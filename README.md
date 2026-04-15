# 🧮 Scientific Calculator in C

A powerful **console-based scientific calculator** built using the C programming language. This project evaluates mathematical expressions with support for basic arithmetic operations, operator precedence, parentheses, and scientific functions.

---

## 🚀 Features

* ✅ Basic Arithmetic Operations
  `+`, `-`, `*`, `/`

* ✅ Operator Precedence Handling
  (Follows standard mathematical rules)

* ✅ Parentheses Support
  Handles nested expressions

* ✅ Scientific Functions

  * `sin(x)` (degree)
  * `cos(x)`
  * `tan(x)`
  * `log(x)` (base 10)
  * `sqrt(x)`

* ✅ Decimal Number Support

* ✅ Recursive Expression Evaluation

* ✅ Error Handling

  * Division by zero
  * Unknown functions

* ✅ Colorful Console UI (Windows)

---

## 🧠 How It Works

This calculator uses a **stack-based expression evaluation algorithm**:

* 📌 **Number Stack** → Stores numeric values
* 📌 **Operator Stack** → Stores operators

It parses the input string and evaluates expressions based on:

* Operator precedence
* Parentheses
* Function calls

---

## 📥 Input Example

```
sin(30) + 5 * 2
```

## 📤 Output Example

```
Result = 10.50
```

---

## 🧪 Sample Test Cases

```
2 + 3 * 4
(2 + 3) * 4
sqrt(25) + log(100)
sin(30 + sqrt(16))
```

---

## ⚠️ Error Handling

The program handles:

* ❌ Division by zero
* ❌ Unknown function input
* ❌ Invalid expressions (partial)

---

## 🛠️ Technologies Used

* C Programming Language
* Standard Libraries:

  * `stdio.h`
  * `stdlib.h`
  * `ctype.h`
  * `math.h`
  * `string.h`
  * `windows.h` (for console UI)

---

## ▶️ How to Run

### 🔹 Compile

```
gcc calculator.c -o calculator -lm
```

### 🔹 Run

```
./calculator
```

---

## 💡 Future Improvements

* 🔹 Add power operator (`^`)
* 🔹 Add modulus (`%`)
* 🔹 Better syntax error handling
* 🔹 Support for negative numbers
* 🔹 GUI version (desktop/web)

