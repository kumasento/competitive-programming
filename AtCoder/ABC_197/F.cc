#include <bits/stdc++.h>

#define LL long long

using namespace std;

int N, M; 
vector<vector<pair<int, char>>> adj;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  adj.resize(N);

  for (int i = 0; i < M; i ++) {
    int A, B; char C; cin >> A >> B >> C;
    A --, B --;
    adj[A].push_back({B, C});
    adj[B].push_back({A, C});
  }

  queue<tuple<int, int, int>> q;
  set<pair<int, int>> vis;
  q.push({0, N - 1, 0});
  vis.insert({0, N - 1});

  int bst = INT_MAX, bst_d = -1;
  while (!q.empty()) {
    int a, b, d; tie(a, b, d) = q.front(); q.pop();

    if (bst_d != -1 && d > bst_d)
      break;
    if (a == b) {
      bst_d = d, bst = 2 * d;
      break;
    }

    for (auto a_to : adj[a]) {
      if (a_to.first == b) {
        bst_d = d, bst = 2 * d + 1;
      }
      for (auto b_to : adj[b]) {
        // Two edges have the same character.
        if (a_to.second == b_to.second) {
          int u = a_to.first, v = b_to.first;
          if (vis.count({u, v}) || vis.count({v, u}))
            continue;

          vis.insert({u, v});
          q.push({u, v, d + 1});
        }
      }
    }
  }

  if (bst_d == -1)
    cout << -1 << endl;
  else
    cout << bst << endl;
}
