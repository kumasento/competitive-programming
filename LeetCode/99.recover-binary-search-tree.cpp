/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */
/**
 * Author: kumasento
 * Date:   2021-05-11T22:45:37.000-05:00
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
    pair<TreeNode*, TreeNode*> dfs(TreeNode *node, bool &done) {
        if (!node)
            return {NULL, NULL};

        TreeNode *leftMin, *leftMax, *rightMin, *rightMax;
        leftMin = leftMax = rightMin = rightMax = node;
        
        if (node->left)
            tie(leftMin, leftMax) = dfs(node->left, done);
        if (node->right)
            tie(rightMin, rightMax) = dfs(node->right, done);

        // if node is the lca of two problematic nodes.
        if (done || (leftMax->val <= node->val && rightMin->val >= node->val))
            return {leftMin, rightMax};

        if (leftMax->val > node->val && rightMin->val < node->val) {
            swap(leftMax->val, rightMin->val);
        } else if (leftMax->val > node->val) {
            swap(node->val, leftMax->val);
        } else if (rightMin->val < node->val) {
            swap(node->val, rightMin->val);
        }
        // once the issue has been fixed, we don't need to take care of the
        // min and max.
        done = true;
        return {leftMin, rightMax};
    };

    void recoverTree(TreeNode* root) {
        bool done = false;
        dfs(root, done);
    }
};
// @lc code=end

