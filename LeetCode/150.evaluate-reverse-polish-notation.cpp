/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (38.50%)
 * Likes:    1664
 * Dislikes: 529
 * Total Accepted:    288.5K
 * Total Submissions: 744.7K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, and /. Each operand may be an integer or
 * another expression.
 * 
 * Note that division between two integers should truncate toward zero.
 * 
 * It is guaranteed that the given RPN expression is always valid. That means
 * the expression would always evaluate to a result, and there will not be any
 * division by zero operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: tokens = ["2","1","+","3","*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: tokens = ["4","13","5","/","+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * Output: 22
 * Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= tokens.length <= 10^4
 * tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the
 * range [-200, 200].
 * 
 * 
 */

/**
 * Author: kumasento
 * Date:   2021-05-25T09:40:16.000-05:00
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
  ifstream in("150.evaluate-reverse-polish-notation.in"); cin.rdbuf(in.rdbuf());
#endif

}

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto &tk: tokens) {
            if (tk.length() == 1 && !isdigit(tk[0])) {
                const int rhs = st.top(); st.pop();
                const int lhs = st.top(); st.pop();
                switch (tk[0]) {
                    case '+':  st.push(lhs + rhs); break;
                    case '-':  st.push(lhs - rhs); break;
                    case '*':  st.push(lhs * rhs); break;
                    case '/':  st.push(lhs / rhs); break;
                }
            } else {
                int num = stoi(tk); st.push(num);
            }
        } 
        return st.top();
    }
};
// @lc code=end

