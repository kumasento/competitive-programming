/**
 * Author: kumasento
 * Date:   2021-05-20T16:12:55.000-05:00
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
#ifdef LOCAL_DEBUG
  ifstream in("C.in"); cin.rdbuf(in.rdbuf());
#endif

  int t; cin >> t;
  while (t --) {
    int n; cin >> n;
    vector<LL> a(n); for (LL &i : a) cin >> i;

    map<LL, LL> dp; // dp[i]: the sum of all the indices for value a[i];
    LL ans = 0;
    for (int i = 0; i < n; i ++) {
      if (!dp.count(a[i]))
        dp[a[i]] = i + 1;
      else {
        ans += (n - i) * dp[a[i]];
        dp[a[i]] += (i + 1);
      }
    }

    cout << ans << endl;
  }

}
