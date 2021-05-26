/**
 * Author: kumasento
 * Date:   2021-05-26T14:04:37.000-05:00
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

constexpr int N = 5000;

bool dp[N+1][N+1];
int pa[N+1][N+1];


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("245H.in"); cin.rdbuf(in.rdbuf());
#endif

  string s; cin >> s;

  int n = s.length();
  for (int i = 0; i < n; i ++) { dp[i][i] = 1; pa[i][i] = 1; dp[i+1][i] = 1; }
  
  for (int l = 2; l <= n; l ++) 
    for (int i = 0; i + l <= n; i ++) {
      dp[i][i+l-1] = (s[i] == s[i+l-1]) && dp[i+1][i+l-2];
      pa[i][i+l-1] = pa[i+1][i+l-1] + pa[i][i+l-2] - pa[i+1][i+l-2] + dp[i][i+l-1];
    }

  int q; cin >> q;
  while (q --) {
    int l, r; cin >> l >> r; l--, r--;

    cout << pa[l][r] << '\n';
  }

}
