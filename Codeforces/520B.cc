/**
 * Author: kumasento
 * Date:   2021-05-18T20:24:52.000-05:00
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

  int n, m; cin >> n >> m;

  unordered_set<int> vis;
  queue<PII> q; q.push({n, 0});
  while (!q.empty()) {
    auto [k, d] = q.front(); q.pop();
    vis.insert(k);
    if (k == m) {
      cout << d << endl;
      return 0;
    }

    if (k < m && !vis.count(k * 2)) q.push({k * 2, d + 1});
    if (k > 1 && !vis.count(k - 1)) q.push({k - 1, d + 1});
  }

}
