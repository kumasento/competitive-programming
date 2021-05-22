/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (50.67%)
 * Likes:    3062
 * Dislikes: 109
 * Total Accepted:    258.6K
 * Total Submissions: 507.4K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [["Q"]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 */

/**
 * Author: kumasento
 * Date:   2021-05-22T10:43:22.000-05:00
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
    void dfs(int i, const int n, vector<string> &path, vector<vector<string>> &ans) {
        if (i == n) {
            ans.push_back(path);
            return ;
        }

        auto check = [&](int k) {
            for (int j = 0; j < path.size(); j ++) {
                if (path[j][k] == 'Q') return false;
                int d = i - j;
                if (k - d >= 0 && path[j][k-d] == 'Q') return false;
                if (k + d < n && path[j][k+d] == 'Q') return false;
            }
            return true;
        };

        for (int j = 0; j < n; j ++) {
            if (check(j)) {
                path.emplace_back(n, '.'); path.back()[j] = 'Q';
                dfs(i + 1, n, path, ans);
                path.pop_back();
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<string> path;
        dfs(0, n, path, ans);
        cout << ans.size() << endl;

        return ans;
    }
};
// @lc code=end


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("51.n-queens.in"); cin.rdbuf(in.rdbuf());
#endif

    Solution sol;
    sol.solveNQueens(4);

}
