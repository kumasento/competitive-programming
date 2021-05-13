/**
 * Author: kumasento
 * Date:   2021-05-12T22:54:08.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

constexpr LL MOD = 1000000000;

/// ---------- Globals   ---------

struct Edge {
  int u, v, w;
  bool operator<(Edge const &other) {
    return w < other.w;
  }
};

int n, m;
vector<Edge> edges;

vector<int> p, r;
LL cost;

void make_set(int v) {
  p[v] = v;
  r[v] = 1; // rank is set as size
}

int find_set(int v) {
  if (v == p[v])
    return p[v];
  return p[v] = find_set(p[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (r[a] < r[b])
      swap(a, b);
    p[b] = a;
    r[a] += r[b];
  }
}

/// ---------- Solution  ---------


void solve() {
  p.resize(n + 1);
  r.resize(n + 1);

  for (int i = 1; i <= n; i ++)
    make_set(i);

  sort(edges.begin(), edges.end());

  for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
      cost = (cost + (((r[e.u] * r[e.v]) % MOD) * e.w) % MOD) % MOD;

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

  cost = 0LL;
  solve();

  cout << cost << endl;
}
