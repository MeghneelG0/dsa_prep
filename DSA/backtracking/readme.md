# Foundational templates

Thinking of backtracking in terms of these two core patterns is the key to mastering the topic.

-----

### \#\# Pattern 1: The "Subsets / Combinations" Template (Pick & Don't Pick)

This pattern is used when the problem asks you to form a group or collection of items, and the order of those items in the final group doesn't matter. For every element, you make a simple binary choice.

**The Core Question:** "Should I include this element in my current solution or not?"

**The Code Structure:**

```cpp
function solve(index, current_subset) {
    // Base Case

    // Choice 1: PICK the element
    current_subset.push_back(arr[index]);
    solve(index + 1, current_subset);
    // UNDO the choice
    current_subset.pop_back();

    // Choice 2: DON'T PICK the element
    solve(index + 1, current_subset);
}
```

**Typical Problems 🧩:**

  * Generating all subsets.
  * Generating all combinations (e.g., "choose k elements from n").
  * 0/1 Knapsack problem.
  * Problems like "Letter Case Permutation" (for each character, choose lowercase or uppercase).

-----

### \#\# Pattern 2: The "Permutations / Placement" Template

This pattern is used when the order or position of elements matters. You are essentially trying to fill a set of slots or build an ordered sequence.

**The Core Question:** "For the current *position*, which of my available options should I place here?"

**The Code Structure:**

```cpp
function solve(index, current_permutation) {
    // Base Case

    for (option in available_options) {
        // CHOOSE an option
        place(option, at_position_index);
        
        // RECURSE
        solve(index + 1, current_permutation);
        
        // UNCHOOSE (backtrack)
        remove(option, from_position_index);
    }
}
```

**Typical Problems 👑:**

  * Generating all permutations of a string/array.
  * N-Queens problem (for each row, which column should I place a queen in?).
  * Sudoku Solver (for each empty cell, which number from 1-9 can I place here?).
  * Finding all paths in a maze or on a grid.

-----

### \#\# The Unifying Idea

The most important takeaway is that both templates are just different ways of executing the same master algorithm: **Choose -\> Recurse -\> Unchoose**.

  * **Pattern 1** is a simple case where your choices at each step are always just `[pick, don't pick]`.
  * **Pattern 2** is the more general case where your choices at each step are a `for` loop over a set of available options.

Recognizing which of these two patterns a problem falls into is the most critical first step. Once you've identified the pattern, you can apply the corresponding template and focus on the problem-specific details, like the base case and constraints. You're on exactly the right track. 🧠




# Backtracking Subsets
- subsets.cpp

![alt text](public\image.png)

include and exclude in each node and we get a recursive tree of all the subsets




- permutation

 realizing that the `for` loop explores all possible choices for a single position, and the backtracking step (the second swap) undoes that choice so you can explore a different path.

Think of it like exploring a maze. You go down one path (make a choice), and if it's a dead end or you've explored it fully, you go back to the last junction (undo the choice) and try the next path.

Here's the standard C++ code for generating permutations using backtracking:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void generatePermutations(int index, std::vector<int>& nums, std::vector<std::vector<int>>& result) {
    // Base case: If we've reached the end of the array, we have a complete permutation.
    if (index == nums.size()) {
        result.push_back(nums);
        return;
    }

    // Explore choices for the current position (index).
    for (int i = index; i < nums.size(); ++i) {
        // 1. Make a choice: Swap the current element with the element at the 'index' position.
        std::swap(nums[index], nums[i]);

        // 2. Recurse: Move to the next position to build the rest of the permutation.
        generatePermutations(index + 1, nums, result);

        // 3. Backtrack: Undo the choice by swapping back. This is the crucial part.
        std::swap(nums[index], nums[i]);
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result;
    generatePermutations(0, nums, result);

    // Print all permutations
    for (const auto& p : result) {
        for (int num : p) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

-----

### \#\# Visualization with `nums = [1, 2, 3]`

Let's trace the execution step-by-step to see how the backtracking works. We'll focus on the state of `nums` and the call stack.

**Initial Call:** `generatePermutations(0, [1, 2, 3], result)`

  * `index` is `0`. The `for` loop will run for `i = 0, 1, 2`.

**1. `i = 0` (Choosing 1 for the first position)**

  * **Swap:** `swap(nums[0], nums[0])`. The array remains `[1, 2, 3]`.
  * **Recurse:** Call `generatePermutations(1, [1, 2, 3], result)`.
      * `index` is `1`. The `for` loop runs for `i = 1, 2`.
      * **`i = 1` (Choosing 2 for the second position)**
          * **Swap:** `swap(nums[1], nums[1])`. Array is `[1, 2, 3]`.
          * **Recurse:** Call `generatePermutations(2, [1, 2, 3], result)`.
              * `index` is `2`. The `for` loop runs for `i = 2`.
              * **`i = 2` (Choosing 3 for the third position)**
                  * **Swap:** `swap(nums[2], nums[2])`. Array is `[1, 2, 3]`.
                  * **Recurse:** Call `generatePermutations(3, [1, 2, 3], result)`.
                      * `index` (`3`) equals `nums.size()` (`3`). **Base case reached.**
                      * **Add `[1, 2, 3]` to the result.**
                      * Return.
                  * **Backtrack:** `swap(nums[2], nums[2])`. Array is back to `[1, 2, 3]`.
              * The loop for `index = 2` finishes. Return.
          * **Backtrack:** `swap(nums[1], nums[1])`. Array is back to `[1, 2, 3]`.
      * **`i = 2` (Choosing 3 for the second position)**
          * **Swap:** `swap(nums[1], nums[2])`. Array becomes `[1, 3, 2]`.
          * **Recurse:** Call `generatePermutations(2, [1, 3, 2], result)`.
              * `index` is `2`. Loop runs for `i = 2`.
              * **`i = 2` (Choosing 2 for the third position)**
                  * **Swap:** `swap(nums[2], nums[2])`. Array is `[1, 3, 2]`.
                  * **Recurse:** Call `generatePermutations(3, [1, 3, 2], result)`.
                      * `index` (`3`) equals `nums.size()` (`3`). **Base case reached.**
                      * **Add `[1, 3, 2]` to the result.**
                      * Return.
                  * **Backtrack:** `swap(nums[2], nums[2])`. Array is back to `[1, 3, 2]`.
              * The loop for `index = 2` finishes. Return.
          * **Backtrack:** `swap(nums[1], nums[2])`. Array is back to `[1, 2, 3]`. **This is crucial.** We've undone the choice of putting 3 in the second spot.
      * The loop for `index = 1` finishes. Return.
  * **Backtrack:** `swap(nums[0], nums[0])`. Array is back to `[1, 2, 3]`. The array is now in its original state, ready for the next iteration of the outermost loop.

-----

**2. `i = 1` (Choosing 2 for the first position)**

  * **Swap:** `swap(nums[0], nums[1])`. The array becomes `[2, 1, 3]`.
  * **Recurse:** Call `generatePermutations(1, [2, 1, 3], result)`.
      * This will now generate all permutations starting with 2: `[2, 1, 3]` and `[2, 3, 1]`. The process is identical to the one above.
  * **Backtrack:** `swap(nums[0], nums[1])`. The array swaps back to `[1, 2, 3]`. Now the array is clean for the final iteration.

-----

**3. `i = 2` (Choosing 3 for the first position)**

  * **Swap:** `swap(nums[0], nums[2])`. The array becomes `[3, 2, 1]`.
  * **Recurse:** Call `generatePermutations(1, [3, 2, 1], result)`.
      * This will generate all permutations starting with 3: `[3, 2, 1]` and `[3, 1, 2]`.
  * **Backtrack:** `swap(nums[0], nums[2])`. The array swaps back to `[1, 2, 3]`.

The process is now complete. The backtracking step (`std::swap(nums[index], nums[i]);` after the recursive call) is what allows the `for` loop to correctly explore all possibilities for each position. Without it, the changes from one branch of recursion would incorrectly affect the next branch.