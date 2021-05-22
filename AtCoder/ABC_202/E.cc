/**
 * Author: kumasento
 * Date:   2021-05-22T13:24:20.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// Constants:
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// Globals:
vector<vector<int>> children, lst;
vector<int> tin, tout, depth;
int timer;

/// Solution:

void dfs(int u) {
  tin[u] = timer ++;
  lst[depth[u]].push_back(tin[u]);
  for (int v : children[u]) {
    depth[v] = depth[u] + 1;
    dfs(v);
  }
  tout[u] = timer ++;
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("E.in"); cin.rdbuf(in.rdbuf());
#endif

  int N; cin >> N;
  children.resize(N);
  lst.resize(N);
  tin.resize(N);
  tout.resize(N);
  depth.resize(N);

  for (int i = 1; i < N; ++ i) {
    int p; cin >> p;
    children[p - 1].push_back(i);
  }

  timer = 0;
  dfs(0);

  /// lst associates the depth with the in time of all nodes with that depth.

  int Q; cin >> Q;
  while (Q --) {
    int u, d; cin >> u >> d; u --;
    auto &v = lst[d];

    // Nodes enter time should be lower than tout[u], and >= tin[u].
    cout << (lower_bound(v.begin(), v.end(), tout[u]) -
             lower_bound(v.begin(), v.end(), tin[u])) << endl;
  }
}
