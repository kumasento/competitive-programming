/**
 * Author: kumasento
 * Date:   2021-05-18T20:42:38.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// Constants:
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// Globals:

/// Solution:



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, t; cin >> n >> t;
  vector<int> a(n); for (int &i : a) cin >> i;

  LL sum = 0;
  int ans = 0;
  int lo = 0;
  // interval is [lo, hi]
  for (int hi = 0; hi < n; hi ++) {
    while (lo < hi && sum + a[hi] > t) 
      sum -= a[lo ++];
    if (sum + a[hi] > t) // can only be that lo==hi.
      lo ++;
    else
      sum += a[hi];
    ans = max(ans, hi - lo + 1);
  }

  cout << ans << endl;
}
