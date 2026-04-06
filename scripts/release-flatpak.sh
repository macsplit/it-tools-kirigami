#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
APP_ID="app.pastetools.Tools"
BRANCH="${FLATPAK_BRANCH:-stable}"
SITE_URL="${FLATPAK_SITE_URL:-https://pastetools.app}"
REPO_URL="${FLATPAK_REPO_URL:-${SITE_URL}/repo/}"
BUILD_ROOT="${FLATPAK_BUILD_ROOT:-/tmp/${APP_ID}-flatpak-build}"
TMP_DIR="${BUILD_ROOT}/tmp"
BUILD_DIR="${TMP_DIR}/build-dir"
TMP_REPO_DIR="${TMP_DIR}/repo"
STATE_DIR="${BUILD_ROOT}/state-dir"
REPO_DIR="${ROOT_DIR}/web/repo"
BUNDLE_PATH="${ROOT_DIR}/web/${APP_ID}.flatpak"
REF_PATH="${ROOT_DIR}/web/${APP_ID}.flatpakref"
REPO_FILE_PATH="${ROOT_DIR}/web/pastetools.flatpakrepo"
KEY_UID="${FLATPAK_GPG_UID:-PasteTools Flatpak Repo <flatpak@pastetools.app>}"
KEY_ID="${FLATPAK_GPG_KEY:-}"

mkdir -p "${BUILD_ROOT}" "${TMP_DIR}" "${ROOT_DIR}/web"
rm -rf "${BUILD_DIR}" "${TMP_REPO_DIR}" "${STATE_DIR}" "${REPO_DIR}" "${BUNDLE_PATH}" "${REF_PATH}" "${REPO_FILE_PATH}"

ostree init --repo="${TMP_REPO_DIR}" --mode=archive-z2
ostree --repo="${TMP_REPO_DIR}" config set core.min-free-space-percent 1

if [[ -z "${KEY_ID}" ]]; then
  KEY_ID="$("${ROOT_DIR}/scripts/create-flatpak-signing-key.sh" "${KEY_UID}")"
fi

flatpak-builder \
  --default-branch="${BRANCH}" \
  --gpg-sign="${KEY_ID}" \
  --state-dir="${STATE_DIR}" \
  --repo="${TMP_REPO_DIR}" \
  --force-clean \
  "${BUILD_DIR}" \
  "${ROOT_DIR}/${APP_ID}.json"

flatpak build-update-repo \
  --generate-static-deltas \
  --gpg-sign="${KEY_ID}" \
  "${TMP_REPO_DIR}"

flatpak build-bundle \
  "${TMP_REPO_DIR}" \
  "${BUNDLE_PATH}" \
  "${APP_ID}" \
  "${BRANCH}" \
  --gpg-sign="${KEY_ID}"

cp -a "${TMP_REPO_DIR}" "${REPO_DIR}"

GPG_KEY_BASE64="$(gpg --export "${KEY_ID}" | base64 -w0)"

cat > "${REPO_FILE_PATH}" <<EOF
[Flatpak Repo]
Title=PasteTools
Url=${REPO_URL}
Homepage=${SITE_URL}/
Comment=Flatpak repository for Tools
Description=Flatpak repository for Tools
GPGKey=${GPG_KEY_BASE64}
EOF

cat > "${REF_PATH}" <<EOF
[Flatpak Ref]
Name=${APP_ID}
Branch=${BRANCH}
Title=Tools
Url=${REPO_URL}
RuntimeRepo=https://dl.flathub.org/repo/flathub.flatpakrepo
IsRuntime=false
GPGKey=${GPG_KEY_BASE64}
EOF

printf 'Built Flatpak repo: %s\n' "${REPO_DIR}"
printf 'Built Flatpak bundle: %s\n' "${BUNDLE_PATH}"
printf 'Wrote repo file: %s\n' "${REPO_FILE_PATH}"
printf 'Wrote ref file: %s\n' "${REF_PATH}"
printf 'Signing key: %s\n' "${KEY_ID}"
