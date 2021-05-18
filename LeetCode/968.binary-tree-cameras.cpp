/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
 */

/**
 * Author: kumasento
 * Date:   2021-05-16T13:19:32.000-05:00
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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
    const int INF = 1000000000;

public:
    array<int, 3> solve(TreeNode *x) {
        if (!x) return {0, 0, INF};

        auto L = solve(x->left), R = solve(x->right);
        int mL12 = min(L[1], L[2]); // left is covered.
        int mR12 = min(R[1], R[2]); // right is covered.

        array<int, 3> ans;

        ans[0] = L[1] + R[1];
        ans[1] = min(L[2] + mR12, R[2] + mL12);
        ans[2] = 1 + min(L[0], mL12) + min(R[0], mR12);
        
        return ans;
    }


    int minCameraCover(TreeNode* root) {
        auto ans = solve(root);
        return min(ans[1], ans[2]);
    }
};
// @lc code=end



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
