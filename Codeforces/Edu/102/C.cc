/**
 * Author: kumasento
 * Date:   2021-05-14T10:16:15.000-05:00
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
    int n, k; cin >> n >> k;

    for (int i = 1; i < k - (n - k); i ++)
      cout << i << " ";
    for (int i = k - (n - k), j = k; i <= k; i ++, j --) 
      cout << j << " ";
    cout << endl;
  }
}
