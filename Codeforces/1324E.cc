/**
 * Author: kumasento
 * Date:   2021-05-20T10:11:22.000-05:00
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
  ifstream in("1324E.in"); cin.rdbuf(in.rdbuf());
#endif

  int n, h, l, r; cin >> n >> h >> l >> r;
  vector<int> a(n); for (int &i : a) cin >> i;

  // dp[i][j]: max # of good; start from day i, wake up at j?
  // dp[i][j] = max(dp[i+1][(j+a[i]-1+h)%h]+{(j+a[i]) in [l,r]}, dp[i+1][(j+a[i]+h)%h]+{(j+a[i]-1) in [l,r]})
  // return dp[0][0];

  vector dp(n+1, vector<int>(h, 0));
  for (int i = n - 1; i >= 0; i --) {
    for (int j = 0; j < h; j ++) {
      int k1 = (j + a[i]) % h, k2 = (j + a[i] - 1) % h;
      dp[i][j] = max(dp[i+1][(k1+h)%h] + (k1 >= l && k1 <= r),
                     dp[i+1][(k2+h)%h] + (k2 >= l && k2 <= r));
    }
  }

  cout << dp[0][0] << endl;
}
