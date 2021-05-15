/**
 * Author: kumasento
 * Date:   2021-05-14T12:13:58.000-05:00
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

class PointsInAPlane {
public:
  int howManyTriangles(vector<int> x, vector<int> y) {
    int n = x.size();
    int ans = 0;
    for (int i = 0; i < n; i ++) {
      for (int j = i + 1; j < n; j ++) {
        for (int k = j + 1; k < n; k ++) {
          LL x1 = x[i] - x[j], x2 = x[i] - x[k];
          LL y1 = y[i] - y[j], y2 = y[i] - y[k];

          if (x1 * y2 == x2 * y1) 
            continue;

          ans ++;
        }
      }
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
