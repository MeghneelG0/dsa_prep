# 🧠 DSA Practice Repository

A structured collection of solutions to Data Structures and Algorithms problems, categorized by topic and problem-solving patterns.

---

## 📁 Overview

This repository contains my implementations of various DSA problems. The focus is on building **pattern-based intuition** and developing clean, reusable solutions.

All code is organized by topic or pattern to make navigation easier.

---

## 📂 Directory Structure

```
DSA_prep/
├── input.txt         # Input test cases for runner
├── output.txt        # Output file generated after running
├── runner.py         # Utility script to run specific solutions
├── pattern/
│   ├── pattern1.py   # Example solution file
│   ├── pattern2.py   # ...
└── ...
```

---

## ⚙️ Setup

1. Clone this repository:

```bash
git clone https://github.com/MeghneelG0/dsa_prep.git
cd dsa_prep
```

2. Make sure Python 3.6 or above is installed:

```bash
python --version
```

---

## 🚀 Running Solutions

You can run any solution in two ways:

### ✅ Using the Runner Script

```bash
python runner.py pattern.pattern1
```

- This runs the `pattern1.py` file inside the `pattern` directory.
- Input is read from `input.txt`, and the output is saved to `output.txt`.

---

### 💻 Using VS Code Tasks (Recommended)

This repo is configured with custom VS Code tasks to speed up development.

#### Steps:
1. Open any file (e.g., `pattern1.py`)
2. Press `Ctrl + Shift + B` to run it
3. OR run the “Run Specific Module” task and enter the module name when prompted

#### Add the following to `.vscode/tasks.json`:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Run any demoX.py with input/output.txt",
      "type": "shell",
      "command": "python",
      "args": [
        "runner.py",
        "${input:filename}"
      ],
      "options": {
        "cwd": "${workspaceFolder}"
      },
      "presentation": {
        "reveal": "always",
        "panel": "shared"
      }
    }
  ],
  "inputs": [
    {
      "id": "filename",
      "type": "promptString",
      "description": "Enter Python filename (e.g. pattern.pattern1)"
    }
  ]
}
```

---

## 🧪 Example

#### `input.txt`
```
5
```

#### `pattern1.py`
```python
def solve():
    n = int(input())
    for i in range(1, n+1):
        print("*" * i)
```

Run:
```bash
python runner.py pattern.pattern1
```

#### `output.txt`
```
*
**
***
****
*****
```
---

Happy coding! 🚀
