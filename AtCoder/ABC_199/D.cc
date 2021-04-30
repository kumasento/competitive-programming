#include <bits/stdc++.h>

#define LL long long

using namespace std;

vector<int> comp; // node id in the current component
vector<int> inds; // node id to component id
vector<int> pres; // previous node visited in DFS
vector<vector<int>> adj;
LL cur = 0LL;
vector<char> color;

// Build the comp, inds, and pres.
void dfs(int u) {
  comp.push_back(u);
  inds[u] = comp.size() - 1;
  for (int v : adj[u])
    if (inds[v] == -1) {
      pres[v] = u;
      dfs(v);
    }
}

// Coloring and checking.
void dfs2(int i) {
  if (i == (int)color.size()) {
    // examine
    // copy(color.begin(), color.end(), ostream_iterator<int>(cout, " "));
    // cout << endl;

    for (int u : comp)
      for (int v : adj[u])
        if (color[inds[u]] == color[inds[v]])
          return;
    cur++;
    return;
  }

  for (int c = 0; c < 3; c++) {
    if (i != 0) {
      // Compare with the parent node's color. Here we visit in the DFS order,
      // so we can be sure that the color of the parent nodes should be
      // determined already.
      int p = pres[comp[i]];
      int j = inds[p];
      if (color[j] == c)
        continue;
    }
    color[i] = c;
    dfs2(i + 1);
  }
}

int main() {
  int N, M;
  cin >> N >> M;

  // Build the graph
  adj.resize(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  inds.assign(N, -1);
  pres.assign(N, -1);

  LL ans = 1;

  // Iterate every connected component in the graph.
  for (int i = 0; i < N; i++) {
    if (inds[i] != -1)
      continue;

    comp.clear();
    color.clear();

    dfs(i);

    int m = comp.size();
    color.assign(m, -1);

    cur = 0LL;
    dfs2(0);
    ans *= cur;
  }

  cout << ans << endl;
}
