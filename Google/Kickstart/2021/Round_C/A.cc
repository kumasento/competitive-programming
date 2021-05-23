/**
 * Author: kumasento
 * Date:   2021-05-23T11:44:31.000-05:00
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
constexpr LL MOD = 1e9 + 7;


LL modpow(LL b, LL e) {
  LL r = 1LL;
  while (e > 0) {
    if (e & 1) r = (r * b) % MOD;
    b = (b * b) % MOD;
    e >>= 1;
  }
  return r;
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("A.in"); cin.rdbuf(in.rdbuf());
#endif

  int T; cin >> T;
  for (int t = 0; t < T; t ++) {
    int N, K; cin >> N >> K;
    string S; cin >> S;

    int M = (N % 2 == 0) ? N / 2 : (N / 2 + 1);
    string A = S.substr(0, M), B = S.substr(N - M);

    LL ans = 0;
    for (int i = 0; i < M; i ++) 
      ans = (ans + ((LL)(S[i] - 'a') * modpow(K, M - i - 1)) % MOD) % MOD;

    reverse(A.begin(), A.end());
    if (A < B)
      ans = (ans + 1) % MOD;

    cout << "Case #" << (t + 1) << ": " << ans << endl;
  }


}
