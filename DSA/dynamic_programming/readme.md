two ways of solving a DP problem: memoization(top-down approach)

and 2nd one is (bottom up approach): The bottom-up approach starts by creating an array dp of size n + 1 to store the number of ways to climb n steps. dp[0] contains the number of ways to climb 0 steps, dp[1] contains the number of ways to climb 1 step, and so on. This dp array is analogous to the cache we used in the memoized recursive approach.
We initialize the base cases dp[0] = 1 and dp[1] = 1, and then iterate from 2 to n, calculating dp[i] = dp[i - 1] + dp[i - 2]. The animation below shows the process of filling in the dp array for n = 5, and how it corresponds to going from the bottom of the memoized call tree to the top. When the iteration is complete, we return dp[n] as the final answer.

def stairs(n):
    if n <= 1:
        return 1
    dp = [0] * (n + 1)

    dp[0] = 1
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]

# 🚀 Dynamic Programming Transition Styles  
### Forward DP vs Backward DP (Cheat Sheet)

Dynamic Programming recurrences usually fall into **two major categories** based on how states transition:

---

## ⭐ 1️⃣ Forward DP (State → Future States)

**Definition:**  
From the current index/state, you decide **what to do next**.  
The transitions move **forward** (increasing index).

### ✔ Characteristics
- You make a **choice** at index `i`
- Your choice moves you to **future** states (`i+1`, `i+2`, ...)
- You evaluate all available next options
- Common in *choice-based* problems

### ✔ Transition Pattern
dp[i] → dp[i+1], dp[i+2], ...


### ✔ Used In
- House Robber  
- Knapsack  
- Coin Change (ways / min coins)  
- Climbing Stairs (counting ways)  
- Frog Jump (forward version)  
- Triangle (top-down DP)

### ✔ Intuition
> **“From this position, what can I do NEXT?”**

---

## ⭐ 2️⃣ Backward DP (State ← Previous States)

**Definition:**  
Define `dp[i]` as the cost/ways to **reach index i**,  
then ask:  
**“How could I have arrived at i?”**  
The transitions move **backward** (decreasing index).

### ✔ Characteristics
- `dp[i]` represents a property *at index i* (cost, ways, min steps, etc.)
- You derive it using information from **previous states** (`i-1`, `i-2`, ...)
- Common in *path-minimization* or *accumulation* problems

### ✔ Transition Pattern
dp[i] ← dp[i-1], dp[i-2], ...

### ✔ Used In
- Min Cost Climbing Stairs  
- Decode Ways  
- Edit Distance  
- Fibonacci / Tribonacci  
- Shortest path on 1D number line  
- Prefix-based DP problems  

### ✔ Intuition
> **“What is the best/easiest way to ARRIVE HERE?”**

---

## 🧠 How to Instantly Recognize Which DP to Use

### Use **Forward DP** when:
- You have **choices** at each step  
- You can “pick” or “skip” elements  
- You branch forward into multiple options  

Example questions:
- “Should I take this house?”  
- “Which next coin can I use?”  
- “Where can I jump next?”

---

### Use **Backward DP** when:
- The DP state depends on **how you arrived** at the current index  
- The cost/ways to reach a position depends on previous positions  
- You’re moving toward a target/destination  

Example questions:
- “How many ways to decode up to index i?”  
- “What’s the min cost to reach step i?”  
- “What was the best previous step?”

---

## 📌 Comparison Table

| Feature | Forward DP | Backward DP |
|--------|-------------|-------------|
| Direction | `i → i+1, i+2` | `i ← i-1, i-2` |
| Thinking Style | Next choices | Previous origins |
| Best For | Branching decisions | Cumulative cost/ways |
| Examples | House Robber, Knapsack | Min Cost Climb, Decode Ways |

---

## 🌟 Final Intuition (Simple & Powerful)

> **Forward DP = What can I do NEXT?**  
> **Backward DP = How did I GET HERE?**

Keep this in mind, and you'll instantly know how to set up your DP recurrence.

---

