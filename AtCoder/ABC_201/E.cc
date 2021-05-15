/**
 * Author: kumasento
 * Date:   2021-05-15T12:54:05.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using ULL = uint64_t;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// ---------- Globals   ---------
int N;
vector<vector<pair<int, ULL>>> adj;
vector<ULL> d;
vector<bool> vis;

/// ---------- Solution  ---------



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> N;
  adj.resize(N);
  d.assign(N, 0);
  vis.assign(N, false);

  for (int i = 0; i < N - 1; i ++) {
    int u, v; LL w;
    cin >> u >> v >> w;
    u --, v --;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    auto u = q.front(); q.pop();
    vis[u] = true;

    for (auto [v, w] : adj[u]) {
      if (!vis[v]) {
        d[v] = d[u] ^ w;
        q.push(v);
      }
    }
  }

  ULL ans = 0;
  constexpr ULL MOD = 1000000007;
  for (int i = 0; i < 60; i ++) {
    vector<int> cnt(2);
    for (int j = 0; j < N; j ++) cnt[d[j] >> i & 1] ++;
    ans += (1LL << i) % MOD * cnt[0] % MOD * cnt[1];
    ans %= MOD;
  }
  cout << ans << endl;
}
