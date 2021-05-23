/**
 * Author: kumasento
 * Date:   2021-05-23T12:41:57.000-05:00
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
  ifstream in("C.in"); cin.rdbuf(in.rdbuf());
#endif

  int T, X; cin >> T >> X;
  int N = 60;

  for (int t = 1; t <= T; t ++) {
    int W, E; cin >> W >> E;

    string ans;

    double bst = 0; array<int, 3> idx;
    for (int n = 1; n <= N - 2; n ++)
      for (int m = 1; m <= N - n - 1; m ++) 
        for (int k = 1; k <= N - n - m; k ++) {
          int l = n + m + k;
          if (l > N) continue;
          double sum = 0; array<double, 3> pr; // {R, S, P}
          pr[0] = pr[1] = pr[2] = 1./3;
          int r, s, p; r = s = p = 0;
          for (int i = 0; i < 60; i ++) {
            int t = i % l;
            if (t <= n) { // R
              r ++; sum += pr[1] * W + pr[0] * E;
            } else if (t <= m) { // S
              s ++; sum += pr[2] * W + pr[1] * E;
            } else { // P
              p ++; sum += pr[0] * W + pr[2] * E;
            }
            pr[0] = (double)s / (i + 1), pr[1] = (double) p/(i + 1), pr[2] = (double)r / (i + 1);
          }

          if (sum > bst) {
            bst = sum;
            idx = {n, m, k};
          }
        }

    auto [n, m, k] = idx;
    int l = n + m + k;
    for (int i = 0; i < 60; i ++) {
      int t = i % l;
      if (t <= n) { // R
        ans.push_back('R');
      } else if (t <= m) { // S
        ans.push_back('S');
      } else { // P
        ans.push_back('P');
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
  }

}
