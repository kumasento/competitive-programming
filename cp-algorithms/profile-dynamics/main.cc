/**
 * Author: kumasento
 * Date:   2021-05-29T14:17:36
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

int n, m;
vector<vector<LL>> dp;

// mask is given. next_mask is on the next row.
// dp will be updated only when y reaches m.

/** Starting from dp[x][mask], how many ways we can build next_mask on the next row. */
void calc(int x, int y, int mask, int next_mask) {
  if (x == n) return;
  if (y >= m) dp[x+1][next_mask] += dp[x][mask];
  else {
    int my_mask = 1 << y;

    // Try to fill the y position.
    if (mask & my_mask) // It has been occupied.
      calc(x, y + 1, mask, next_mask);
    else {
      // Not occupied, place 2x1, next_mask will be marked as well.
      calc(x, y + 1, mask, next_mask | my_mask);
      // If I can place 1x2, place it, next_mask won't be bothered.
      if (y + 1 < m && !(mask & my_mask) && !(mask & (my_mask << 1)))
        calc(x, y + 2, mask, next_mask);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("main.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif


  cin >> n >> m;
  dp.resize(n + 1, vector<LL>(1<<m)); // each row has 2^m elements (masks).

  dp[0][0] = 1;
  for (int x = 0; x < n; ++ x) {
    for (int mask = 0; mask < (1<<m); mask ++)
      calc(x, 0, mask, 0);
    dbg(dp[x+1]);
  }

  cout << dp[n][0] << '\n';
}
