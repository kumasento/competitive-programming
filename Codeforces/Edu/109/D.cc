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

  int n; cin >> n;
  vector<int> a(n); for (int &i : a) cin >> i;
  vector<int> pos;
  for (int i = 0; i < n; i ++) if (a[i] == 1) pos.push_back(i);

  int k = pos.size();
  vector dp(n + 1, vector<int>(k + 1, INT_INF));
  dp[0][0] = 0;

  for (int i = 0; i < n; i ++) { // looking at (i+1)-th position.
    for (int j = 0; j <= k; j ++) { // j are picked as ending ones.
      // it is not possible for dp[i][j]
      if (dp[i][j] == INT_INF) continue;

      // if we don't move anything
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);

      if (j < k && a[i] == 0) {
        // i is an empty seat. we use i to resolve the j's problem
        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(pos[j]-i));
      }
    }
  }

  cout << dp[n][k] << endl;
} 
