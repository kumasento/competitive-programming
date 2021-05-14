/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */

/**
 * Author: kumasento
 * Date:   2021-05-14T09:06:00.000-05:00
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



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode *x) {
        if (!x)
            return nullptr;
        TreeNode *left_end = dfs(x->left);
        TreeNode *right_end = dfs(x->right);

        if (!left_end && !right_end)
            return x;
        if (!right_end) {
            x->right = x->left;
            x->left = nullptr;
            return left_end;
        }
        if (!left_end) 
            return right_end;

        left_end->right = x->right;
        x->right = x->left; 
        x->left = nullptr;
        return right_end;
    }

    void flatten(TreeNode* root) {
        dfs(root);
    }
};
// @lc code=end

