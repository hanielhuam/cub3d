#!/usr/bin/env bash
set -u

BIN="${1:-./test/bin/validation_test}"
TMP_DIR="test/tmp_validation"
PASS=0
FAIL=0

mkdir -p "$TMP_DIR"

write_case()
{
	local name="$1"
	shift
	printf "%s" "$*" > "$TMP_DIR/$name.cub"
}

run_case()
{
	local name="$1"
	local expected="$2"
	local output
	local status

	output="$("$BIN" "$TMP_DIR/$name.cub" 2>&1)"
	status=$?
	if { [ "$expected" = "ok" ] && [ "$status" -eq 0 ]; } \
		|| { [ "$expected" = "ko" ] && [ "$status" -ne 0 ]; }; then
		printf "[OK]   %-28s expected=%s status=%d\n" "$name" "$expected" "$status"
		PASS=$((PASS + 1))
	else
		printf "[FAIL] %-28s expected=%s status=%d\n" "$name" "$expected" "$status"
		if [ -n "$output" ]; then
			printf "%s\n" "$output" | sed 's/^/       /'
		fi
		FAIL=$((FAIL + 1))
	fi
}

HEADER='NO ./resources/north-texture
SO ./resources/south-texture
WE ./resources/west-texture
EA ./resources/east-texture
F 220,100,0
C 225,30,0
'

write_case valid_basic "$HEADER"'
11111
10001
10E01
10001
11111
'

write_case map_open_wall "$HEADER"'
11111
10001
10E01
10000
11111
'

write_case map_no_player "$HEADER"'
11111
10001
10001
10001
11111
'

write_case map_two_players "$HEADER"'
11111
10N01
10E01
10001
11111
'

write_case map_empty_line_inside "$HEADER"'
11111
10001

10E01
10001
11111
'

run_case valid_basic ok
run_case map_open_wall ko
run_case map_no_player ko
run_case map_two_players ko
run_case map_empty_line_inside ko

printf "\nSUMMARY: PASS=%d FAIL=%d\n" "$PASS" "$FAIL"
exit "$FAIL"

write_case color_with_spaces 'NO ./resources/north-texture
SO ./resources/south-texture
WE ./resources/west-texture
EA ./resources/east-texture
F 220, 100, 0
C 225, 30, 0

11111
10001
10E01
10001
11111