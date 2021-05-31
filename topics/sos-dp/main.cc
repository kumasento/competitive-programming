/**
 * Author: kumasento
 * Date:   2021-05-31T20:55:08
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
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
// overload container output. Won't affect strings.
template <typename C,
          typename T = typename enable_if<!is_same<C, string>::value,
                                          typename C::value_type>::type>
ostream &operator<<(ostream &os, const C &v) {
  os << '{';
  string sep;
  for (const T &x : v)
    os << sep << x, sep = ", ";
  return os << '}';
}
// variadic debugger.
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#ifdef LOCAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/// --------------------- Globals:

/// --------------------- Solution:

// https://codeforces.com/blog/entry/45223

// O(4^N)
void solve(int n, vector<int> &A) {
  vector<int> F(1 << n);
  for (int mask = 0; mask < (1 << n); mask++) {
    // here we just iterate every mask and see if it is a subset of mask.
    for (int i = 0; i < (1 << n); i++) {
      if ((i & mask) == i)
        F[mask] += A[i];
    }
  }
}

// O(3^N)
void solve2(int n, vector<int> &A) {
  vector<int> F(1 << n);

  // mask = {0, 1, 2, 3}, n = 2;
  // i & mask == i -> means i is a subset of mask.
  for (int mask = 0; mask < (1 << n); mask++) {
    F[mask] = 0;
    for (int i = mask; i; i = (i - 1) & mask) {
      F[mask] += A[i];
    }
  }
}

void solve3(int n, vector<int> &A) {
  vector<int> F(1 << n);
  vector dp((1 << n), vector<int>((1 << n)));
  for (int mask = 0; mask < (1 << n); ++mask) {
    dp[mask][-1] = A[mask];       // dp[mask, i] is the sum over S(mask, i).
    for (int i = 0; i < n; ++i) { // each level of the tree.
      if (mask & (1 << i))
        dp[mask][i] = dp[mask][i - 1] + dp[mask ^ (1 << i)][i - 1];
      else
        dp[mask][i] = dp[mask][i - 1];
    }
    F[mask] = dp[mask][n - 1]; // root of the tree.
  }
}

void solve4(int n, vector<int> &A) {
  vector<int> F(1 << n);
  for (int i = 0; i < (1 << n); ++i)
    F[i] = A[i];                                // initialize for each mask
  for (int i = 0; i < n; ++i)                   // at each level
    for (int mask = 0; mask < (1 << n); ++mask) // go through every mask
      if (mask & (1 << i)) // if i-th bit is on, add from the other branch
        F[mask] += F[mask ^ (1 << i)];
  // otherwise, just propagate.
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("main.in");
  if (in)
    cin.rdbuf(in.rdbuf());
#endif
}
