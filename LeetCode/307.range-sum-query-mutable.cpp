/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */
/**
 * Author: kumasento
 * Date:   2021-05-12T11:46:07.000-05:00
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
class NumArray {
    vector<int> bit, &nums;
    int n;

public:
    NumArray(vector<int>& nums): nums(nums) {
        n = nums.size();
        bit.assign(n + 1, 0);

        for (int i = 1; i <= n; i ++)
            add(i - 1, nums[i - 1]);
    }

    void add(int idx, int delta) {
        for (++idx; idx <= n; idx += (idx & -idx))
            bit[idx] += delta;
    }
    
    void update(int index, int val) {
        add(index, val - nums[index]);
        nums[index] = val;
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= (idx & -idx))
            ret += bit[idx];
        return ret;
    }
    
    int sumRange(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> nums{7, 2, 7, 2, 0};
    NumArray sol{nums};
}   
