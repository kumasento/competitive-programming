/**
 * Author: kumasento
 * Date:   2021-06-01T20:54:52
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
  ifstream in("C.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  LL N; cin >> N;

  // 0 - 1000: no comma
  // 1,000 - 999,999: one comma for all of them
  // 1,000,000 - 999,999,999 : two commas for all of them
  // 1,000,000,000 - 999,999,999,999 : three commas

  LL ans = 0LL;
  if (N >= (LL)1e3)
    ans += min(N, (LL)(1e6-1)) - (LL)(1e3-1);
  if (N >= (LL)1e6)
    ans += 2LL * (min(N, (LL)(1e9-1)) - (LL)(1e6-1));
  if (N >= (LL)1e9)
    ans += 3LL * (min(N, (LL)(1e12-1)) - (LL)(1e9-1));
  if (N >= (LL)1e12)
    ans += 4LL * (min(N, (LL)(1e15-1)) - (LL)(1e12-1));
  if (N >= (LL)1e15)
    ans += 5LL * (min(N, (LL)(1e18-1)) - (LL)(1e15-1));

  cout << ans << '\n';


}
