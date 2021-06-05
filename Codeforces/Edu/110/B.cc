/**
 * Author: kumasento
 * Date:   2021-06-04T22:45:22
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
  ifstream in("B.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  int t; cin >> t;

  while (t --) {
    int n; cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i ++) {
      int x; cin >> x;
      if (x & 1) b.push_back(x);
      else a.push_back(x);
    }

    // reorder all even numbers to the beginning.
    // what about odd numbers? 3 7 9 ... it doesn't matter for their positioning.

    LL ans = 0;
    for (int i = 0; i < (int)a.size(); ++ i)
      ans += (n - i - 1);
    for (int i = 0; i < (int)b.size(); ++ i)
      for (int j = i + 1; j < (int)b.size(); ++ j)
        if (gcd(b[i], 2 * b[j]) > 1)
          ++ ans;

    cout << ans << '\n';
  }



}
