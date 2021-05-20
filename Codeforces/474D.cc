/**
 * Author: kumasento
 * Date:   2021-05-19T15:01:13.000-05:00
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
 
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
 
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
 
  int t, k; cin >> t >> k;
 
  vector<LL> dp(N + 1), ps(N + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= N; i ++) dp[i] = (dp[i-1] + (i >= k ? dp[i-k] : 0)) % MOD;
  for (int i = 1; i <= N; i ++) ps[i] = (ps[i-1] + dp[i]) % MOD;
 
  while (t --) {
    int a, b; cin >> a >> b;
    cout << (((ps[b] - ps[a-1]) % MOD + MOD) % MOD) << endl;
  }
}
