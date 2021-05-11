#include <bits/stdc++.h>
using namespace std;
#define LL long long

// Declaring as global memory is the best: https://atcoder.jp/contests/abc200/submissions/22497862
// LL dp[4][3000005] = {0};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; LL k; cin >> n >> k;

  // LL dp[4][3000005] = {0};
  // Using vector is fine: https://atcoder.jp/contests/abc200/submissions/22497962
  vector dp(4, vector<LL>(3LL * n + 5, 0));

  dp[0][0] = 1;
  
  #if 0
  // A slower way of calculating dp[i][j] is:
  // Will give TLE: https://atcoder.jp/contests/abc200/submissions/22497898

  for (int i = 0; i < 3; i ++) {
    // O(N^2)
    for (int j = 0; j <= 3 * n; j ++) {
      for (int k = 1; k <= n; k ++) {
        dp[i + 1][j + k] += dp[i][j];
      }
    }
  }

  // first of all, we know dp[i][j] > 0 if j <= i * n;
  // next, dp[i][j] will be added to dp[i+1][j+1:j+n+1)
  // so we can basically use dp[i+1][j] as a prefix to dp[i+1][j+1]
  #else

  for (int i = 0; i < 3; i ++) {
    // O(N)
    for (int j = 0; j <= i * n; j ++) {
      dp[i+1][j+1] += dp[i][j];
      dp[i+1][j+n+1] -= dp[i][j]; // remove from accumulation.
    }
    // accumulate / prefix sum
    for (int j = 1; j <= (i + 1) * n; j ++)
      dp[i+1][j] += dp[i+1][j-1];
  }

  #endif
  // we accumulate the counts of sums until we reach k.
  // sum_{i=3}^{x} dp[3][i] <= k. we want to find x.
  int x;
  for (int i = 3; i <= 3 * n; i ++) {
    if (k <= dp[3][i]) { x = i; break; }
    else { k -= dp[3][i]; }
  }

  // finally, we can iterate the beauty of the cake
  for (int i = 1; i <= n; i ++) {
    // i is the beauty.
    // the maximum of the taste we can get is
    // x (the sum) - i (beauty) - n (pop).
    // the minimum is
    // x - i - 1.
    // we should constrain them between [1, n].
    int jmi = max(1, x - i - n), jma = min(n, x - i - 1);

    if (jmi > jma) continue; // in this case i is too small.
    if (k > (jma - jmi + 1)) {
      k -= (jma - jmi + 1); // these are the choices available for taste.
      continue;
    }

    int y = jmi + k - 1;
    int z = x - i - y;
    cout << i << ' ' << y << ' ' << z << '\n';
    return 0;
  }
}
