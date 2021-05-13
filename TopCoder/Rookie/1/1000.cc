/**
 * Author: kumasento
 * Date:   2021-05-13T21:11:12.000-05:00
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

class OneForYou {
public:
  LL coinCount(LL N) {
    if (N <= 1)
      return 0;

    int k = 0;
    while ((LL) k * k + 3LL * k <= 2LL * N) 
      k ++;
    k --;

    LL M = N - ((LL) k * k + 3LL * k) / 2;

    return (1LL + k) * k / 2 + max(0LL, M - 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
