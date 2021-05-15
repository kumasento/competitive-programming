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

/// ---------- Solution  ---------

int fac(int n) {
  int res = 1;
  for (int i = 1; i <= n; i ++) res *= i;
  return res;
}

int C(int n, int k) { return fac(n) / (fac(k) * fac(n - k)); }

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  string S; cin >> S;

  vector<bool> mask(10, false);
  for (int i = 0; i < 10; i ++) if (S[i] == 'o') mask[i] = true;

  int ans = 0;
  for (int a = 0; a < 10; a ++)
    for (int b = 0; b < 10; b ++)
      for (int c = 0; c < 10; c ++)
        for (int d = 0; d < 10; d ++) {
          if (S[a] == 'x' || S[b] == 'x' || S[c] == 'x' || S[d] == 'x')
            continue;
          
          vector<bool> mask2(10, false);
          mask2[a] = true;
          mask2[b] = true;
          mask2[c] = true;
          mask2[d] = true;

          bool ok = true;
          for (int i = 0; i < 10; i ++)
            if (mask[i] && !mask2[i])
              ok = false;

          if (!ok)
            continue;
          ans ++;
        }
  cout << ans << endl; 
}
