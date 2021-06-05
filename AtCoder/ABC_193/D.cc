/**
 * Author: kumasento
 * Date:   2021-06-05T14:54:43
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

  int K; cin >> K;
  string S, T; cin >> S >> T;

  array<int, 9> cnts; fill(cnts.begin(), cnts.end(), K);

  auto score = [](string &s, int k) {
    array<int, 9> cnts{{0}}; fill(cnts.begin(), cnts.end(), 0);
    for (int i = 0; i < 4; i ++) cnts[s[i]-'1']++;
    cnts[k-1] ++;
    int sum = 0;
    for (int i = 1; i <= 9; i ++)
      sum += pow(10, cnts[i-1]) * i;

    return sum;
  };

  for (int i = 0; i < 4; i ++) cnts[S[i]-'1'] --;
  for (int i = 0; i < 4; i ++) cnts[T[i]-'1'] --;

  dbg(cnts);

  LL tot = 0, win = 0;
  for (int i = 1; i <= 9; i ++) {
    for (int j = 1; j <= 9; j ++) {
      if (i == j && cnts[i-1] < 2)
        continue;
      if (i != j && (cnts[i-1] < 1 || cnts[j-1] < 1))
        continue;

      LL a = cnts[i-1];
      LL b = i == j ? cnts[i-1] - 1 : cnts[j-1];
      tot += a * b; if (score(S, i) > score(T, j)) win += a * b;
    }
  }
  dbg(tot,win);

  cout << fixed << setprecision(20) << (double)win/tot << '\n';
}
