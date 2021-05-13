/**
 * Author: kumasento
 * Date:   2021-05-12T21:24:03.000-05:00
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
  int w = INT_INF, to = -1;

  bool operator<(Edge const &other) const {
    return make_pair(w, to) < make_pair(other.w, other.to);
  }
};

int n;
vector<vector<Edge>> adj;

/// ---------- Solution  ---------

void prim() {
  int total_weight = 0;
  vector<Edge> min_e(n);
  min_e[0].w = 0;

  set<Edge> q;
  q.insert({0, 0});

  vector<bool> selected(n, false);

  for (int i = 0; i < n; ++ i) {
    if (q.empty()) {
      cout << "NO MST!" << endl;
      exit(0);
    }

    int v = q.begin()->to;
    selected[v] = true;
    total_weight += q.begin()->w;
    q.erase(q.begin());

    if (min_e[v].to != -1)
      cout << v << " " << min_e[v].to << endl;

    for (Edge e : adj[v]) {
      if (!selected[e.to] && e.w < min_e[e.to].w) {
        q.erase({min_e[e.to].w, e.to});
        min_e[e.to] = {e.w, v};
        q.insert({e.w, e.to});
      }
    }
  }

  cout << total_weight << endl;

}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
