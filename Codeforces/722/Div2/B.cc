/**
 * Author: kumasento
 * Date:   2021-05-24T15:42:04.000-05:00
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
    vector<LL> a(n); for (LL &i : a) cin >> i;


    sort(a.begin(), a.end());

    LL md = -1;
    for (int i = 0; i < n - 1; i ++) {
      if (a[i] <= 0) {
        if (md == -1) md = a[i + 1] - a[i];
        else md = min(a[i+1] - a[i], md);
      }
    }


    int neg = 0, pos = 0, nz = 0;
    for (LL i : a) {
      if (i < 0) neg ++;
      else if (i == 0) nz ++;
      else pos ++;
    }

    if (md == -1) {
      // all numbers are positive
      cout << 1 << endl;
    } else if (md == 0) {
      // find all zeros
      cout << neg + nz << endl;
    } else {
      // md is larger than 0
      // use all zeros should be a good choice still
      if (nz >= 2) cout << neg + nz << endl;
      else {
        int ans = neg + nz;
        // find if there is a good positive number. 
        for (int i = 0; i < n; i ++) {
          if (a[i] > 0 && a[i] <= md) {
            ans ++;
            break;
          }
        }
        cout << ans << endl;
      }
    }
  }

}
