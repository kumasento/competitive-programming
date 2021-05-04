#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define MAXM 200001
#define MOD 1000000007

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;

  // a DP based solution.
  vector<LL> dp(MAXM + 1);
  for (int i = 0; i <= MAXM; i ++) 
    dp[i] = ((i >= 9 ? dp[i - 9] : 1) + (i >= 10 ? dp[i - 10] : 1)) % MOD;

  while (T --) {
    string S; LL m; cin >> S >> m;

    LL ans = 0;
    for (char d : S) {
      int k = m - (10 - (d - '0'));
      if (k < 0) ans = (ans + 1) % MOD;
      else ans = (ans + dp[k]) % MOD;
    }
    cout << ans << '\n';
  }
}
