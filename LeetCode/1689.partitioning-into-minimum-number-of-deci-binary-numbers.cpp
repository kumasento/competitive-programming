/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 *
 * https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/
 *
 * algorithms
 * Medium (87.04%)
 * Likes:    293
 * Dislikes: 244
 * Total Accepted:    31.9K
 * Total Submissions: 36.2K
 * Testcase Example:  '"32"'
 *
 * A decimal number is called deci-binary if each of its digits is either 0 or
 * 1 without any leading zeros. For example, 101 and 1100 are deci-binary,
 * while 112 and 3001 are not.
 * 
 * Given a string n that represents a positive decimal integer, return the
 * minimum number of positive deci-binary numbers needed so that they sum up to
 * n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = "32"
 * Output: 3
 * Explanation: 10 + 11 + 11 = 32
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = "82734"
 * Output: 8
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = "27346209830709182346"
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n.length <= 10^5
 * n consists of only digits.
 * n does not contain any leading zeros and represents a positive integer.
 * 
 */

/**
 * Author: kumasento
 * Date:   2021-05-26T13:59:30.000-05:00
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
  ifstream in("1689.partitioning-into-minimum-number-of-deci-binary-numbers.in"); cin.rdbuf(in.rdbuf());
#endif

}

// @lc code=start
class Solution {
public:
    int minPartitions(string n) {
        if (n == "0")
            return 1;
        
        return *max_element(n.begin(), n.end()) - '0';
    }
};
// @lc code=end

