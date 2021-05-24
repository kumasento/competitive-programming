/**
 * Author: kumasento
 * Date:   2021-05-24T16:29:03.000-05:00
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


constexpr LL MOD = 998244353;
constexpr int N = 1e6;


int lp[N + 1], np[N + 1];
vector<int> pr;

LL modpow(LL base, LL exp) {
  LL res = 1;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("D.in"); cin.rdbuf(in.rdbuf());
#endif

  fill(lp, lp + N + 1, 0);
  for (int i = 2; i <= N; i ++) {
    if (lp[i] == 0) {
      lp[i] = i; np[i] = 1;
      pr.push_back(i);
    }

    for (auto &p : pr) {
      if (p > lp[i] || i * p > N)
        break;
      lp[i * p] = p;
    }
  }

  int n; cin >> n;
  vector<LL> dp(n + 1);
  vector<LL> pre(n + 2, 0);

  dp[0] = dp[1] = 1;
  pre[0] = 0, pre[1] = 1, pre[2] = 2;

  vector<int> cnts;
  for (int i = 2; i <= n; i ++) {
    cnts.clear();

    int x = i;
    int p = lp[x];
    while (x > 1) {
      int cnt = 0;
      while (x % p == 0) {
        cnt ++;
        x /= p;
      }
      p = lp[x];
      cnts.push_back(cnt);
    }

    LL tot = 1;
    for (auto cnt : cnts)
      tot = (tot * ((cnt + 1LL) % MOD)) % MOD;

    dp[i] = tot - 1;
    dp[i] = (pre[i] + dp[i]) % MOD;
    pre[i+1] = (dp[i] + pre[i]) % MOD;
  }

  cout << dp[n] << endl;
}
