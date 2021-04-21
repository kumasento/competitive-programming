#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  vector<vector<int>> G(N + 1);

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  unordered_map<int, unordered_map<int, unordered_set<int>>> forbiddens;
  for (int i = 0; i < K; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    forbiddens[c][b].insert(a);
  }
}
