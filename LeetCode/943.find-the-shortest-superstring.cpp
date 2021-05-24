/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 *
 * https://leetcode.com/problems/find-the-shortest-superstring/description/
 *
 * algorithms
 * Hard (43.41%)
 * Likes:    567
 * Dislikes: 81
 * Total Accepted:    13.6K
 * Total Submissions: 31K
 * Testcase Example:  '["alex","loves","leetcode"]'
 *
 * Given an array of strings words, return the smallest string that contains
 * each string in words as a substring. If there are multiple valid strings of
 * the smallest length, return any of them.
 * 
 * You may assume that no string in words is a substring of another string in
 * words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["alex","loves","leetcode"]
 * Output: "alexlovesleetcode"
 * Explanation: All permutations of "alex","loves","leetcode" would also be
 * accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
 * Output: "gctaagttcatgcatc"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 12
 * 1 <= words[i].length <= 20
 * words[i] consists of lowercase English letters.
 * All the strings of words are unique.
 * 
 * 
 */

/**
 * Author: kumasento
 * Date:   2021-05-23T10:26:52.000-05:00
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

    string shortestSuperstring(vector<string>& words) {
        int n = words.size();

        auto check = [](string &a, string &b, int len) -> bool {
            int i = a.length() - len;
            for (int j = 0; j < len; j ++) 
                if (a[i + j] != b[j])
                    return false;
            return true;
        };

        auto calc = [&check](string &a, string &b) -> int {
            // overlapped length
            int m = min(a.length(), b.length());
            for (int l = m; l >= 1; l --) 
                if (check(a, b, l))
                    return l;
            return 0; 
        };


        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for (int i = 0; i < n; i ++) 
            for (int j = 0; j < n; j ++) {
                overlap[i][j] = calc(words[i], words[j]);

                // cout << "Overlap " << words[i] << " <-> " << words[j] << endl;
                // cout << overlap[i][j] << endl;
            }

        vector<vector<int>> dp(1<<n, vector<int>(n));
        vector<vector<int>> pa(1<<n, vector<int>(n, -1));

        for (int mask = 0; mask < (1<<n); ++ mask) {
            for (int bit = 0; bit < n; ++bit) {
                if ((mask >> bit) & 1) { // if this bit has been set
                    int pmask = mask ^ (1 << bit); // unset the bit
                    if (pmask == 0) continue; // initial case, bit is the only set one

                    for (int i = 0; i < n; ++i) {
                        if ((pmask >> i) & 1) {
                            int val = dp[pmask][i] + overlap[i][bit];
                            if (val > dp[mask][bit]) {
                                dp[mask][bit] = val;
                                pa[mask][bit] = i;
                            }
                        }
                    }
                }
            }
        }

        // reconstruct the answer.
        vector<int> perm(n);
        vector<bool> seen(n);
        int t = 0;
        int mask = (1 << n) - 1;

        // find the best ending word.
        int p = 0;
        for (int j = 0; j < n; ++ j)
            if (dp[(1<<n)-1][j] > dp[(1<<n)-1][p])
                p = j;
        // cout << words[p] << endl;

        while (p != -1) {
            perm[t ++] = p;
            seen[p] = true;
            int p2 = pa[mask][p];
            mask ^= 1 << p;
            p = p2;
        } 

        // why are these exist?
        for (int i = 0; i < n; ++ i)
            if (!seen[i])
                perm[t ++] = i;

        reverse(perm.begin(), perm.end());
        string ans = words[perm[0]];
        for (int i = 1; i < n; ++ i) {
            int len = overlap[perm[i-1]][perm[i]];
            ans.append(words[perm[i]].substr(len)); 
        }

        return ans;
    }
};
// @lc code=end


int main() {

    vector<string> words{"catg","ctaagt","gcta","ttca","atgcatc"};

    Solution sol;
    cout << sol.shortestSuperstring(words) << endl;

}
