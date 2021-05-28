/**
 * Author: kumasento
 * Date:   2021-05-28T11:26:25.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// --------------------- Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// --------------------- Constants:
constexpr int IINF = 1000000000;
constexpr LL LINF = 10000000000000000LL;
constexpr LL MOD = 1e9 + 7;

/// --------------------- Helpers:
#define DEBUG_VAR(x) { cout << #x << " = " << x << '\n'; }
#define DEBUG_VEC(vec) { for (auto i : (vec)) cout << i << " "; cout << '\n'; }

/// --------------------- Globals:

/// --------------------- Solution:

int n, m, k;
vector<int>  w, u;
vector<vector<int>> adj;



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("1524A.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  int g; cin >> g;
  while (g --) {
    cin >> n; w.resize(n); for (int &i : w) cin >> i;
    cin >> k; u.resize(k); for (int &i : u) { cin >> i; i --; }
    cin >> m; adj.resize(m); for (int i = 0; i < m; i ++) {
      int u, v; cin >> u >> v; u --, v --;
      adj[u].push_back(v);
    }


    // The simplest solution: we mark every node, and assign each node to a region.
    set<int> U; for (int i = 0; i < n; i ++) U.insert(i);
    for (int &i : u) U.erase(i);

    cout << n - k << ' ';
    for (int k: U) cout << (k + 1) << ' ';
    cout << '\n';

    cout << n << '\n';
    for (int i = 0; i < n; i ++)
      cout << (i + 1) << ' ' << (i + 1) << '\n';
  }

}
