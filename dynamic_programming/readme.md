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