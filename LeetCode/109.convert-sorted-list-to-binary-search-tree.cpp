/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    /// Build BST from nums[lo, hi)
    TreeNode *helper(vector<int> &nums, int lo, int hi) {
        // [1, 2) -> 1; [1, 3) -> 2
        // left part will be one less than the right.
        if (lo == hi)
            return nullptr;
        if (lo == hi - 1)
            return new TreeNode(nums[lo]);
        int mi = lo + (hi - lo) / 2;
        TreeNode *root = new TreeNode(nums[mi], helper(nums, lo, mi), helper(nums, mi + 1, hi));
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode *curr = head;
        while (curr) { nums.push_back(curr->val); curr = curr->next; }

        return helper(nums, 0, nums.size());
    }
};
// @lc code=end

