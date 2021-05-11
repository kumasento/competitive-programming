/**
 * Author: kumasento 
 * Date:   2021-05-11T18:25:17.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, int>;

/// ---------- Constants ---------
constexpr LL INF = 10000000000000000LL;

/// ---------- Globals   ---------
vector<vector<PII>> adj;

/// ---------- Solution  ---------
void dijsktra(int s, vector<int> &d, vector<int> &p) {
  int n = adj.size();
  d.assign(n, INF);
  p.assign(n, -1);

  vector<bool> u(n, false);

  d[s] = 0;
  for (int i = 0; i < n; i ++) {
    int v = -1;
    for (int j = 0; j < n; j ++) 
      if (!u[j] && (v == -1 || d[j] < d[v]))
        v = j;

    if (v == -1)
      break;

    u[v] = true;

    for (auto [to, len] : adj[v]) {
      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        p[to] = v;
      }
    }
  }
}


void dijkstra_set(int s, vector<LL> &d, vector<int> &p) {
  int n = adj.size();
  d.assign(n, INF);
  p.assign(n, -1);
  
  d[s] = 0;
  set<PLI> q; q.insert({0, s});
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());

    for (auto [to, len] : adj[v]) {
      if (d[v] + len < d[to]) {
        q.erase({d[to], to});
        d[to] = d[v] + len;
        p[to] = v;
        q.insert({d[to], to});
      }
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m; cin >> n >> m;
  adj.resize(n);

  for (int i = 0; i < m; i ++) {
    int u, v, w; cin >> u >> v >> w;
    u --, v --;

    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  vector<LL> d; vector<int> p;
  dijkstra_set(0, d, p);

  vector<int> path;
  for (int v = n - 1; v != 0; v = p[v]) {
    if (v == -1) {
      cout << -1 << endl;
      return 0;
    }
    path.push_back(v);
  }
  path.push_back(0);

  reverse(path.begin(), path.end());
  for (int i : path)
    cout << i + 1 << " ";
  cout << endl;
}
