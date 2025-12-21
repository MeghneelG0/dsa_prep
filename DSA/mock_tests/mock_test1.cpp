/* This is the best way to test if you are ready.

🚨 Infosys Specialist/Power Programmer Mock Test (2025 Pattern)
Instructions:

Total Time: 3 Hours (Strict).

Goal: You must solve 2 full questions to clear the cutoff. Solving 3 gets you the Power Programmer interview.

Language: C++ (Preferred).

Environment: No IDE features (Auto-complete is usually OFF in real OAs). Use a simple text editor or paper.

Question 1: The RPG Game (Greedy / Sorting)
Suggested Time: 30 Minutes Difficulty: Easy-Medium

Problem Statement: You are playing a game where you are a knight with an initial power level. There are n monsters in a dungeon. Each monster i has a power[i] and a bonus[i].

You can only defeat a monster if your current power >= monster_power[i].

If you defeat monster i, your current power increases by bonus[i].

You can fight monsters in any order.

Find the maximum number of monsters you can defeat.

Input Format:

n: Integer (Number of monsters)

initial_power: Integer

monster_power: Array of size n

monster_bonus: Array of size n

Constraints:

1 <= n <= 10^5

1 <= power <= 10^9

Sample Input:

Plaintext

n = 3, initial_power = 10
monster_power = [15, 10, 12]
monster_bonus = [5, 2, 3]
Sample Output:

Plaintext

3
(Explanation: Fight monster with power 10 first. Your power becomes 10+2=12. Then fight monster 12. Power becomes 12+3=15. Then fight monster 15. Total 3.) 
*/
#include <bits/stdc++.h>
using namespace std; 

int fightMonster(int n, int initial_power, vector<int> monster_power, vector<int> monster_bonus) {
    vector<pair<int,int>> monsters;
    for (int i=0; i < monster_power.size(); i++) {
        monsters.push_back({monster_power[i], monster_bonus[i]});
    }
    sort(monsters.begin(), monsters.end());
    int count = 0; 
    long long currentPower = initial_power; 
    for (int i=0; i < n; i++) {
        if (currentPower >= monsters[i].first) {
            currentPower += monsters[i].second;
            count++;
        } else {
            break;
        }
    }
    return count;
}

/* Question 2: The Continuous Subarray (Sliding Window / Map)
Suggested Time: 45 Minutes Difficulty: Medium

Problem Statement: You are given an array arr of size n. Find the length of the longest contiguous subarray such that the absolute difference between any two elements in that subarray is less than or equal to limit.

Input Format:

n: Integer

arr: Array of size n

limit: Integer

Constraints:

1 <= n <= 10^5

0 <= limit <= 10^9

Sample Input:

Plaintext

n = 4, limit = 4
arr = [8, 2, 4, 7]
Sample Output:

Plaintext

2
(Explanation: Subarray [2, 4] diff is 2 (<=4). Subarray [4, 7] diff is 3 (<=4). [8, 2] diff is 6 (>4). Longest is size 2.) */
#include <bits/stdc++.h>
using namespace std;

int longestSubarray(int n, vector<int>& arr, int limit) {
    multiset<int> window; // Keeps elements sorted
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < n; right++) {
        // 1. Add new guy to window
        window.insert(arr[right]);

        // 2. Check if window is invalid (Max - Min > Limit)
        // *window.rbegin() gives the largest element
        // *window.begin() gives the smallest element
        while (!window.empty() && (*window.rbegin() - *window.begin() > limit)) {
            
            // Remove the element at 'left' to make window valid again
            // CRITICAL: Use window.find() so we erase only ONE instance (if duplicates exist)
            auto it = window.find(arr[left]);
            window.erase(it);
            
            left++; // Shrink window
        }

        // 3. Update Answer
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}