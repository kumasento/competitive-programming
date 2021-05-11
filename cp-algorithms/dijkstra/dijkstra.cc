/**
 * Author: kumasento
 * Date:   2021-05-11T18:40:40.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>;

/// ---------- Constants ---------
constexpr int INF = 1000000000;

/// ---------- Globals   ---------

vector<vector<pair<int, int>>> adj;

/// ---------- Solution  ---------

void dijkstra(int s, vector<int> &d, vector<int> &p) {
  int n = adj.size();
  d.assign(n, INF);
  p.assign(n, -1);
  vector<bool> u(n, false); // visited.

  d[s] = 0;
  for (int i = 0; i < n; i ++) {
    int v = -1;
    for (int j = 0; j < n; j ++) 
      if (!u[j] && (v == -1 || d[j] < d[v]))
        v = j;

    if (d[v] == INF) // not reachable
      break;

    u[v] = true;
    for (auto edge : adj[v]) {
      auto [to, len] = edge;
      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        p[to] = v;
      }
    }
  }

}

vector<int> restore_path(int s, int t, vector<int> const &p) {
  vector<int> path;
  for (int v = t; v != s; v = p[v]) 
    path.push_back(v);
  path.push_back(s);

  reverse(path.begin(), path.end());
  return path;
}


void dijkstra_set(int s, vector<int> &d, vector<int> &p) {
  int n = adj.size();
  d.assign(n, INF);
  p.assign(n, -1);
  
  d[s] = 0;
  set<PII> q; q.insert({0, s});
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

}
