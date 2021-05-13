/**
 * Author: kumasento
 * Date:   2021-05-12T22:09:35.000-05:00
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
  int u, v, weight;
  bool operator<(Edge const &other) {
    return weight < other.weight;
  }
};

int n;
vector<Edge> edges;

int cost = 0;
vector<int> tree_id(n);
vector<Edge> result;

/// ---------- Solution  ---------


void kruskal() {
  for (int i = 0; i < n; i ++) 
    tree_id[i] = i;

  sort(edges.begin(), edges.end());

  for (Edge e : edges) {
    if (tree_id[e.u] != tree_id[e.v]) {
      cost += e.weight;
      result.push_back(e);

      int old_id = tree_id[e.u], new_id = tree_id[e.v];
      for (int i = 0; i < n; i ++)
        if (tree_id[i] == old_id)
          tree_id[i] = new_id;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
