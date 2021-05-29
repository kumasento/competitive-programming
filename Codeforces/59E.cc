/**
 * Author: kumasento
 * Date:   2021-05-29T17:37:37
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

int m, n, k;
vector<vector<int>> adj;
set<tuple<int, int, int>> no;

void dijsktra(int s, vector<vector<int>> &d, vector<vector<int>> &p) {
  d.assign(n, vector<int>(n, INF));
  p.assign(n, vector<int>(n, -1));

  d[s][s] = 0;
  set<tuple<int, int, int>> q; // {d, u, v};
  q.insert({0, s, s});

  while (!q.empty()) {
    // this shortest path goes from v to u
    int dis, u, v; tie(dis, u, v) = *q.begin();
    q.erase(q.begin());

    for (auto t : adj[u]) {
      if (!no.count({v, u, t}) && d[v][u] + 1 < d[u][t]) {
        d[u][t] = d[v][u] + 1;
        p[u][t] = v;
        dbg(u, t, d[u][t]);
        q.insert({d[u][t], t, u});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("59E.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif


  cin >> n >> m >> k;
  adj.resize(n);
  for (int i = 0; i < m; i ++) {
    int u, v; cin >> u >> v; u --, v --;
    adj[u].push_back(v);
    adj[v].push_back(u);
  } 

  for (int i = 0; i < k; i ++) {
    int a, b, c; cin >> a >> b >> c; a--, b--, c --;
    no.insert({a, b, c});
  }

  vector<vector<int>> d, p;
  dijsktra(0, d, p);

  dbg(d);
  dbg(p);

  int mn = INF, prev;
  for (int i = 0; i < n; i ++) 
    if (d[i][n-1] < mn) {
      mn = d[i][n-1];
      prev = i;
    }

  if (mn == INF) {
    cout << -1 << '\n';
    return 0;
  }

  vector<int> path;
  int x = prev, y = n - 1;
  while (x != -1 && y != -1) {
    dbg(x, y);
    path.push_back(y);
    int tmp = p[x][y];
    y = x;
    x = tmp;
  }

  reverse(path.begin(), path.end());
  cout << mn << '\n'; for (int i : path) cout << i + 1 << ' '; cout << '\n';
}
