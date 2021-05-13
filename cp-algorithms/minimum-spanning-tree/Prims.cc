/**
 * Author: kumasento
 * Date:   2021-05-12T20:51:58.000-05:00
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
int n;
vector<vector<int>> adj; // stores weights of the edges.


/// ---------- Solution  ---------


struct Edge {
  int w = INT_INF, to = -1;
};

void prim() {
  int total_weight = 0;
  vector<bool> selected(n, false);
  vector<Edge> min_e(n);
  min_e[0].w = 0;

  for (int i = 0; i < n; ++ i) {
    int v = -1;
    for (int j = 0; j < n; j ++) {
      if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
        v = j;
    }

    if (min_e[v].w == INT_INF) {
      cout << "NO MST!" << endl;
      exit(0);
    }

    selected[v] = true;
    total_weight += min_e[v].w;

    for (int to = 0; to < n; to ++) {
      if (adj[v][to] < min_e[to].w)
        min_e[to] = {adj[v][to], v};
    }

  }

  cout << total_weight << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
