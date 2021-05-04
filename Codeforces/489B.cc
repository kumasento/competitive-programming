#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n;
  vector<int> a(n); for (int &i: a) cin >> i;
  cin >> m;
  vector<int> b(m); for (int &i: b) cin >> i;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      if (abs(a[i-1] - b[j-1]) <= 1)
        dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
    }
  }

  int bst = 0;
  for (int i = 0; i <= m; i ++)
    bst = max(bst, dp[n][i]);
  cout << bst << endl;
}
