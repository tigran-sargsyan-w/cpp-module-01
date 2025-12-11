# C++ Module 01 – Memory, References & Complaining Clients 🧠🧟‍♂️

✅ **Status**: Completed – all exercises 

🏫 **School**: 42 – C++ Modules (Module 01) 

🏅 Score: 100/100

> *Memory allocation, references, pointers to members and `switch` statements.*

---

## 📚 Table of Contents

* [Description](#-description)
* [Goals of the Module](#-goals-of-the-module)
* [Exercises Overview](#-exercises-overview)

  * [ex00 – BraiiiiiiinnnzzzZ](#ex00--braiiiiiiinnnzzzz)
  * [ex01 – Moar brainz!](#ex01--moar-brainz)
  * [ex02 – HI THIS IS BRAIN](#ex02--hi-this-is-brain)
  * [ex03 – Unnecessary violence](#ex03--unnecessary-violence)
  * [ex04 – Sed is for losers](#ex04--sed-is-for-losers)
  * [ex05 – Harl 2.0](#ex05--harl-20)
  * [ex06 – Harl filter](#ex06--harl-filter-optional)
* [Requirements](#-requirements)
* [Build & Run](#-build--run)
* [Repository Layout](#-repository-layout)
* [Testing Tips](#-testing-tips)
* [42 Notes](#-42-notes)

---

## 📝 Description

This repository contains my solutions to **42’s C++ Module 01 (C++98)**.

Module 01 continues the C++ journey by focusing on:

* **Dynamic memory** and when to use heap vs stack
* **References vs pointers** (and how they differ)
* **Pointers to member functions**
* Using the **`switch` statement** in C++
* Structuring slightly larger examples while keeping code readable

All exercises are written in **C++98** and compiled with strict flags (`-Wall -Wextra -Werror -std=c++98`).

---

## 🎯 Goals of the Module

Concepts covered (depending on the exercise):

* Manual **memory allocation** (`new` / `delete`, arrays of objects)
* **Object lifetime** and destructors (debug messages, leak-free code)
* **References** vs **pointers** and basic address manipulation
* **Pointers to member functions** (dynamic behavior without giant `if`/`else` forests)
* **`switch` / `case`** for simple log-level filtering
* Splitting code across multiple **`.hpp` / `.cpp`** files

The idea is to get comfortable with how C++ manages memory and indirection, while still staying in relatively small, focused exercises.

---

## 📦 Exercises Overview

### ex00 – BraiiiiiiinnnzzzZ

> First zombie steps: stack vs heap allocation.

**Goal:**
Implement a `Zombie` class that:

* Has a private `std::string name`
* Has a member function `void announce(void);` that prints:

  ```text
  <name>: BraiiiiiiinnnzzzZ...
  ```
* Prints a debug message in its **destructor** when a zombie is destroyed

You also implement two helper functions:

* `Zombie* newZombie(std::string name);`

  * Allocates a `Zombie` on the **heap**, names it and returns the pointer
* `void randomChump(std::string name);`

  * Creates a temporary `Zombie`, makes it `announce()`, then lets it be destroyed

**Concepts practiced:**

* Stack vs heap allocation and when each makes sense
* Constructors / destructors for debug output
* Ownership / lifetime of dynamically allocated objects

---

### ex01 – Moar brainz!

> One zombie is nice. A whole horde is better.

**Goal:**
Implement:

```cpp
Zombie* zombieHorde(int N, std::string name);
```

* Allocates **`N` zombies in one allocation** (array of objects)
* Initializes all of them with the same `name`
* Returns a pointer to the **first** zombie in the horde
* You must `delete[]` the horde when you’re done with it and ensure no leaks

**Concepts practiced:**

* Using `new[]` / `delete[]` for arrays of objects
* Looping through an array of objects and calling `announce()`
* Making sure destructors run for each element in the array

---

### ex02 – HI THIS IS BRAIN

> Demystifying references through addresses and values.

**Goal:**
Write a program that:

* Has a `std::string` initialized to `"HI THIS IS BRAIN"`
* Declares:

  * `stringPTR` – a **pointer** to that string
  * `stringREF` – a **reference** to that string
* Prints:

  * The **memory address** of:

    * the original string
    * the pointer’s target
    * the reference’s target
  * Then the **values** via:

    * the variable
    * the pointer
    * the reference

**Concepts practiced:**

* Basic pointer and reference syntax
* Differences between pointers and references
* A reference is syntactic sugar with safety rules. It's like a "const pointer," which:
  * Automatically dereferences (you don't need to write *).
  * Prohibits NULL (the compiler will slap you if you try).
  * Prohibits address changes (binding forever).
* [Look how similar they are(pointers and references)](https://godbolt.org/z/8787dd8Ms) 
* Understanding that a reference is essentially an alias to an existing object
* Seeing how addresses line up in memory

---

### ex03 – Unnecessary violence

> Two humans, one weapon type: pointer vs reference design.

**Goal:**

Implement a `Weapon` class:

* Private attribute: `std::string type;`
* `const std::string& getType() const;`
* `void setType(const std::string& newType);`

Then implement two classes: `HumanA` and `HumanB`:

* Both have a **name** and some kind of **Weapon** association
* Both implement:

  ```text
  <name> attacks with their <weapon type>
  ```
* Differences:

  * `HumanA` is **always armed** – the `Weapon` is passed in the constructor (likely as a reference)
  * `HumanB` may **start unarmed** and receive a weapon later via `setWeapon()` (often stored as a pointer)

**Concepts practiced:**

* Choosing between **reference** and **pointer** members
* Understanding when an object must always exist vs may be optional
* Keeping weapon type in sync across multiple owners via reference/pointer

---

### ex04 – Sed is for losers

> Tiny `sed`-like replacer using only C++ strings.

**Goal:**
Create a program:

```bash
./sed_is_for_losers <filename> <s1> <s2>
```

* Opens `<filename>`
* Writes a new file `<filename>.replace`
* Replaces **every occurrence** of `s1` with `s2` in the content
* Handles invalid input and I/O errors

**Important rules:**

* You **must not** use `std::string::replace` (depending on your chosen implementation style / subject constraints)
* Use C++ streams (`std::ifstream`, `std::ofstream`) instead of C-style I/O

**Concepts practiced:**

* File input/output with C++ streams
* Manual substring search + replace using string operations
* Edge cases: empty `s1`, `s2`, large files, no matches, etc.

---

### ex05 – Harl 2.0

> Turning a noisy customer into a table of function pointers.

**Goal:**
Implement a `Harl` class with private member functions:

* `void debug(void);`
* `void info(void);`
* `void warning(void);`
* `void error(void);`

And a public function:

```cpp
void complain(std::string level);
```

This should:

* Call the corresponding private method based on `level` (`"DEBUG"`, `"INFO"`, `"WARNING"`, `"ERROR"`)
* **Use pointers to member functions** – no giant `if`/`else if` chains

The subject typically provides example messages for each log level.

**Concepts practiced:**

* Mapping strings → member function pointers
* Cleaner dispatch vs long condition chains
* Encapsulating logging behavior inside a class

---

### ex06 – Harl filter (optional)

> Same Harl, but now with log-level filtering and `switch`.

**Goal:**
Create a program:

```bash
./harlFilter <level>
```

* `<level>` is one of: `"DEBUG"`, `"INFO"`, `"WARNING"`, `"ERROR"`

* The program prints **all messages from that level and above**, in order. For example:

  * Input: `"WARNING"` → prints `WARNING` + `ERROR` messages
  * Input: invalid string → prints a default line like:

    ```text
    [ Probably complaining about insignificant problems ]
    ```

* Executable name is usually **`harlFilter`**

* You **must** use the `switch` statement for this exercise

**Concepts practiced:**

* Mapping strings to integer levels and using `switch`
* Filtering logs by severity level
* Reusing the `Harl` class and controlling which levels are displayed

---

## 🛠 Requirements

General requirements for the C++ modules:

* **Compiler**: `c++`
* **Flags**:

  * `-Wall -Wextra -Werror`
  * `-std=c++98`
* **OS**: any Unix-like system (Linux / macOS)
* **No external libraries** (no C++11, no Boost, etc.)
* **No `printf`, `malloc`, `free`** & friends – use C++ standard library instead
* Do **not** use `using namespace std;` (or any other namespace with `using namespace`)

---

## ▶️ Build & Run

Clone the repository and build each exercise separately:

```bash
git clone <this-repo-url>
cd cpp-module-01
```

### ex00 – BraiiiiiiinnnzzzZ

```bash
cd ex00
make
./zombies   # or whatever executable name you chose
```

### ex01 – Moar brainz!

```bash
cd ex01
make
./horde
```

### ex02 – HI THIS IS BRAIN

```bash
cd ex02
make
./brain
```

### ex03 – Unnecessary violence

```bash
cd ex03
make
./violence
```

### ex04 – Sed is for losers

```bash
cd ex04
make
./sed_is_for_losers input.txt s1 s2
```

### ex05 – Harl 2.0

```bash
cd ex05
make
./harl
```

### ex06 – Harl filter

```bash
cd ex06
make
./harlFilter "WARNING"
```

> Exact executable names may differ depending on my implementation / subject instructions.

---

## 📂 Repository Layout

```text
cpp-module-01/
├── ex00/
│   ├── Makefile
│   ├── Zombie.hpp / Zombie.cpp
│   ├── newZombie.cpp
│   ├── randomChump.cpp
│   └── main.cpp
│
├── ex01/
│   ├── Makefile
│   ├── Zombie.hpp / Zombie.cpp
│   ├── zombieHorde.cpp
│   └── main.cpp
│
├── ex02/
│   ├── Makefile
│   └── main.cpp
│
├── ex03/
│   ├── Makefile
│   ├── Weapon.hpp / Weapon.cpp
│   ├── HumanA.hpp / HumanA.cpp
│   ├── HumanB.hpp / HumanB.cpp
│   └── main.cpp
│
├── ex04/
│   ├── Makefile
│   ├── main.cpp
│   ├── *.hpp / *.cpp    # helper classes if any
│
├── ex05/
│   ├── Makefile
│   ├── Harl.hpp / Harl.cpp
│   └── main.cpp
│
└── ex06/
    ├── Makefile
    ├── Harl.hpp / Harl.cpp   # can reuse / adapt from ex05
    └── main.cpp
```

---

## 🔍 Testing Tips

Some ideas for manual testing:

* **ex00 / ex01 – Zombies**

  * Verify **destructors** are called when expected (heap vs stack, horde deletion)
  * Run with Valgrind / a leak checker to make sure there are **no memory leaks**

* **ex02 – HI THIS IS BRAIN**

  * Check that all three printed addresses are consistent:

    * string variable address
    * `stringPTR` target
    * `stringREF` target

* **ex03 – Unnecessary violence**

  * Change the weapon type after constructing humans and ensure both see the updated value
  * Test `HumanB` without a weapon first to ensure it doesn’t crash and behaves predictably

* **ex04 – Sed is for losers**

  * Empty file, no occurrence of `s1`
  * `s1` at the **start/end** of file and multiple times in a row
  * Edge case: `s1` and `s2` having different lengths, or `s1` being an empty string

* **ex05 – Harl 2.0**

  * Pass each log level and verify only the correct output appears
  * Check behavior with invalid levels (should probably do nothing or handle it gracefully)

* **ex06 – Harl filter**

  * Test each valid level (`DEBUG`, `INFO`, `WARNING`, `ERROR`) and verify that:

    * It prints from that level **upwards**
  * Test with completely invalid strings:

    * Should print something like `[ Probably complaining about insignificant problems ]`

---

## 🧾 42 Notes

* C++ modules have **no enforced Norminette**, but the subject still expects **clean and readable code**.
* No STL containers or algorithms before the later modules – stick to basic types and `std::string` for now.
* Headers must be self-sufficient (include their own dependencies) and properly guarded against multiple inclusion.

---

If you’re a 42 student working on the same module, feel free to browse the code and learn from it — but **write your own implementation**. That’s how you’ll actually understand C++ and survive the exams. 🚀
