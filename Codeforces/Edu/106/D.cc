/**
 * Author: kumasento
 * Date:   2021-06-01T15:07:31
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

constexpr int N = 2e7 + 13;
array<int, N> mind, val;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("D.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  fill(mind.begin(), mind.end(), -1);
  mind[1] = 1; // mind[i] - minimum prime divisor of i

  // O(N log log N) to calculate the mind.
  for (int i = 2; i < N; ++ i) if (mind[i] == -1)
    for (int j = i; j < N; j += i) if (mind[j] == -1)
      mind[j] = i;
  
  // val[i] - the number of prime divisors of i
  for (int i = 2; i < N; i ++) {
    int j = i / mind[i];
    val[i] = val[j] + (mind[i] != mind[j]); // add 1 only when you changed mind[i].
  }

  int t; cin >> t;

  while (t --) {
    int c, d, x; cin >> c >> d >> x;
    int ans = 0;

    // O(sqrt(x)) - iterate every divisor of x.
    for (int i = 1; i * i <= x; ++ i) {
      // i and x/i are two x's divisors.
      if (x % i != 0) continue;
      int k1 = x / i + d; // i is gcd(a, b).
      if (k1 % c == 0) ans += 1 << val[k1/c]; // val[k1/c] number of prime factors of A * B.
      if (i * i == x) continue;
      int k2 = i + d;
      if (k2 % c == 0) ans += 1 << val[k2/c];
    }

    cout << ans << '\n';
  }
}
