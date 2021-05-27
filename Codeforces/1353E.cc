/**
 * Author: kumasento
 * Date:   2021-05-27T10:42:27.000-05:00
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
constexpr int IINF = 1000000000;
constexpr LL LINF = 10000000000000000LL;
constexpr LL MOD = 1e9 + 7;

/// Globals:

/// Solution:

constexpr int N = 1e6;
int dp[N + 1][2], ps[N + 1];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("1353E.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  int t; cin >> t;
  while (t --) {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    ps[0] = 0; for (int i = 0; i < n; i ++) ps[i+1] = ps[i] + (s[i] == '1');
    dp[0][0] = dp[0][1] = 0;
    for (int i = 0; i < n; i ++) {
      dp[i+1][0] = (s[i] == '1') + min(dp[i][0], dp[i][1]);
      dp[i+1][1] = (s[i] == '0') + min(ps[i], (i >= k ? (ps[i] - ps[i-k+1] + dp[i-k+1][1]) : INT_MAX));
    }

    cout << min(dp[n][0], dp[n][1]) << '\n';
  }

}
