/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

/**
 * Author: kumasento
 * Date:   2021-05-12T11:09:11.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// ---------- Globals   ---------

/// ---------- Solution  ---------


// @lc code=start
class NumMatrix {
public:

    struct FenwickTree {
        vector<vector<int>> bit;
        int n, m;

        FenwickTree() {}

        FenwickTree(vector<vector<int>> &matrix) {
            n = matrix.size(), m = matrix[0].size();
            bit.assign(n + 1, vector<int>(m + 1, 0));

            for (int i = 1; i <= n; i ++)
                for (int j = 1; j <= m; j ++)
                    add(i, j, matrix[i - 1][j - 1]);
        }

        int sum(int x, int y) {
            int ret = 0;
            for (int i = x; i > 0; i -= (i & -i))
                for (int j = y; j > 0; j -= (j & -j))
                    ret += bit[i][j];
            return ret;
        }

        void add(int x, int y, int delta) {
            for (int i = x; i <= n; i += (i & -i))
                for (int j = y; j <= m; j += (j & -j))
                    bit[i][j] += delta;
        }
    };

    FenwickTree t;

    NumMatrix(vector<vector<int>>& matrix) {
        t = FenwickTree(matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // cout << t.sum(row2 + 1, col2 + 1) << endl;
        // cout << t.sum(row1, col1) << endl;
        // cout << t.sum(row1, col2 + 1) << endl;
        // cout << t.sum(row2 + 1, col1) << endl;

        return t.sum(row2 + 1, col2 + 1) +
               t.sum(row1, col1) -
               t.sum(row1, col2 + 1) -
               t.sum(row2 + 1, col1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end




int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<vector<int>> matrix{
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix sol(matrix);
    cout << sol.sumRegion(2, 1, 4, 3) << endl;
}
