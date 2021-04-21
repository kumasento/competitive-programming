#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, d;
  cin >> n >> k >> d;

  vector<vector<pair<int, int>>> G(n + 1);

  set<int> p;
  for (int i = 0; i < k; i++) {
    int t;
    cin >> t;
    p.insert(t);
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    G[u].push_back({v, i + 1});
    G[v].push_back({u, i + 1});
  }

  set<int> remove;

  queue<pair<int, int>> q;
  vector<bool> used(n + 1, false);

  for (int stn : p) {
    q.push({stn, 0});
    used[stn] = true;
  }

  while (!q.empty()) {
    int u, from;
    tie(u, from) = q.front();
    q.pop();

    for (int i = 0; i < G[u].size(); i++) {
      int v, id;
      tie(v, id) = G[u][i];
      if (from == v)
        continue;
      if (used[v]) {
        remove.insert(id);
        continue;
      }

      q.push({v, u});
      used[v] = true;
    }
  }

  cout << remove.size() << endl;
  copy(remove.begin(), remove.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}
