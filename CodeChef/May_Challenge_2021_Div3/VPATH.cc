/**
 * Author: kumasento
 * Date:   2021-05-12T19:33:33.000-05:00
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
int N; 
vector<vector<int>> adj;
vector<LL> h; 
LL sum;

/// ---------- Solution  ---------

void dfs(int u, int parent = -1) {
  h[u] = 1;
  
  LL s = 0LL;
  LL p = 0LL;
  vector<LL> ps;
  for (int v : adj[u]) {
    if (v != parent) {
      dfs(v, u);
      p = (p + ((h[v] * s) % MOD) * 2 % MOD) % MOD;
      s = (s + h[v]) % MOD;
    }
  }
  h[u] = (s * 2) % MOD + 1;
  
  sum = (sum + p) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);


  int T; cin >> T;
  while (T --) {
    cin >> N;

    adj.assign(N, vector<int>{});
    h.assign(N, 0);

    for (int i = 0; i < N - 1; i ++) {
      int u, v; cin >> u >> v; u --, v --;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    sum = 0;
    dfs(0);

    cout << ((h[0] + sum) % MOD) << endl; 
  }
}
