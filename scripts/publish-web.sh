#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DEST="${1:-nuc:/var/www/tools/}"
WEB_DIR="${ROOT_DIR}/web"

if [[ "${PASTETOOLS_DEPLOY_WEB:-}" != "1" ]]; then
  printf 'publish-web.sh is an internal step. Use ./scripts/deploy-web.sh instead.\n' >&2
  exit 1
fi

required_paths=(
  "${WEB_DIR}/index.html"
  "${WEB_DIR}/styles.css"
  "${WEB_DIR}/app.pastetools.Tools.flatpak"
  "${WEB_DIR}/app.pastetools.Tools.flatpakref"
  "${WEB_DIR}/pastetools.flatpakrepo"
  "${WEB_DIR}/repo/summary"
)

for path in "${required_paths[@]}"; do
  if [[ ! -e "${path}" ]]; then
    printf 'publish-web.sh: missing required artifact: %s\n' "${path}" >&2
    exit 1
  fi
done

if command -v rsync >/dev/null 2>&1; then
  if ssh "${DEST%%:*}" "command -v rsync >/dev/null 2>&1"; then
      rsync -rlD --delete "${WEB_DIR}/" "${DEST}"
    exit 0
  fi
fi

HOST="${DEST%%:*}"
REMOTE_PATH="${DEST#*:}"

find "${WEB_DIR}" -mindepth 1 -maxdepth 1 -printf '%P\0' |
  tar -C "${WEB_DIR}" --null -T - -cf - |
  ssh "${HOST}" "mkdir -p '${REMOTE_PATH}' && tar -C '${REMOTE_PATH}' -xf -"
