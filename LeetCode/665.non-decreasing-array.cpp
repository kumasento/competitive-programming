/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:

    bool checkPossibility(vector<int>& nums) {
        auto check = [](const vector<int>& nums) -> bool {
            for (int i = 0; i < nums.size() - 1; i ++)
                if (nums[i] > nums[i + 1])
                    return false;
            return true;
        };

        for (int i = 0; i < nums.size() - 1; i ++) {
            if (nums[i] > nums[i + 1]) {
                int a = nums[i], b = nums[i + 1];
                nums[i] = b;
                if (check(nums))
                    return true;
                nums[i] = a, nums[i + 1] = a;
                if (check(nums))
                    return true;
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

