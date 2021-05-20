/**
 * Author: kumasento
 * Date:   2021-05-20T15:46:12.000-05:00
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

  int t; cin >> t;
  while (t --) {
    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0, cnt2 = 0;
    for (int i = 0, j = n - 1; i <= j; ++i, --j) {
      if (s[i] == '0') {
        cnt ++;
        if (i != j) cnt2 += 2;
        else cnt2 ++;
      }
    }

    if ((cnt2 & 1) && (cnt2 > 1)) {
      cout << "ALICE" << endl;
    } else { 
      cout << "BOB" << endl;
    }

  }

}
