/**
 * Author: kumasento
 * Date:   2021-05-20T14:42:06.000-05:00
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
  ifstream in("A.in"); cin.rdbuf(in.rdbuf());
#endif


  int t ; cin >> t;
  while (t --) {
    LL n; cin >> n;
    // get MSB
    int k = 0;
    while (n > 0) {
      n >>= 1;
      k ++;
    }
    cout << ((1 << (k - 1)) - 1) << endl;
  }

}
