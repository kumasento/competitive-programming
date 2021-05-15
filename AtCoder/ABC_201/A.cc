/**
 * Author: kumasento
 * Date:   2021-05-15T12:54:05.000-05:00
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

  int A1, A2, A3; cin >> A1 >> A2 >> A3;

  if (A3 - A2 == A2 - A1 ||
      A2 - A3 == A3 - A1 || 
      A3 - A1 == A1 - A2 || 
      A1 - A3 == A3 - A2 || 
      A1 - A2 == A2 - A3 || 
      A2 - A1 == A1 - A3) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;
}
