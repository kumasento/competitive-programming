/**
 * Author: kumasento
 * Date:   2021-05-24T16:13:17.000-05:00
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

vector<vector<int>> adj;
vector<LL> l, r;
vector<array<LL, 2>> dp;

void dfs(int u, int p = -1) {
  dp[u] = {0, 0};
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);

      dp[u][0] += max(abs(l[u] - l[v]) + dp[v][0], abs(l[u] - r[v]) + dp[v][1]);
      dp[u][1] += max(abs(r[u] - l[v]) + dp[v][0], abs(r[u] - r[v]) + dp[v][1]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("C.in"); cin.rdbuf(in.rdbuf());
#endif

  int t; cin >> t;

  while (t --) {
    int n; cin >> n;
    adj.clear(); adj.resize(n);
    l.resize(n); r.resize(n);
    dp.clear(); dp.resize(n);

    for (int i = 0; i < n; i ++) cin >> l[i] >> r[i];
    for (int i = 0; i < n - 1; i ++) {
      int u, v; cin >> u >> v; u --, v --;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(0);

    cout << max(dp[0][0], dp[0][1]) << endl;
  }

}
