/**
 * Author: kumasento
 * Date:   2021-05-18T12:15:37.000-05:00
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

  int n, m, a, b;
  cin >> n >> m >> a >> b;

  int k = (int)ceil((double)n/m);
  int ans = INT_MAX;
  for (int i = 0; i <= k; i ++) 
    ans = min(ans, i * b + max(n - m * i, 0) * a);
  cout << ans << endl;
}
