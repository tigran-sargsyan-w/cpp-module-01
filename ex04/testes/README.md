# C++ Module 01 — ex04: Replacer Test Guide

This document describes a set of manual tests for the program:

```bash
./ex04/replacer <filename> <s1> <s2>
```

Assumptions:

* Binary is located at `./ex04/replacer`
* Test files are located under: `ex04/testes/`
* For each `<filename>` the program produces `<filename>.replace`
  Example:
  Input:  `ex04/testes/test01_basic.txt`
  Output: `ex04/testes/test01_basic.txt.replace`

---

## 0. Build

From the root of the repository:

```bash
make -C ex04
```

Check that the binary exists:

```bash
ls ex04/replacer
```

---

## 1. Test 01 — Basic replacement (multiple occurrences, case-sensitive)

**Source file**
Path: `ex04/testes/test01_basic.txt`

Content:

```text
Hello, world! This is a simple world test.
world world WORLD
```

**Run**

```bash
./ex04/replacer ex04/testes/test01_basic.txt world planet
```

**Expected output**
File: `ex04/testes/test01_basic.txt.replace`

```text
Hello, planet! This is a simple planet test.
planet planet WORLD
```

Notes:

* Lowercase `world` → replaced
* Uppercase `WORLD` → NOT replaced (case-sensitive)

---

## 2. Test 02 — Matches at beginning and end of line

**Source file**
Path: `ex04/testes/test02_edges.txt`

Content:

```text
abc something in the middle abc
abc
```

**Run**

```bash
./ex04/replacer ex04/testes/test02_edges.txt abc XYZ
```

**Expected output**
File: `ex04/testes/test02_edges.txt.replace`

```text
XYZ something in the middle XYZ
XYZ
```

---

## 3. Test 03 — Multiline file, multiple matches per line

**Source file**
Path: `ex04/testes/test03_multiline.txt`

Content:

```text
line1: cat dog cat
line2: cat
line3: nothing here
line4: catcatcat
```

**Run**

```bash
./ex04/replacer ex04/testes/test03_multiline.txt cat mouse
```

**Expected output**
File: `ex04/testes/test03_multiline.txt.replace`

```text
line1: mouse dog mouse
line2: mouse
line3: nothing here
line4: mousemousemouse
```

Notes:

* Checks that consecutive patterns (`catcatcat`) are handled correctly.

---

## 4. Test 04 — Different lengths of `s1` and `s2`

Use one file and run **two separate variants** (recreate file between runs if needed).

**Source file**
Path: `ex04/testes/test04_length.txt`

Content:

```text
aaaaa
xxx
```

### 4A. `s1` longer than `s2`

**Run**

```bash
./ex04/replacer ex04/testes/test04_length.txt aaa Z
```

**Expected output**
File: `ex04/testes/test04_length.txt.replace`

```text
Zaa
xyzxyzxyz
```

Explanation:

* `aaaaa` → first `aaa` becomes `Z`, remains `aa`, which no longer contains `aaa`.

---

### 4B. `s1` shorter than `s2`

**Source file (reset it to original before this run)**

```text
aaaaa
xxx
```

**Run**

```bash
./ex04/replacer ex04/testes/test04_length.txt x superX
```

**Expected output**
File: `ex04/testes/test04_length.txt.replace`

```text
aaaaa
superXyzsuperXyzsuperXyz
```

---

## 5. Test 05 — No occurrences of `s1`

**Source file**
Path: `ex04/testes/test05_none.txt`

Content:

```text
There is no keyword here.
Just some random text.
```

**Run**

```bash
./ex04/replacer ex04/testes/test05_none.txt hello hi
```

**Expected output**
File: `ex04/testes/test05_none.txt.replace`

```text
There is no keyword here.
Just some random text.
```

Notes:

* Output must match the original file **exactly**.

---

## 6. Test 06 — `s1 == s2` (no visible change)

**Source file**
Path: `ex04/testes/test06_same.txt`

Content:

```text
repeat repeat repeat
```

**Run**

```bash
./ex04/replacer ex04/testes/test06_same.txt repeat repeat
```

**Expected output**
File: `ex04/testes/test06_same.txt.replace`

```text
repeat repeat repeat
```

---

## 7. Test 07 — UTF-8 / Cyrillic, case-sensitive

**Source file**
Path: `ex04/testes/test07_utf8.txt`

Content:

```text
Привет, мир! Это тест. мир мир МИР.
```

**Run**

```bash
./ex04/replacer ex04/testes/test07_utf8.txt мир вселенная
```

**Expected output**
File: `ex04/testes/test07_utf8.txt.replace`

```text
Привет, вселенная! Это тест. вселенная вселенная МИР.
```

Notes:

* Replace only lowercase `мир`
* Uppercase `МИР` must stay unchanged

---

## 8. Test 08 — Empty file

**Source file**
Path: `ex04/testes/test08_empty.txt`
Content: *(empty file)*

Create it like this:

```bash
touch ex04/testes/test08_empty.txt
```

**Run**

```bash
./ex04/replacer ex04/testes/test08_empty.txt abc xyz
```

**Expected output**
File: `ex04/testes/test08_empty.txt.replace`
Content: *(empty file)*

---

## 9. Test 09 — Very frequent single-character pattern

**Source file**
Path: `ex04/testes/test09_char.txt`

Content:

```text
aaaaaaaaaa
bbbbaaaabbb
```

**Run**

```bash
./ex04/replacer ex04/testes/test09_char.txt a _
```

**Expected output**
File: `ex04/testes/test09_char.txt.replace`

```text
__________
bbbb____bbb
```

---

## 10. Test 10 — Overlapping pattern (`aa` in `aaaa`)

**Source file** 
Path: `ex04/testes/test10_overlap.txt`
Content:

```text
aaaa
```
**Run**

```bash
./ex04/replacer ex04/testes/test10_overlap.txt aa X
```

**Expected output**
File: `ex04/testes/test10_overlap.txt.replace`
```text
XX
```

---