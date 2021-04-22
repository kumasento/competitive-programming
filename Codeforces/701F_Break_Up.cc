// Reference: https://codeforces.com/contest/700/submission/19379508
// Result: https://codeforces.com/contest/700/submission/113867704

// Ref on bridge searching:
// https://cp-algorithms.com/graph/bridge-searching.html
#include <bits/stdc++.h>

using namespace std;

int n, m, s, t, cur, timer;
vector<vector<pair<int, int>>> adj;
vector<int> costs;

vector<bool> visited;
vector<int> path, br, tin, low, ans;

// Store edges from v to 'to' in a reversed order in path.
bool dfs1(int v, int to) {
  visited[v] = true;
  if (v == to)
    return true;
  for (auto e : adj[v]) {
    if (!visited[e.first] && dfs1(e.first, to)) {
      path.push_back(e.second);
      return true;
    }
  }
  return false;
}

// p is the edge ID we come from.
bool dfs2(int v, int to, int p = -1) {
  visited[v] = true;
  tin[v] = low[v] = timer++;
  bool res = v == to;

  for (auto e : adj[v]) {
    // skip the removed edge and the from edge.
    if (e.second == cur || e.second == p)
      continue;

    if (visited[e.first]) {
      low[v] = min(low[v], tin[e.first]);
    } else {
      // flag indicates whether we've found to in the following steps.
      bool flag = dfs2(e.first, to, e.second);
      res = res || flag;
      low[v] = min(low[v], low[e.first]);

      // Found a bridge and 'to' is visited.
      if (low[e.first] > tin[v] && flag)
        br.push_back(e.second);
    }
  }
  return res;
}

int main() {
  cin >> n >> m;
  adj.resize(n);
  costs.resize(m);
  visited.assign(n, false);
  tin.resize(n);
  low.resize(n);

  cin >> s >> t;
  s--, t--;
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;

    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
    costs[i] = c;
  }

  if (!dfs1(s, t)) {
    cout << 0 << endl;
    cout << 0 << endl;
    return 0;
  }

  int minCost = INT_MAX;
  // NOTE: we just need to search for one path. If there are more than 1:
  // 2 paths: we can deal with the other one during find bridges.
  // > 2 paths: cannot separate s and t in 2 steps anyway.
  for (int i : path) {
    cur = i;                  // the edge removed.
    timer = 0;                // reset timer.
    br.clear();               // bridges.
    visited.assign(n, false); // reset visited.

    if (!dfs2(s, t)) {
      // if breaking cur makes t not reacheable.
      if (minCost > costs[i]) {
        minCost = costs[i];
        ans = {i + 1};
      }
    }
    for (auto i2 : br) {
      if (minCost > costs[i] + costs[i2]) {
        minCost = costs[i] + costs[i2];
        ans = {i + 1, i2 + 1};
      }
    }
  }

  if (minCost == INT_MAX) {
    cout << -1 << endl;
    return 0;
  }

  cout << minCost << endl;
  cout << ans.size() << endl;
  copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}
