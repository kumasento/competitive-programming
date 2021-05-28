/**
 * Author: kumasento
 * Date:   2021-05-28T15:14:40.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// --------------------- Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// --------------------- Constants:
constexpr int IINF = 1000000000;
constexpr LL LINF = 10000000000000000LL;
constexpr LL MOD = 1e9 + 7;

/// --------------------- Helpers:
#define DEBUG_VAR(x) { cout << #x << " = " << x << '\n'; }
#define DEBUG_VEC(vec) { for (auto i : (vec)) cout << i << " "; cout << '\n'; }

/// --------------------- Globals:

/// --------------------- Solution:

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("B.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  int t; cin >> t;
  while (t --) {
    int x; cin >> x;

    bool ok = false;
    for (int a = 0; (LL)a * 111 <= x; a ++) {
      int y = x - a * 111;
      if (y % 11 == 0) {
        ok = true;
        break;
      }
    }

    if (ok) cout << "YES\n"; else cout << "NO\n";
  }

}
