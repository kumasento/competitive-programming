#include <bits/stdc++.h>

using namespace std;

int dfs(int u, int from, int num, const int m, vector<vector<int>> &G,
        vector<int> &a) {

  if (a[u] == 0) {
    num = 0;
  } else {
    num++;
    if (num > m)
      return 0;
  }

  if (G[u].size() == 1 && G[u][0] == from)
    return 1;

  int sum = 0;
  for (int v : G[u]) {
    if (v != from) {
      sum += dfs(v, u, num, m, G, a);
    }
  }
  return sum;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<vector<int>> G(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<int> res;
  cout << dfs(1, 0, 0, m, G, a) << endl;
}
