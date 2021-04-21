#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> color;
vector<vector<int>> adj;
int n1; // # conn comps with same color.
vector<bool> used;
vector<int> comp;
vector<vector<int>> adj1; // graph on comps
vector<int> dp;           // depth of all nodes.
int diameter = 0;         // diameter of the clustered tree.

void dfs1(int v, int col, int cmp) {
  if (used[v])
    return;
  if (color[v] != col)
    return;

  used[v] = true;
  comp[v] = cmp;

  for (int u : adj[v])
    dfs1(u, col, cmp);
}

// p is parent
void dfs2(int v, int p = -1) {
  int mx1 = 0, mx2 = 0; // mx1 >= mx2, two largest depths.

  // works on the clustered graph
  for (int u : adj1[v]) {
    if (u == p)
      continue;
    dfs2(u, v);
    int val = dp[u] + 1;
    mx2 = max(val, mx2);
    if (mx1 < mx2)
      swap(mx1, mx2);
  }
  dp[v] = mx1;
  diameter = max(diameter, mx1 + mx2);
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> n;
  color.resize(n);
  adj.resize(n);
  comp.resize(n);
  used.assign(n, false);

  for (int i = 0; i < n; i++)
    cin >> color[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }

  // Build connected components.
  for (int i = 0; i < n; i++)
    if (!used[i])
      dfs1(i, color[i], n1++);

  //
  adj1.resize(n1);
  dp.resize(n1);
  for (int v = 0; v < n; v++)
    for (int u : adj[v])
      if (comp[u] != comp[v])
        adj1[comp[v]].push_back(comp[u]);

  dfs2(0);

  cout << (diameter + 1) / 2 << endl;
}
