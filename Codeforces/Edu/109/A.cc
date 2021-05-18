/**
 * Author: kumasento
 * Date:   2021-05-16T08:35:04.000-05:00
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
    int k; cin >> k;

    if (k == 100 || k == 0)
      cout << "1" << endl;
    else {
      int a = k, b = 100 - k;
      int g = gcd(a, b);
      a /= g, b /= g;
      cout << a + b << endl;
    }
  }
} 
