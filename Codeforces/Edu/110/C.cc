/**
 * Author: kumasento
 * Date:   2021-06-05T10:19:29
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

  int t; cin >> t;

  while (t --) {
    string s; cin >> s;


    int lo = 0, prev = s[0] == '?' ? 0 : -1; LL ans = 1;

    auto check = [&](int hi) {
      int len = hi - prev;
      if (prev >= 1) {
        if (((len & 1) && s[hi] != s[prev-1]) ||
            (!(len & 1) && s[hi] == s[prev-1])) {
              return true;
            }
      }
      return false;
    };

    for (int hi = 1; hi < (int)s.length();  ++hi) {
      dbg(lo, prev, hi);
      if (s[hi] == '?') {
        if (prev == -1 || s[hi-1] != '?') prev = hi;
      } else { // s[hi] == '0' or '1'
        dbg(s[hi-1], s[hi]);
        if (s[hi-1] == s[hi])
          lo = hi, prev = prev < lo ? -1 : prev;
        else if (s[hi-1] == '?' && check(hi))
          lo = prev;
      }

      dbg(lo, prev, hi, hi - lo + 1);
      ans += hi - lo + 1;
    }

    cout << ans << '\n';
  }



}
