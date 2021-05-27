/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (52.63%)
 * Likes:    1106
 * Dislikes: 83
 * Total Accepted:    112.1K
 * Total Submissions: 211K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, return the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. If no such
 * two words exist, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists only of lowercase English letters.
 * 
 * 
 */
/**
 * Author: kumasento
 * Date:   2021-05-27T10:21:04.000-05:00
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
  ifstream in("318.maximum-product-of-word-lengths.in"); cin.rdbuf(in.rdbuf());
#endif

}

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<bitset<26>> cnts;
        for (string word : words) {
            cnts.emplace_back(0);
            auto &cnt = cnts.back();
            for (char c : word) cnt[c-'a'] = 1;        
        }

        int ans = 0;
        int n = words.size();
        for (int i = 0; i < n; i ++)
            for (int j = i + 1; j < n; j ++)
                if (!(cnts[i] & cnts[j]).count())
                    ans = max(ans, (int)(words[i].length() * words[j].length()));

        return ans;
    }
};
// @lc code=end

