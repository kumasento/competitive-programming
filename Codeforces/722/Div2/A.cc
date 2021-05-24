/**
 * Author: kumasento
 * Date:   2021-05-24T15:27:18.000-05:00
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

  int t; cin >> t;
  while (t --) {
    int n; cin >> n; 
    vector<int> a(n); for (int &i : a) cin >> i;

    sort(a.begin(), a.end());
    int i; for (i = 0; i < n; i ++) if (a[i] != a[0]) break;

    cout << (n - i) << endl;
  }

}
