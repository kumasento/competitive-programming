#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, x;
  cin >> n >> m >> x;

  vector<LL> a(n);
  for (auto &i : a) cin >> i;

  vector adj(n, vector<pair<int, int>>{}); 
  for (int i = 0; i < m; i ++) {
    int u, v; cin >> u >> v;
    u --, v --;

    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  vector<int> ans;

  for (int i = 0; i < n; i ++) {
    vector<bool> used(n, false);
    priority_queue<int> pq;
    pq.push(i);

    LL sum = 0LL;
    while (!pq.empty()) {
      int u = pq.top(); pq.pop();
      sum += a[u];

      for (auto &to : adj[i]) {
        int v, id; tie(v, id) = to;

        if (used[v])
          continue;
        if (sum + a[v] >= x) 
          pq.push(v);
      }
    }
  }
}
