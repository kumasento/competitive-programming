/**
 * Author: kumasento
 * Date:   2021-05-12T18:07:32.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

constexpr LL MOD = 1000000007;

/// ---------- Globals   ---------

int N, X;
vector<vector<int>> adj;
vector<LL> h; // height of each node.
LL sum;

/// ---------- Solution  ---------

void dfs(int u, int p = -1) {
  h[u] = 1;

  priority_queue<LL> pq;
  for (int v : adj[u]) 
    if (v != p) {
      dfs(v, u);
      pq.push(h[v]);
    }
  
  int i = 1;
  while (!pq.empty()) {
    h[u] = (h[u] + (pq.top() * (i ++)));
    pq.pop();
  }
}

void bfs() {
  queue<PIL> q; 
  q.push({0, X});

  vector<bool> u(N, false);

  while (!q.empty()) {
    auto [to, val] = q.front(); q.pop();
    u[to] = true;

    sum = (sum + val) % MOD;

    sort(adj[to].begin(), adj[to].end(),
         [&](const int &a, const int &b) { return h[a] > h[b]; });

    int i = 1;
    for (int v : adj[to]) 
      if (!u[v])
        q.push({v, ((i ++) * val) % MOD});
  }
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);


  int T; cin >> T;
  while (T --) {

    cin >> N >> X;
    adj.assign(N, vector<int>{});
    h.assign(N, 0);

    for (int i = 0; i < N - 1; i ++) {
      int u, v; cin >> u >> v; u --, v --;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(0);

    sum = 0LL;
    bfs();

    cout << sum << endl;
  }
}
