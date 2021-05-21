/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */

/**
 * Author: kumasento
 * Date:   2021-05-21T10:04:28.000-05:00
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



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("890.find-and-replace-pattern.in"); cin.rdbuf(in.rdbuf());
#endif

}

// @lc code=start
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (string word : words) {
            vector<int> f(26, -1), g(26, -1);
            bool ok = true;
            for (int i = 0; i < word.length(); i ++) {
                int j = word[i] - 'a', k = pattern[i] - 'a';
                if (f[j] == -1 && g[k] == -1) {
                    f[j] = k, g[k] = j;
                } else if (!(f[j] == k && g[k] == j)) {
                    ok = false; break;
                }
            }
            if (ok) ans.push_back(word);
        }
        return ans;
    }
};
// @lc code=end

