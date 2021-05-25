/**
 * Author: kumasento
 * Date:   2021-05-24T10:44:27.000-05:00
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


constexpr int n = 100;
array<double, 3> dp[n+1][n+1][n+1];


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("540D.in"); cin.rdbuf(in.rdbuf());
#endif

  int r, s, p;
  cin >> r >> s >> p;

  for (int i = 1; i <= n; i ++)
    dp[i][0][0] = {1, 0, 0}, dp[0][i][0] = {0, 1, 0}, dp[0][0][i] = {0, 0, 1};

  for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++)
    dp[i][j][0] = {1, 0, 0}, dp[0][i][j] = {0, 1, 0}, dp[i][0][j] = {0, 0, 1};

  for (int m = 3; m <= 3 * n; m ++) {
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= n; j ++) {
        int k = m - i - j; if (k <= 0 || k > n) continue;
        int tot = i * j + j * k + i * k;
        dp[i][j][k] = {0, 0, 0};

        for (int d = 0; d < 3; d ++) {
          dp[i][j][k][d] += (double) i * k / tot * dp[i-1][j][k][d];
          dp[i][j][k][d] += (double) i * j / tot * dp[i][j-1][k][d];
          dp[i][j][k][d] += (double) j * k / tot * dp[i][j][k-1][d];
        }

        // if (i <= 2 && j <= 2 && k <= 2) {
        //   cout << i << " " << j << " " << k << " ";
        //   copy(dp[i][j][k].begin(), dp[i][j][k].end(), ostream_iterator<double>(cout, " "));
        //   cout << endl;
        // }
      }
    }
  }

  cout << setprecision(15) << dp[r][s][p][0] << " " << dp[r][s][p][1] << " " << dp[r][s][p][2] << endl;
}
