/**
 * Author: kumasento
 * Date:   2021-05-20T16:42:23.000-05:00
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


int min(pair<int, int> p) { return min(p.first, p.second); }
int max(pair<int, int> p) { return max(p.first, p.second); }

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("B2.in"); cin.rdbuf(in.rdbuf());
#endif

  int t; cin >> t;
  while (t --) {

    int n; cin >> n;

    string s; cin >> s;

    int m = 0, k = 0;
    for (int i = 0, j = n - 1; i <= j; i ++, j --) {
      if (s[i] != s[j])
        k ++;
      else if (s[i] == '0') {
        if (i == j) m ++;
        else m += 2;
      }
    }

    vector dp(k + 1, array<pair<int, int>, 2>()); 
    // dp[i][j] the diff B - A
    if (m & 1) {
      if (m == 1) { 
        dp[0][0] = {-1, -1}, dp[0][1] = {1, 1};
      } else {
        dp[0][0] = {1, 1}, dp[0][1] = {-1, -1};
      }
    } else {
      dp[0][0] = {-2, -2}, dp[0][1] = {2, 2};
    }

    for (int i = 1; i <= k; i ++) {
      // not allowed to rotate
      dp[i][0].second = min(dp[i-1][1]) - 1;
      dp[i][1].second = max(dp[i-1][0]) + 1;
      // allowed to rotate
      dp[i][0].first = max(min(dp[i-1][1]) - 1, dp[i][1].second);
      dp[i][1].first = min(max(dp[i-1][1]) + 1, dp[i][0].second);
    }

    if (dp[k][0].first == 0)
      cout << "DRAW" << endl;
    else if (dp[k][0].first > 0)
      cout << "ALICE" << endl;
    else
      cout << "BOB" << endl;
  }
}
