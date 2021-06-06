/**
 * Author: kumasento
 * Date:   2021-06-06T15:28:03
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
    int n; cin >> n;
    vector<int> a(n); for (int &i : a) cin >> i;

    if (any_of(a.begin(), a.end(), [](int i) { return i < 0; }))
      cout << "NO\n";
    else {
      unordered_set<int> b{a.begin(), a.end()};
      unordered_set<int> c;

      int cnt = 0;
      do {
        c.clear();
        for (auto i : b) for (auto j : b) {
          if (i == j) continue;
          int d = abs(i - j);
          if (b.count(d)) continue;
          c.insert(d);
        }
        b.insert(c.begin(), c.end());
      } while (!c.empty());

      cout << "YES\n";
      cout << b.size() << '\n';
      for (auto i : b) cout << i << ' ';
      cout << '\n';
    }

  }



}
