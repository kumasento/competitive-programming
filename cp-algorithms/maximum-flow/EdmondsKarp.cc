/**
 * Author: kumasento
 * Date:   2021-05-27T22:47:38.000-05:00
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
constexpr int INF = 1000000000;
constexpr LL LINF = 10000000000000000LL;
constexpr LL MOD = 1e9 + 7;

/// Globals:

/// Solution:

int n; 
vector<vector<int>> adj;
vector<vector<int>> capacity;

int bfs(int s, int t, vector<int> &parent) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;

  queue<pair<int, int>> q;
  q.push({s, INF}); // along the path what the min flow is.

  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;

    q.pop();

    for (int next : adj[cur]) {
      if (parent[next] == -1 && capacity[cur][next]) {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        if (next == t)
          return new_flow;
        q.push({next, new_flow});
      }
    }
  }

  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  vector<int> parent(n);
  int new_flow;

  while (new_flow = bfs(s, t, parent)) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }

  return flow;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("EdmondsKarp.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  cin >> n;
  adj.resize(n);
  capacity.assign(n, vector<int>(n, -1));

  int s, t; cin >> s >> t;
  int m; cin >> m;
  for (int i = 0; i < m; i ++) {
    int u, v, c; cin >> u >> v >> c;
    adj[u].push_back(v);

    capacity[u][v] = c;
    capacity[v][u] = 0;
  }

  cout << maxflow(0, 5) << endl;

}
