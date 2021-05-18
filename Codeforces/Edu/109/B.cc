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
    int n; cin >> n;

    vector<int> a(n); for (int &i : a) cin >> i;

    bool sorted = true;
    for (int i = 0; i < n - 1; i ++) if (a[i] != a[i + 1] - 1) { sorted = false; break; }
    if (sorted) {
      cout << 0 << endl;
    } else {
      if (a.front() == n && a.back() == 1) {
        cout << 3 << endl;
      } else if (a.back() != n && a.front() != 1) {
        cout << 2 << endl;
      } else {
        cout << 1 << endl;
      }
    }
  }

} 
