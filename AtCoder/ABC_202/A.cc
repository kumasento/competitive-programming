/**
 * Author: kumasento
 * Date:   2021-05-22T12:50:49.000-05:00
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

  int a, b, c; cin >> a >> b >> c;

  cout << 21 - (a + b + c) << endl;

}
