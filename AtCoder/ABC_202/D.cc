/**
 * Author: kumasento
 * Date:   2021-05-22T13:14:13.000-05:00
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


constexpr int MAX = 30;
LL dp[MAX + 1][MAX + 1];

string find_kth(int A, int B, LL k) {
  if (A == 0) return string(B, 'b');
  if (B == 0) return string(A, 'a');
  if (k <= dp[A-1][B])
    return string("a") + find_kth(A-1, B, k);
  return string("b") + find_kth(A, B-1, k-dp[A-1][B]);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("D.in"); cin.rdbuf(in.rdbuf());
#endif

  int A, B; LL K; cin >> A >> B >> K;

  dp[0][0] = 1;
  for (int i = 0; i <= A; i ++)
    for (int j = 0; j <= B; j ++) {
      if (i >= 1) dp[i][j] += dp[i-1][j];
      if (j >= 1) dp[i][j] += dp[i][j-1];
    }

  cout << find_kth(A, B, K) << endl;
}
