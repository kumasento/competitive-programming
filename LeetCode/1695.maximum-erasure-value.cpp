/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 *
 * https://leetcode.com/problems/maximum-erasure-value/description/
 *
 * algorithms
 * Medium (49.17%)
 * Likes:    305
 * Dislikes: 7
 * Total Accepted:    16K
 * Total Submissions: 31.6K
 * Testcase Example:  '[4,2,4,5,6]'
 *
 * You are given an array of positive integers nums and want to erase a
 * subarray containing unique elements. The score you get by erasing the
 * subarray is equal to the sum of its elements.
 * 
 * Return the maximum score you can get by erasing exactly one subarray.
 * 
 * An array b is called to be a subarray of a if it forms a contiguous
 * subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some
 * (l,r).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,2,4,5,6]
 * Output: 17
 * Explanation: The optimal subarray here is [2,4,5,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,2,1,2,5,2,1,2,5]
 * Output: 8
 * Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */

/**
 * Author: kumasento
 * Date:   2021-05-28T10:58:12.000-05:00
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
constexpr int IINF = 1000000000;
constexpr LL LINF = 10000000000000000LL;
constexpr LL MOD = 1e9 + 7;

#define DEBUG_VEC(vec) { for (auto i : (vec)) cout << i << " "; cout << '\n'; }

/// Globals:

/// Solution:

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, sum = 0, lo = 0, hi = 0;
        unordered_set<int> vals;

        for (; hi < nums.size(); hi ++) {

            if (vals.count(nums[hi])) {
                while (lo < hi) {
                    int val = nums[lo];
                    sum -= val;
                    vals.erase(val);
                    lo ++;
                    if (val == nums[hi])
                        break;
                }
            }

            vals.insert(nums[hi]);
            sum += nums[hi]; 
            ans = max(sum, ans);
        }

        return ans;
    }
};
// @lc code=end





int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_DEBUG
    ifstream in("1695.in"); if (in) cin.rdbuf(in.rdbuf());
    #endif

    vector<int> nums;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(nums));

    DEBUG_VEC(nums);

    Solution sol;
    cout << sol.maximumUniqueSubarray(nums) << endl;

}
