/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

/**
 * Author: kumasento
 * Date:   2021-05-19T10:27:30.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// Constants:
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// Globals:

/// Solution:


// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());        

        int ans = 0;
        for (int i = 0, j = n - 1; i <= j; i ++, j --) 
            ans += nums[j] - nums[i];
        return ans;
    }
};
// @lc code=end



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
