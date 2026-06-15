#!/usr/bin/env bash

set -u

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BIN="$ROOT/cub3D_validate"
TMP="$ROOT/tests/.tmp"
PASS=0
FAIL=0

mkdir -p "$TMP"

run_case() {
	name="$1"
	expected="$2"
	file="$3"
	(cd "$ROOT" && "$BIN" "$file") >/dev/null 2>&1
	status=$?
	if { [ "$expected" = "ok" ] && [ "$status" -eq 0 ]; } ||
		{ [ "$expected" = "error" ] && [ "$status" -ne 0 ]; }; then
		printf "[OK] %s\n" "$name"
		PASS=$((PASS + 1))
	else
		printf "[FAIL] %s (status %d)\n" "$name" "$status"
		FAIL=$((FAIL + 1))
	fi
}

cp "$ROOT/tests/maps/valid.cub" "$TMP/no_newline.cub"
truncate -s -1 "$TMP/no_newline.cub"

run_case "valid map" ok "$ROOT/tests/maps/valid.cub"
run_case "last line without newline" ok "$TMP/no_newline.cub"
run_case "spaced colors and configs" ok "$ROOT/tests/maps/spaces.cub"
run_case "blank line inside map" error "$ROOT/tests/maps/blank_map.cub"
run_case "open map" error "$ROOT/tests/maps/open_map.cub"
run_case "color out of range" error "$ROOT/tests/maps/invalid_color.cub"
run_case "duplicate player" error "$ROOT/tests/maps/duplicate_player.cub"
run_case "missing texture" error "$ROOT/tests/maps/missing_texture.cub"

printf "\n%d passed, %d failed\n" "$PASS" "$FAIL"
rm -rf "$TMP"
[ "$FAIL" -eq 0 ]
