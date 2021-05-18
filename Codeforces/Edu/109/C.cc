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
    int n; LL m; cin >> n >> m;

    vector<LL> x(n); for (LL &i : x) cin >> i;
    vector<int> d(n); for (int i = 0; i < n; i ++) { char c; cin >> c; d[i] = c == 'L'; }
    vector<LL> ans(n, -1);
    vector<int> ord(n); for (int i = 0; i < n; i ++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int i, int j) { return x[i] < x[j]; });

    array<stack<LL>, 2> st;
    for (int i : ord) {
      int k = x[i] & 1;
      if (d[i]) { // left
        if (st[k].empty())
          st[k].push(i); // left most will be reflected.
        else {
          int j = st[k].top(); st[k].pop();
          ans[i] = ans[j] = (x[i] - (d[j] ? - x[j] : x[j])) / 2;
        }
      } else { // right
        st[k].push(i);
      }
    }

    for (int k = 0; k < 2; k ++) {
      while (int(st[k].size()) > 1) {
        int i = st[k].top(); st[k].pop();
        int j = st[k].top(); st[k].pop();
        ans[i] = ans[j] = (2 * m - x[i] - (d[j] ? - x[j] : x[j])) / 2;
      }
    }

    for (int i = 0; i < n; i ++)
      cout << ans[i] << " ";
    cout << endl;
  }
} 
