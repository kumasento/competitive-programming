/**
 * Author: kumasento
 * Date:   2021-06-01T13:38:03
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
  ifstream in("A.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  int t; cin >> t;

  while (t --) {
    int n, k1, k2; cin >> n >> k1 >> k2;
    int w, b; cin >> w >> b;

    int max_w = min(k1, k2) + (max(k1, k2) - min(k1, k2)) / 2;
    int max_b = min(n - k1, n - k2) + (max(n - k1, n - k2) - min(n - k1, n - k2)) / 2;
    if (w <= max_w && b <= max_b)
      cout << "YES\n";
    else
      cout << "NO\n";
  }



}
