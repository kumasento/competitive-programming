#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL dp[4][3000005] = {0};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; LL k; cin >> n >> k;
  dp[0][0] = 1;

  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j <= i * n; j ++) {
      dp[i+1][j+1] += dp[i][j];
      dp[i+1][j+n+1] -= dp[i][j];
    }
    for (int j = 1; j <= (i + 1) * n; j ++)
      dp[i+1][j] += dp[i+1][j-1];
  }

  for (int j = 0; j <= 6; j ++) {
    for (int i = 0; i <= 3; i ++) {
      cout << setw(5) << dp[i][j] << " ";
    }
    cout << endl;
  }
}
