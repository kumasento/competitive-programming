/**
 * Author: kumasento
 * Date:   2021-05-22T11:15:06.000-05:00
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

constexpr LL MOD = 1e9 + 7;
constexpr int N = 1000000;

/// Solution:
LL dp[N + 1];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("1061C.in"); cin.rdbuf(in.rdbuf());
#endif
  int n; cin >> n;
  vector<int> a(n); for (int &i : a) cin >> i;

  // dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
  fill(dp, dp + N, 0);

  dp[0] = 1;
  dp[1] = 1;
  for (int i = 1; i < n; i ++) {
    vector<int> divs;
    for (int j = 1; (LL)j * j <= a[i]; j ++) {
      if (a[i] % j == 0) {
        divs.push_back(j);
        if (j != a[i] / j)
          divs.push_back(a[i] / j);
      }
    } 
    sort(divs.begin(), divs.end());
    reverse(divs.begin(), divs.end());

    for (int d : divs) 
      dp[d] = (dp[d] + dp[d - 1]) % MOD;
  }

  LL ans = 0;
  for (int i = 1; i <= n; i ++)
    ans = (ans + dp[i]) % MOD; 
  cout << ans << endl;
}
