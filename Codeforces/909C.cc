/**
 * Author: kumasento
 * Date:   2021-05-21T10:48:31.000-05:00
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

/// Solution:



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("909C.in"); cin.rdbuf(in.rdbuf());
#endif

  int N; cin >> N; vector<char> a(N); for (char &c : a) cin >> c;
  // the total number of for loops.
  int M = accumulate(a.begin(), a.end(), 1,
                     [](int x, char c) { return x + (c == 'f'); });

  vector dp(N + 1, vector<LL>(M + 1, 0));
  dp[N-1].assign(M + 1, 1);

  for (int i = N - 2; i >= 0; i --) {
    if (a[i] == 'f') {
      for (int j = 0; j < M; j ++)
        dp[i][j] = dp[i+1][j+1];
    } else {
      dp[i][0] = dp[i+1][0];
      for (int j = 0; j < M; j ++)
        dp[i][j+1] = (dp[i][j] + dp[i+1][j+1]) % MOD;
    }
  }

  cout << dp[0][0] << endl;

}
