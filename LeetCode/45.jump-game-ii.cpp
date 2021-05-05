/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, INT_MAX);

        // dp[i] min num jumps to reach i. 
        // dp[i] = min(dp[j] + 1) nums[j] + j <= i.
        dp[0] = 0;
        for (int i = 0; i < N; i ++) {
            for (int j = 1; j <= nums[i] && i + j < N; j ++)
                dp[i + j] = min(dp[i + j], dp[i] + 1);
        }

        return dp[N - 1];
    }
};
// @lc code=end

