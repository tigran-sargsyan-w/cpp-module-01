#!/bin/bash
# Simple test runner for C++ Module 01 - ex04 (Replacer)

BIN="./ex04/replacer"
TEST_DIR="ex04/testes"

OK=0
FAIL=0

run_diff() {
    local name="$1"
    local expected="$2"
    local output="$3"

    if diff -u "$expected" "$output" > /dev/null 2>&1; then
        echo "[OK]   $name"
        OK=$((OK + 1))
    else
        echo "[FAIL] $name"
        echo "       diff:"
        diff -u "$expected" "$output" || true
        FAIL=$((FAIL + 1))
    fi
}

if [ ! -x "$BIN" ]; then
    echo "Binary '$BIN' not found or not executable."
    echo "Run 'make' first (from project root) and ensure ./ex04/replacer exists."
    exit 1
fi

mkdir -p "$TEST_DIR"

########################################
# Test 01
########################################
input="$TEST_DIR/test01_basic.txt"
output="$input.replace"
expected="$TEST_DIR/test01_basic.expected"

rm -f "$output" "$expected"

"$BIN" "$input" "world" "planet"

cat > "$expected" << 'EOF'
Hello, planet! This is a simple planet test.
planet planet WORLD
EOF

run_diff "Test 01 - basic replacement" "$expected" "$output"

########################################
# Test 02
########################################
input="$TEST_DIR/test02_edges.txt"
output="$input.replace"
expected="$TEST_DIR/test02_edges.expected"

rm -f "$output" "$expected"

"$BIN" "$input" "abc" "XYZ"

cat > "$expected" << 'EOF'
XYZ something in the middle XYZ
XYZ
EOF

run_diff "Test 02 - edges (begin/end)" "$expected" "$output"

########################################
# Test 03
########################################
input="$TEST_DIR/test03_multiline.txt"
output="$input.replace"
expected="$TEST_DIR/test03_multiline.expected"

rm -f "$output" "$expected"

"$BIN" "$input" "cat" "mouse"

cat > "$expected" << 'EOF'
line1: mouse dog mouse
line2: mouse
line3: nothing here
line4: mousemousemouse
EOF

run_diff "Test 03 - multiline" "$expected" "$output"

########################################
# Test 04A - s1 longer than s2
########################################
# IMPORTANT: предполагаем, что test04_length.txt сейчас:
# aaaaa
# xyzxyzxyz
input="$TEST_DIR/test04_length.txt"
output="$input.replace"
expected="$TEST_DIR/test04_length_A.expected"

rm -f "$output" "$expected"

"$BIN" "$input" "aaa" "Z"

cat > "$expected" << 'EOF'
Zaa
xyzxyzxyz
EOF

run_diff "Test 04A - s1 longer than s2" "$expected" "$output"

########################################
# Test 04B - s1 shorter than s2
########################################
# Тот же исходный файл (aaaaa / xyzxyzxyz)
input="$TEST_DIR/test04_length.txt"
output="$input.replace"
expected="$TEST_DIR/test04_length_B.expected"

rm -f "$output" "$expected"

"$BIN" "$input" "x" "superX"

cat > "$expected" << 'EOF'
aaaaa
superXyzsuperXyzsuperXyz
EOF

run_diff "Test 04B - s1 shorter than s2" "$expected" "$output"

########################################
# Test 05 - no occurrences
########################################
input="$TEST_DIR/test05_none.txt"
output="$input.replace"
expected="$TEST_DIR/test05_none.expected"

rm -f "$output" "$expected"

"$BIN" "$input" "hello" "hi"

cat > "$expected" << 'EOF'
There is no keyword here.
Just some random text.
EOF

run_diff "Test 05 - no occurrences" "$expected" "$output"

########################################
# Test 06 - s1 == s2
########################################
input="$TEST_DIR/test06_same.txt"
output="$input.replace"
expected="$TEST_DIR/test06_same.expected"

rm -f "$output" "$expected"

"$BIN" "$input" "repeat" "repeat"

cat > "$expected" << 'EOF'
repeat repeat repeat
EOF

run_diff "Test 06 - s1 == s2" "$expected" "$output"

########################################
# Test 07 - UTF-8 / Cyrillic
########################################
input="$TEST_DIR/test07_utf8.txt"
output="$input.replace"
expected="$TEST_DIR/test07_utf8.expected"

rm -f "$output" "$expected"

"$BIN" "$input" "мир" "вселенная"

cat > "$expected" << 'EOF'
Привет, вселенная! Это тест. вселенная вселенная МИР.
EOF

run_diff "Test 07 - UTF-8 / Cyrillic" "$expected" "$output"

########################################
# Test 08 - empty file
########################################
input="$TEST_DIR/test08_empty.txt"
output="$input.replace"
expected="$TEST_DIR/test08_empty.expected"

rm -f "$output" "$expected"

"$BIN" "$input" "abc" "xyz"

# expected empty file
: > "$expected"

if [ ! -f "$output" ]; then
    echo "[FAIL] Test 08 - empty file (no .replace created)"
    FAIL=$((FAIL + 1))
else
    run_diff "Test 08 - empty file" "$expected" "$output"
fi

########################################
# Test 09 - many single-char matches
########################################
input="$TEST_DIR/test09_char.txt"
output="$input.replace"
expected="$TEST_DIR/test09_char.expected"

rm -f "$output" "$expected"

"$BIN" "$input" "a" "_"

cat > "$expected" << 'EOF'
__________
bbbb____bbb
EOF

run_diff "Test 09 - single-char spam" "$expected" "$output"

########################################
# Test 10 - overlapping pattern
########################################
input="$TEST_DIR/test10_overlap.txt"
output="$input.replace"
expected="$TEST_DIR/test10_overlap.expected"

rm -f "$output" "$expected"

"$BIN" "$input" "aa" "X"

cat > "$expected" << 'EOF'
XX
EOF

run_diff "Test 10 - overlapping aa in aaaa" "$expected" "$output"

########################################
# Summary
########################################

echo
echo "Summary: $OK passed, $FAIL failed."

# Cleanup: *.expected и *.replace
rm -f "$TEST_DIR"/*.expected "$TEST_DIR"/*.txt.replace

if [ "$FAIL" -ne 0 ]; then
    exit 1
else
    exit 0
fi
