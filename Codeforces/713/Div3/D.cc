/**
 * Author: kumasento
 * Date:   2021-06-08T20:53:45
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

void print(vector<LL> &b, int i, int j) {
  for (int k = 0; k < (int) b.size(); k ++)
    if (k != i && k != j)
      cout << b[k] << ' ';
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("D.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  int t; cin >> t;
  while (t --) {
    int n; cin >> n; vector<LL> b(n + 2); for (auto &i : b) cin >> i;

    LL sum = accumulate(b.begin(), b.end(), 0LL);
    unordered_map<LL, int> cnts; for (LL i : b) ++cnts[i];

    bool ok = false;
    for (int i = 0; i < n + 2; i ++) {
      // if b[i] is the sum, then b[i] = sum - b[i] - b[j]
      // b[j] = sum - 2 b[i]
      LL bj = sum - 2 * b[i];
      if ((bj == b[i] && cnts[bj] >= 2) ||
          (bj != b[i] && cnts[bj] >= 1)) {
        -- cnts[bj], -- cnts[b[i]];
        for (auto [v, c] : cnts) for (int k = 0; k < c; k ++) cout << v << ' '; cout << '\n';

        ok = true;
        break;
      }
    }

    if (!ok) cout << -1 << '\n';
  }



}
