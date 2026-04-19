#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DEST="${1:-nuc:/var/www/tools/}"

if command -v rsync >/dev/null 2>&1; then
  if ssh "${DEST%%:*}" "command -v rsync >/dev/null 2>&1"; then
      rsync -rlD --delete "${ROOT_DIR}/web/" "${DEST}"
    exit 0
  fi
fi

HOST="${DEST%%:*}"
REMOTE_PATH="${DEST#*:}"

find "${ROOT_DIR}/web" -mindepth 1 -maxdepth 1 -printf '%P\0' |
  tar -C "${ROOT_DIR}/web" --null -T - -cf - |
  ssh "${HOST}" "mkdir -p '${REMOTE_PATH}' && tar -C '${REMOTE_PATH}' -xf -"
