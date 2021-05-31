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
    a[i] = bitset<60>(s).to_ullong();
  }
  dbg(a);

  // randomly point to a friend.
  int iters = 50;

  LL bst = 0;
  while (iters --) {
    map<LL, int> freq, sfreq; 
    // the selected friend.
    int ind = ((double) rand() / RAND_MAX) * n;

    // now calculate the frequency of x & a[ind].
    for (LL x : a) freq[x & a[ind]] ++;

    // then submask frequency
    for (const auto &[msk, frq] : freq) 
      for (LL s = msk; s; s = (s - 1) & msk) 
        sfreq[s] += frq;

    // iterate every submask to find the final answer.
    for (const auto &[smk, frq]: sfreq) 
      if (frq >= thresh) 
        if (__builtin_popcountll(smk) > __builtin_popcountll(bst))
          bst = smk;
  } 

  for (int i = m-1; i >= 0; i --) {
    cout << ((bst>>i) & 1);
  }
  cout << '\n';
}
// hi1
