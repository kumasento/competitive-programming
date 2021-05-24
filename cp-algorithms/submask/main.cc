/**
 * Author: kumasento
 * Date:   2021-05-24T10:17:36.000-05:00
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
  ifstream in("main.in"); cin.rdbuf(in.rdbuf());
#endif

  int mask = 13;
  for (int s = mask; s; s=(s-1)&mask) {
    cout << bitset<8>(s) << endl;
  }

  int n = 4;
  for (int m = 0; m < (1<<n); ++ m) {
    cout << "Mask: " << bitset<6>(m) << endl;
    cout << "Submasks: " << endl;
    for (int s = m; s; s=(s-1)&m) {
      cout << bitset<6>(s) << endl;
    }
  }

}
