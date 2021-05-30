/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (37.33%)
 * Likes:    1226
 * Dislikes: 223
 * Total Accepted:    105K
 * Total Submissions: 278.6K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an integer array nums, return the maximum difference between two
 * successive elements in its sorted form. If the array contains less than two
 * elements, return 0.
 * 
 * You must write an algorithm that runs in linear time and uses linear extra
 * space.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or
 * (6,9) has the maximum difference 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return
 * 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */

/**
 * Author: kumasento
 * Date:   2021-05-30T09:37:32
 */

#include <bits/stdc++.h>
using namespace std;

/// --------------------- Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// --------------------- Constants:
constexpr int INF = 1e9;
constexpr LL LINF = 1e16;
constexpr LL MOD = 1e9 + 7;

/// --------------------- Helpers:
// *** Credit to Neal Wu
// overload operator<<() for pairs.
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// overload container output. Won't affect strings.
template <typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream &operator<<(ostream &os, const C &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// variadic debugger.
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/// --------------------- Globals:

/// --------------------- Solution:

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        vector<pair<int, int>> buckets(n, {INT_MAX, INT_MIN});
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        int bucket_size = ceil((double)(mx - mn) / (n - 1));
        if (bucket_size == 0) return 0;
        for (int num : nums) {
            int ind = (num - mn) / bucket_size;
            buckets[ind].first = min(buckets[ind].first, num);
            buckets[ind].second = max(buckets[ind].second, num);
        }

        int ans = 0;
        int cur = INT_MAX;

        int i = 0;
        while (i < n) {
            if (buckets[i].first == INT_MAX) {
                i ++;
                continue;
            }

            if (cur == INT_MAX) {
                cur = buckets[i++].second;
                continue;
            }

            ans = max(ans, buckets[i].first - cur);
            cur = buckets[i++].second;
        }

        return ans;
    }
};
// @lc code=end


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("164.maximum-gap.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif


    vector<int> v{3};
    Solution sol;
    dbg(sol.maximumGap(v));

}
