/**
 * Author: kumasento
 * Date:   2021-05-30T21:12:17
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

  int n, m, p;
  cin >> n >> m >> p;

  int thresh = ceil((double)n/2);

  vector<LL> a(n); 
  for (int i = 0; i < n; i ++) {
    string s; cin >> s;
    for (int j = m - 1; j >= 0; j --)
      if (s[m-j-1] == '1') a[i] |= (1LL << j); // 1LL!
  }

  int iters = 50; // Number of random trials
  LL bst = 0; // Best mask with the most 1's
  while (iters --) {
    // The selected friend.
    int ind = ((double) rand() / RAND_MAX) * n;

    // Compression map for a[ind].
    // The compression result has `bits` bits, and ord[i] is how to map 
    // the i-th bit in the compressed mask back to the original mask.
    int bits = 0; array<int, 17> ord; fill(ord.begin(), ord.end(), -1);
    for (int i = m - 1; i >= 0; i --) if ((a[ind]>>i) & 1) ord[bits++] = i;

    // Sum over superset.
    // https://codeforces.com/blog/entry/45223#comment-798359
    vector<int> A(1<<bits, 0), F(1<<bits, 0); 
    for (LL x : a) { // Get the compressed & between a[ind] and friends' mask `x`.
      int msk = 0;
      for (int i = 0; i < bits; i ++) 
        msk = (msk<<1) | (((a[ind] & x) >> ord[i]) & 1);
      A[msk] ++;
    }

    // F[msk] is the sum over all msk's supersets.
    for (int msk = 0; msk < (1<<bits); msk ++) 
      F[msk] = A[msk];
    for (int i = 0; i < bits; i ++) 
      for (int msk = 0; msk < (1<<bits); msk ++) 
        if (!(msk & (1<<i)))
          F[msk] += F[msk^(1<<i)];

    // Iterate every submask to find the final answer.
    // We should recover bst to the original bitset.
    for (int msk = 0; msk < (1<<bits); msk ++) 
      if (F[msk] >= thresh) 
        if (__builtin_popcount(msk) > __builtin_popcountll(bst)) {
          bst = 0;
          for (int i = bits - 1; i >= 0; i --) 
            if ((msk >> i) & 1) 
              bst = bst | (1LL<<ord[bits-i-1]); // 1LL!
        }
  } 

  for (int i = m-1; i >= 0; i --) cout << ((bst>>i) & 1); cout << '\n';
}
