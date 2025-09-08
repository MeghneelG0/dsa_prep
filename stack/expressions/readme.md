### 🔹 1. Algorithm (Infix → Prefix)

### A common way:

- Reverse the infix expression.

- Swap ( with ) and vice versa.

- Convert the reversed expression to postfix (using the standard infix → postfix algorithm with a stack).

- Reverse the postfix result → that’s the prefix.

### 🔹 2. Worked Example

#### Expression:

- (A + B) * (C - D)

#### Step 1: Reverse (and swap brackets)

- Original: (A + B) * (C - D)
Reversed: (D - C) * (B + A)

#### Step 2: Convert to postfix

- Now convert (D - C) * (B + A) to postfix using operator stack.

#### Rules:

- If operand → output directly.

- If ( → push to stack.

- If ) → pop until (.

- If operator → pop higher/equal precedence operators first, then push.

### Iteration table:

### Convert Reversed Expression to Postfix

| Symbol | Action                 | Output    | Stack |
|--------|------------------------|-----------|-------|
| (      | Push                   |           | (     |
| D      | Operand → output       | D         | (     |
| -      | Push                   | D         | (-    |
| C      | Operand → output       | D C       | (-    |
| )      | Pop until (            | D C -     |       |
| *      | Push                   | D C -     | *     |
| (      | Push                   | D C -     | *(    |
| B      | Operand → output       | D C - B   | *(    |
| +      | Push                   | D C - B   | *(+   |
| A      | Operand → output       | D C - B A | *(+   |
| )      | Pop until (            | D C - B A + | *   |

👉 At the end, pop the stack:  

- End: Pop stack → postfix =

- D C - B A + *

### Step 3: Reverse postfix

- Reverse:

# * + A B - C D


## ✅ That’s the Prefix expression.