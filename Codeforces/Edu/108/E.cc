#include <bits/stdc++.h>

#define LL long long

using namespace std;

vector<vector<int>> adj;
vector<bool> used;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
  used[v] = true;
  tin[v] = low[v] = timer++;

  for (int to : adj[v]) {
    if (to == p)
      continue;

    if (used[u]) {
    }
  }
}

int main() {
  int n;
  cin >> n;
  map<pair<LL, LL>, set<int>> lines;

  for (int i = 0; i < n; i++) {
    LL a, b, c, d;
    cin >> a >> b >> c >> d;

    int x1 = (a + b) * d, y1 = b * c;
    int x2 = a * d, y2 = b * (c + d);

    lines[{x1, y1}].insert(i);
    lines[{x2, y2}].insert(i);
  }

  // maybe find all bridges first?

  adj.resize(n);
  used.assign(n, false);
  tin.assign(n, -1);
  low.assign(n, -1);
  timer = 0;

  for (auto &it : lines) {
    for (int v : it.second) {
      for (int u : it.second) {
        if (u != v) {
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
      }
    }
  }
}
