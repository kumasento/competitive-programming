/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 *
 * https://leetcode.com/problems/maximum-performance-of-a-team/description/
 *
 * algorithms
 * Hard (36.27%)
 * Likes:    450
 * Dislikes: 28
 * Total Accepted:    14.9K
 * Total Submissions: 40.7K
 * Testcase Example:  '6\n[2,10,3,1,5,8]\n[5,4,3,9,7,2]\n2'
 *
 * You are given two integers n and k and two integer arrays speed and
 * efficiency both of length n. There are n engineers numbered from 1 to n.
 * speed[i] and efficiency[i] represent the speed and efficiency of the i^th
 * engineer respectively.
 *
 * Choose at most k different engineers out of the n engineers to form a team
 * with the maximum performance.
 *
 * The performance of a team is the sum of their engineers' speeds multiplied
 * by the minimum efficiency among their engineers.
 *
 * Return the maximum performance of this team. Since the answer can be a huge
 * number, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
 * Output: 60
 * Explanation:
 * We have the maximum performance of the team by selecting engineer 2 (with
 * speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7).
 * That is, performance = (10 + 5) * min(4, 7) = 60.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
 * Output: 68
 * Explanation:
 * This is the same example as the first but k = 3. We can select engineer 1,
 * engineer 2 and engineer 5 to get the maximum performance of the team. That
 * is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
 * Output: 72
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= <= k <= n <= 10^5
 * speed.length == n
 * efficiency.length == n
 * 1 <= speed[i] <= 10^5
 * 1 <= efficiency[i] <= 10^8
 *
 *
 */


/**
 * Author: kumasento
 * Date:   2021-06-05T08:23:14
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
    using ll = long long;

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // sort by efficiency first?
        // and get the max k sum of range [i...] by heap.

        constexpr ll MOD = 1e9 + 7;

        vector<int> ord(n); for (int i = 0; i < n; i++) ord[i] = i;
        sort(ord.begin(), ord.end(), [&](const int &i, const int &j) { return efficiency[i] < efficiency[j]; });

        priority_queue<int, vector<int>, greater<int>> pq;

        ll sum = 0, ans = 0;
        for (int i = n - 1; i >= 0; -- i) {
            ans = max((sum + speed[ord[i]]) * (ll)efficiency[ord[i]], ans);
            pq.push(speed[ord[i]]); sum = (sum + (ll)speed[ord[i]]);
            if (pq.size() > k - 1) { sum = (sum - (ll)pq.top()); pq.pop(); }
        }

        return ans % MOD;
    }
};
// @lc code=end


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_DEBUG
    ifstream in("1383.1.in"); if (in) cin.rdbuf(in.rdbuf());
    #endif


    int n, k;
    cin >> n;
    vector<int> speed(n), efficiency(n);
    for (int &i : speed) cin >> i;
    for (int &i : efficiency) cin >> i;
    cin >> k;

    Solution sol;
    cout << sol.maxPerformance(n, speed, efficiency, k) << '\n';
}
