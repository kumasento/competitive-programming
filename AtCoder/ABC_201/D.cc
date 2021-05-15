/**
 * Author: kumasento
 * Date:   2021-05-15T12:54:05.000-05:00
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
int H, W;
int A[2001][2001];
int dp[2001][2001][2];
/// ---------- Solution  ---------


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> H >> W;
  for (int i = 0; i < H; i ++) {
    string S; cin >> S;
    for (int j = 0; j < W; j ++)
      A[i + 1][j + 1] = S[j] == '+' ? 1 : -1;
  }

  dp[H][W][0] = dp[H][W][1] = 0;
  for (int i = W - 1; i >= 1; i --) {
    dp[H][i][0] = A[H][i+1] + dp[H][i+1][1];
    dp[H][i][1] = - A[H][i+1] + dp[H][i+1][0];
  }
  for (int i = H - 1; i >= 1; i --) {
    dp[i][W][0] = A[i+1][W] + dp[i+1][W][1];
    dp[i][W][1] = - A[i+1][W] + dp[i+1][W][0];
  }

  for (int i = H - 1; i >= 1; i --) {
    for (int j = W - 1; j >= 1; j --) {
      dp[i][j][0] = max(dp[i][j+1][1] + A[i][j+1], dp[i+1][j][1] + A[i+1][j]);
      dp[i][j][1] = min(dp[i][j+1][0] - A[i][j+1], dp[i+1][j][0] - A[i+1][j]);
    }
  }

  // for (int i = 1; i <= H; i ++) {
  //   for (int j = 1; j <= W; j ++) {
  //     cout << "(" << dp[i][j][0] << ", " << dp[i][j][1] << ") ";
  //   }
  //   cout << endl;
  // }

  if (dp[1][1][0] > 0)
    cout << "Takahashi" << endl;
  else if (dp[1][1][0] == 0)
    cout << "Draw" << endl;
  else
    cout << "Aoki" << endl;
}
