/**
 * Author: kumasento
 * Date:   2021-05-11T19:04:22.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

struct edge {
  int a, b, cost;
};

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// ---------- Globals   ---------
int n, m, v;
vector<edge> e;

/// ---------- Solution  ---------

void solve() {
  vector<int> d(n, INT_INF);
  d[v] = 0;
  for (int i = 0; i < n - 1; i ++) {
    for (int j = 0; j < m; j ++)
      if (d[e[j].a] < INT_INF)
        d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].cost);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
