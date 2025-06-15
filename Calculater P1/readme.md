## Hacker Calculator — Basic C Project

This simple command-line calculator is written in C. It performs basic arithmetic operations based on user input.

### Features

* Addition (`add`)
* Subtraction (`sub`)
* Multiplication (`multi`)
* Division (`div`), with zero-division error handling

### How to Use

Run the program from the terminal with three arguments:

```
./calculator [operation] [num1] [num2]
```

* `operation`: One of `add`, `sub`, `multi`, `div`
* `num1` and `num2`: Integer numbers to calculate

### Example Usage

```bash
./calculator add 5 3
```

Output:

```
----- Hacker Calculator -----
Adding: 5 + 3 = 8
```

### Code Explanation

* The program accepts command-line arguments and checks if exactly 3 arguments are given (operation and two numbers).
* It converts the second and third arguments from strings to integers using `atoi()`.
* Using `strcmp()`, it compares the operation argument to decide which calculation to perform.
* For division, the program checks if the divisor is zero and handles the error gracefully.
* It prints the result in a formatted manner.

---
