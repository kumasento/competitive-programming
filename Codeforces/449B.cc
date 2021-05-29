/**
 * Author: kumasento
 * Date:   2021-05-29T19:04:55
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
constexpr int INF = 1e9;
constexpr LL LINF = 1e16;
constexpr LL MOD = 1e9 + 7;

/// --------------------- Helpers:
// *** Credit to Neal Wu
// overload operator<<() for pairs.
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// overload container output. Won't affect strings.
template <typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream &operator<<(ostream &os, const C &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// variadic debugger.
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/// --------------------- Globals:

/// --------------------- Solution:

int n, m, k;
vector<vector<PIL>> adj;

void dijkstra(int s, vector<LL> &d, vector<int> &p) {
  d.assign(n, LINF);
  p.assign(n, 0); // p now calculates the in-degree of the shortest path graph.

  set<PLI> q;
  q.insert({0, s});
  d[0] = 0;

  while (!q.empty()) {
    LL dis; int u; tie(dis, u) = *q.begin();
    q.erase(q.begin());

    for (auto [v, len] : adj[u]) {
      if (d[u] + len < d[v]) {
        if (d[v] != LINF)
          q.erase({d[v], v});
        d[v] = d[u] + len;
        p[v] = 1;
        q.insert({d[v], v});
      } else if (d[u] + len == d[v]) {
        p[v] ++;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("449B.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif


  cin >> n >> m >> k;
  adj.resize(n);
  for (int i = 0; i < m; i ++) {
    int u, v; LL x; cin >> u >> v >> x; u --, v --;
    adj[u].push_back({v, x});
    adj[v].push_back({u, x});
  }

  vector<PIL> trains(k);
  for (int i = 0; i < k; i ++) {
    int s; LL y; cin >> s >> y; s--;
    adj[0].push_back({s, y});
    trains.push_back({s, y});
  }

  vector<LL> d;
  vector<int> p;
  dijkstra(0, d, p);

  dbg(d);

  int ans = 0;

  for (auto [s, y] : trains) {
    if (d[s] < y)
      ans ++;
    else if (d[s] == y) {
      if (p[s] > 1) {
        ans ++;
        p[s] --;
      }
    }
  }

  cout << ans << '\n';

}
