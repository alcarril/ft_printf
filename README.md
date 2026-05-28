ft_printf
=========

<div align="center">
	<strong><span style="font-size: 1.25em;">My implementation of the printf function from scratch</span></strong>
	<br />
	<br />
	<img src="https://img.shields.io/badge/42-Project-black" alt="42" />
	<img src="https://img.shields.io/badge/C-Language-blue" alt="C" />
	<img src="https://img.shields.io/badge/GNU-Makefile-green" alt="GNU Makefile" />
</div>

## 📌 Overview
This project is my third 42 school assignment to recreate the `printf` function and some of its parsing and expansion (formatting) cases. To build it, I use variadic functions, my own library from the Libft project, and the standard C functions `malloc`, `free`, and `write`.

## Key Features
- Variadic function handling and safe casting for each format case.
- Parsing and formatting strings using `%` as the delimiter.
- Base conversions (decimal/hex) and numeric representation in C.
- Understanding C data types, their sizes, and low-level bit operations.

## Formatted Cases
We replicate the formatting cases used by `printf`:
- `c` for a single character.
- `s` for strings.
- `d` and `i` for signed decimal integers.
- `u` for unsigned integers.
- `p` for memory addresses (pointers).
- `x` for hexadecimal (lowercase).
- `X` for hexadecimal (uppercase).
- `%%` for a literal percent sign.

## 🛠️ Requirements
Install required packages (Ubuntu/Debian):
```bash
sudo apt update
sudo apt install -y make
sudo apt install -y gcc
```

Libft is included in this project (my own library), no extra install needed.

Note: On other Linux or Unix-like systems, install GCC/Clang and GNU Make with your package manager.

## 🧱 Build
```bash
git clone <your-repo-url>
cd printf
make
```
This builds the static library for handling `printf`.

## ▶️ Run
Example `main.c`:
```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, number: %d\n", "World", 42);
	return 0;
}
```

Compile and link with the static library:
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o demo
./demo
```

Example output:
```text
Hello World, number: 42
```

You can also run the included tests in the `test` folder:
```bash
make test
```
