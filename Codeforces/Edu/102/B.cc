/**
 * Author: kumasento
 * Date:   2021-05-14T10:04:55.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// ---------- Globals   ---------

/// ---------- Solution  ---------



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int q; cin >> q;
  while (q --) {
    string s, t; cin >> s >> t;

    int n = s.length(), m = t.length();
    int k = lcm(n, m);

    string S, T;
    for (int i = 0; i < k / n; i ++) S += s;
    for (int i = 0; i < k / m; i ++) T += t;

    if (S == T)
      cout << S << endl;
    else
      cout << -1 << endl;
  }
}
