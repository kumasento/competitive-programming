/**
 * Author: kumasento
 * Date:   2021-06-01T21:40:33
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
  ifstream in("B.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  int A, B, W;
  cin >> A >> B >> W; 


  // it is a linear diophantine equation.
  // ax + by = W. A <= a, b <= B
  // but it is too hard to implement.


  // a yes-no question: if there are N oranges selected, then
  // AN <= 1000 W <= BN.
  // Then we just need to find this N.

  int mn = INT_MAX, mx = 0;
  for (int N = 1; N <= 1000 * W / A; N ++) 
    if (A * N <= 1000 * W && B * N >= 1000 * W) 
      mn = min(N, mn), mx = max(N, mx);

  if (mx == 0)
    cout << "UNSATISFIABLE\n";  
  else
    cout << mn << " " << mx << '\n';
}
