/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (80.34%)
 * Likes:    709
 * Dislikes: 1935
 * Total Accepted:    272.1K
 * Total Submissions: 338.4K
 * Testcase Example:  '"Hello"'
 *
 * Given a string s, return the string after replacing every uppercase letter
 * with the same lowercase letter.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "Hello"
 * Output: "hello"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "here"
 * Output: "here"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "LOVELY"
 * Output: "lovely"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s consists of printable ASCII characters.
 * 
 * 
 */

/**
 * Author: kumasento
 * Date:   2021-05-24T10:14:02.000-05:00
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
  ifstream in("709.to-lower-case.in"); cin.rdbuf(in.rdbuf());
#endif


}

// @lc code=start
class Solution {
public:
    string toLowerCase(string s) {
        string t;
        transform(s.begin(), s.end(), back_inserter(t), [](char c) { return tolower(c); });
        return t;
    }
};
// @lc code=end

