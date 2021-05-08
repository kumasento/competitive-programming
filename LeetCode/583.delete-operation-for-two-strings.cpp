/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // find the longest subsequence
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                dp[i][j] = max(dp[i][j - 1], dp[i][j]);
            }
        }

        return m + n - 2 * dp[m][n];
    }
};
// @lc code=end

