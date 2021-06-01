/**
 * Author: kumasento
 * Date:   2021-06-01T21:05:54
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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("D.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif


  int N, M, Q; cin >> N >> M >> Q;
  vector<int> W(N), V(N); for (int i = 0; i < N; i ++) cin >> W[i] >> V[i];
  vector<int> X(M); for (int &x: X) cin >> x;
  vector<int> ord(M); for (int i = 0; i < M; i ++) ord[i] = i;
  sort(ord.begin(), ord.end(), [&](int a, int b) { return X[a] < X[b]; });

  while (Q --) {
    int L, R; cin >> L >> R;

    int ans = 0; vector<bool> vis(N, false);
    for (int i = 0; i < M; i ++) {
      if (ord[i] <= R-1 && ord[i] >= L-1) continue;
      int x = X[ord[i]]; 
      int bst = 0, bst_i = -1;
      for (int j = 0; j < N; j ++) 
        if (!vis[j] && bst < V[j] && x >= W[j]) 
          bst = V[j], bst_i = j;
      if (bst_i != -1) vis[bst_i] = true;
      ans += bst;
    }

    cout << ans << '\n';
  }
}
