/**
 * Author: kumasento
 * Date:   2021-06-03T21:28:39
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
  ifstream in("C.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif


  int N; cin >> N;
  vector<LL> A(N); for (LL &i : A) cin >> i;

  // (i-1) A_i^2 + sum_{j=1}^{i-1} A_j^2 - 2 A_i (sum_{j=1}^{i-1} A_j)
  // (i-1) A_i^2 + pre1[i] - 2 A_i pre2[i]
  LL pre1 = A[0] * A[0], pre2 = A[0];

  LL ans = 0;
  for (int i = 1; i < N; i ++) {
    LL sq = A[i] * A[i];
    ans += i * sq + pre1 - 2 * A[i] * pre2;
    dbg(ans);
    pre1 += sq;
    pre2 += A[i];
  }
  cout << ans << '\n';
}
