/**
 * Author: kumasento
 * Date:   2021-05-18T11:59:08.000-05:00
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

  LL n, l; cin >> n >> l;
  vector<LL> a(n); for (LL &i: a) cin >> i;
  sort(a.begin(), a.end());

  double d = 0;
  for (int i = 0; i < n; i ++) {
    double t = i == 0 ? a[i] : (0.5 * (a[i] - a[i - 1]));
    d = max(d, t);
  }
  d = max((double)l - a.back(), d);

  cout << fixed << d << endl;
}
