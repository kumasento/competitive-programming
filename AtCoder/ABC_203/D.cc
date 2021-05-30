/**
 * Author: kumasento
 * Date:   2021-05-30T13:29:41
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


void insert(multiset<int, greater<int>> &S, multiset<int>::iterator &it, int val) {
  S.insert(val);

  if (S.size() % 2 == 0 && val <= *it)
    advance(it, 1);
  else if (S.size() % 2 == 1 && val >= *it)
    advance(it, -1);
}

void erase(multiset<int, greater<int>> &S, multiset<int>::iterator &it, int val) {
  if (S.size() % 2 == 0 && val <= *it)
    advance(it, -1);
  else if (S.size() % 2 == 1 && val >= *it)
    advance(it, 1);

  S.erase(S.find(val));
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("D.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif


  int N, K; cin >> N >> K;
  vector A(N, vector<int>(N)); for (int i = 0; i < N; i ++) for (int j = 0; j < N; j ++) cin >> A[i][j];

  vector S(N + 1, vector<int>(N + 1, 0));

  constexpr int MAX_A = 1e9 + 1;
  int hi = MAX_A, lo = -1;
  while ((lo + 1) < hi) {
    int mid = (lo + hi) / 2;

    for (int i = 0; i < N; i ++) {
      for (int j = 0; j < N; j ++) {
        S[i+1][j+1] = S[i+1][j] + S[i][j+1] - S[i][j];
        if (A[i][j] > mid)
          S[i+1][j+1] ++;
      }
    }
    
    bool ok = false;

    for (int i = 0; i <= N - K; i ++) {
      for (int j = 0; j <= N - K; j ++) {
        int num = S[i+K][j+K] - S[i][j+K] - S[i+K][j] + S[i][j];
        dbg(i, j, num);
        if (num < K * K / 2 + 1)
          ok = true;
      }
    }

    if (ok) hi = mid; 
    else lo = mid;
  }

  cout << hi << endl;
}
