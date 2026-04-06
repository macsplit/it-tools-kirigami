#!/usr/bin/env bash
set -euo pipefail

KEY_UID="${1:-PasteTools Flatpak Repo <flatpak@pastetools.app>}"

existing_key=$(
  { gpg --list-secret-keys --with-colons --keyid-format LONG "$KEY_UID" 2>/dev/null || true; } |
  awk -F: '$1 == "sec" { print $5; exit }'
)

if [[ -n "$existing_key" ]]; then
  printf '%s\n' "$existing_key"
  exit 0
fi

gpg --batch --passphrase '' --quick-gen-key "$KEY_UID" rsa4096 sign 0

gpg --list-secret-keys --with-colons --keyid-format LONG "$KEY_UID" |
  awk -F: '$1 == "sec" { print $5; exit }'
