/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (46.70%)
 * Likes:    5474
 * Dislikes: 265
 * Total Accepted:    424.8K
 * Total Submissions: 903.6K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

/**
 * Author: kumasento
 * Date:   2021-06-06T14:42:24
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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("128.longest-consecutive-sequence.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif





}

// @lc code=start

class Solution {
    vector<int> p, size;

    int Find(int x) {
        if (p[x] == x)
            return x;
        return p[x] = Find(p[x]);
    }

    void Union(int a, int b) {
        int x = Find(a), y = Find(b);
        if (x == y) return;
        if (size[x] < size[y])
            swap(x, y);

        p[y] = x;
        size[x] += size[y];
    }

public:
    int longestConsecutive(vector<int>& nums) {
        // maybe a hash table will do.
        // no: the number range is large.
        // a range-based data structure that support O(1) update?
        // disjoint set union

        if (nums.empty()) return 0;

        int n = nums.size();
        p.assign(n, -1); for (int i = 0; i < n; i ++) p[i] = i;
        size.assign(n, 1);

        unordered_map<int, int> ind;

        for (int i = 0; i < n; i ++) {
            int num = nums[i];
            if (ind.count(num)) continue;

            ind[num] = i; // record index
            if (ind.count(num-1)) Union(i, ind[num-1]);
            if (ind.count(num+1)) Union(i, ind[num+1]);
        }

        return *max_element(size.begin(), size.end());

    }
};
// @lc code=end

