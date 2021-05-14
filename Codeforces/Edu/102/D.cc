/**
 * Author: kumasento
 * Date:   2021-05-14T11:01:51.000-05:00
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

  int t; cin >> t;
  while (t --) {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    vector<int> pmin(n + 1, 0), pmax(n + 1, 0), smin(n + 1, 0), smax(n + 1, 0), psum(n + 1, 0);
    int cur = 0;
    for (int i = 0; i < n; i ++)  {
      cur += s[i] == '+' ? 1 : -1;
      psum[i + 1] = cur;
      pmin[i + 1] = min(pmin[i], cur);
      pmax[i + 1] = max(pmax[i], cur);
    }

    smin[n] = smax[n] = cur;
    for (int i = n - 1; i >= 0; i --) {
      cur += s[i] == '+' ? -1 : 1;
      smin[i] = min(smin[i + 1], cur);
      smax[i] = max(smax[i + 1], cur);
    }

    for (int i = 0; i < m; i ++) {
      int l, r; cin >> l >> r;

      int d = psum[r] - psum[l - 1];
      int mx = max(pmax[l - 1], smax[r] - d);
      int mn = min(pmin[l - 1], smin[r] - d);

      cout << mx - mn + 1 << endl;
    }

  }

}
