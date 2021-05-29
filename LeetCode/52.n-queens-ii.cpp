/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (60.94%)
 * Likes:    890
 * Dislikes: 187
 * Total Accepted:    166.7K
 * Total Submissions: 271.3K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 9
 *
 *
 */

/**
 * Author: kumasento
 * Date:   2021-05-29T09:59:20.000-05:00
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
  ifstream in("52.n-queens-ii.in"); if (in) cin.rdbuf(in.rdbuf());
#endif

    string s = "Hello World!";
    vector<int> vec{1, 2, 3, 4};

    dbg(s);
    dbg(vec);

}

// @lc code=start
class Solution {
public:
  void dfs(int i, vector<int> &path, int &ans, const int &n) {
    if (i == n) {
      ans++;
      return;
    }

    for (int k = 0; k < n; k++) {
      if (find(path.begin(), path.end(), k) != path.end())
        continue;

      bool ok = true;
      for (int j = 0; j < i; j++)
        if (abs(i - j) == abs(k - path[j]))
          ok = false;
      if (ok) {
        path.push_back(k);
        dfs(i + 1, path, ans, n);
        path.pop_back();
      }
    }
  }

  int totalNQueens(int n) {
    int ans = 0;
    vector<int> path;
    dfs(0, path, ans, n);
    return ans;
  }
};
// @lc code=end
