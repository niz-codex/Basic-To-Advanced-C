# 🔐 Password Strength Checker (C)

This is a simple yet effective C program that checks the strength of a given password based on five common security criteria.

---

## 🛠️ Features

- Checks for:
  - ✅ Minimum length (8+ characters)
  - ✅ At least one **uppercase** letter
  - ✅ At least one **lowercase** letter
  - ✅ At least one **digit**
  - ✅ At least one **special character** (like `!@#$%^&*`)
- Outputs password **strength** as:
  - 🟢 Strong
  - 🟡 Medium
  - 🔴 Weak
- Displays **missing criteria** to improve your password

---

## 🧠 How It Works

The program checks each character of the password using functions from `<ctype.h>`:
- `isupper()` – detects uppercase letters
- `islower()` – detects lowercase letters
- `isdigit()` – detects numbers
- `ispunct()` – detects symbols like `!@#$%`

Then it scores your password out of 5 based on:
1. Length ≥ 8
2. At least one uppercase
3. At least one lowercase
4. At least one digit
5. At least one special character

---

## ⚙️ Compilation

Use GCC or any C compiler:

```bash
gcc password_checker.c -o checker
