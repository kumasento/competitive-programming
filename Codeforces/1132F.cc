/**
 * Author: kumasento
 * Date:   2021-05-31T10:57:16
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
  ifstream in("1132F.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  int n; cin >> n;

  string s; cin >> s;

  vector dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; i ++) dp[i][i+1] = 1;
  for (int len = 2; len <= n; len ++) {
    for (int i = 0; i < n - len + 1; i ++) {
      int j = i + len;
      dp[i][j] = 1 + dp[i+1][j];
      for (int k = i + 1; k < j; k ++) 
        if (s[i] == s[k])
          dp[i][j] = min(dp[i+1][k] + dp[k][j], dp[i][j]);
    }
  }

  cout << dp[0][n] << '\n';
}
