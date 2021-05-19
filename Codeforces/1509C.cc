/**
 * Author: kumasento
 * Date:   2021-05-19T10:39:46.000-05:00
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

  int n; cin >> n;
  vector<LL> s(n); for (LL &i : s) cin >> i;
  sort(s.begin(), s.end());

  vector dp(n + 1, vector<LL>(n + 1, 0));
  for (int len = 2; len <= n; len ++) {
    for (int i = 0; i <= n - len; i ++) {
      int j = i + len - 1;
      dp[i][j] = s[j] - s[i] + min(dp[i][j-1], dp[i+1][j]);
    }
  } 

  cout << dp[0][n-1] << endl;
}
