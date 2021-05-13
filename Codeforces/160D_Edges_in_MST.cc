/**
 * Author: kumasento
 * Date:   2021-05-12T22:17:40.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// ---------- Globals   ---------

struct Edge {
  int u, v, w;
  bool operator<(Edge const& other) {
    return w < other.w;
  }
};

int n, m;
vector<int> parent, ranks;
vector<Edge> edges;

/// ---------- Solution  ---------


void make_set(int v) {
  parent[v] = v;
  ranks[v] = 0;
}

int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (ranks[a] < ranks[b])
      swap(a, b);
    parent[b] = a;
    if (ranks[a] == ranks[b])
      ranks[a] ++;
  }
}

void solve() {
  parent.resize(n);
  ranks.resize(n);

  for (int i = 0; i < n; i ++)
    make_set(i);

  sort(edges.begin(), edges.end());

  for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
      union_sets(e.u, e.v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < m; i ++) {
    Edge e; cin >> e.u >> e.v >> e.w;
    edges.push_back(e);
  }

  solve();
}
