/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Medium (32.91%)
 * Likes:    2163
 * Dislikes: 111
 * Total Accepted:    186.8K
 * Total Submissions: 565.5K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving
 * of s1 and s2.
 * 
 * An interleaving of two strings s and t is a configuration where they are
 * divided into non-empty substrings such that:
 * 
 * 
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 +
 * t3 + s3 + ...
 * 
 * 
 * Note: a + b is the concatenation of strings a and b.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s1 = "", s2 = "", s3 = ""
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s1.length, s2.length <= 100
 * 0 <= s3.length <= 200
 * s1, s2, and s3 consist of lowercase English letters.
 * 
 * 
 * 
 * Follow up: Could you solve it using only O(s2.length) additional memory
 * space?
 * 
 */

/**
 * Author: kumasento
 * Date:   2021-06-02T08:38:36
 */

#include <bits/stdc++.h>
using namespace std;

/// --------------------- Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// --------------------- Constants:
constexpr int INF = 1e9;
constexpr LL LINF = 1e16;
constexpr LL MOD = 1e9 + 7;

/// --------------------- Helpers:
// *** Credit to Neal Wu
// overload operator<<() for pairs.
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// overload container output. Won't affect strings.
template <typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream &operator<<(ostream &os, const C &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// variadic debugger.
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/// --------------------- Globals:

/// --------------------- Solution:

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.length(), m = s2.length();
        if (s3.length() != n + m) return false;
        if (n == 0) return s2 == s3;
        if (m == 0) return s1 == s3;

#if 0
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false)); 
        dp[0][0] = true, dp[1][0] = s1[0] == s3[0], dp[0][1] = s2[0] == s3[0];

        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i > 0 && s3[i+j-1] == s1[i-1]) dp[i][j] = dp[i][j] | dp[i-1][j];
                if (j > 0 && s3[i+j-1] == s2[j-1]) dp[i][j] = dp[i][j] | dp[i][j-1];
            }
        }
        return dp[n][m];
#endif
        vector<bool> dp(m + 1, false); 
        dp[0] = true; 
        for (int i = 1; i <= m; i ++) // init j when i is empty
            dp[i] = dp[i-1] && s2[i-1] == s3[i-1];

        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (j == 0) dp[j] = (s1[i-1] == s3[i+j-1]) && dp[j];
                else dp[j] = ((s1[i-1] == s3[i+j-1]) && dp[j]) ||
                             ((s2[j-1] == s3[i+j-1]) && dp[j-1]);
            }
        }

        return dp[m];
    }
};
// @lc code=end


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("97.interleaving-string.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif


    Solution sol;
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") << '\n';


}
