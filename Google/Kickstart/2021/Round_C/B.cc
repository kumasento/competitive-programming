/**
 * Author: kumasento
 * Date:   2021-05-23T12:31:15.000-05:00
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



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("B.in"); cin.rdbuf(in.rdbuf());
#endif

  int T; cin >> T;

  for (int t = 1; t <= T; t ++) {
    LL G; cin >> G;

    LL M = sqrt( 2LL * G);
    LL ans = 0;
    for (LL N = 1; N <= M; N ++) {
      LL d = 2LL * G - N * N;
      if (d > 0 && (d % N == 0) && ((d / N + 1) % 2 == 0)) 
        ans ++;
    }

    cout << "Case #" << t << ": " << ans << endl;
  }

}
