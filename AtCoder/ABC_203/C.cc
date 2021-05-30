/**
 * Author: kumasento
 * Date:   2021-05-30T13:03:51
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


  int N; LL K; cin >> N >> K;
  vector<PLL> A(N); for (auto &p : A) cin >> p.first >> p.second;
  sort(A.begin(), A.end());

  vector<PLL> B;
  for (auto p : A) { 
    if (!B.empty() && B.back().first == p.first)
      B.back().second += p.second;
    else
      B.push_back(p);
  }
  for (int i = (int) B.size() - 1; i > 0; i --)
    B[i].first -= B[i-1].first; 

  dbg(B);

  LL x = K;
  LL cnt = 0;
  for (int i = 0; i < (int)B.size(); i ++) {
    if (x >= B[i].first) {
      x -= B[i].first;
      x += B[i].second;
      cnt += B[i].first;
    } else {
      break;
    }
  }

  cnt += x;

  cout << cnt << endl;
}
