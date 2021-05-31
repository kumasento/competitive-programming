/**
 * Author: kumasento
 * Date:   2021-05-30T17:12:54
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

void print(const vector<int> &s) {
  for (int i = 0; i < s.size(); i ++)
    cout << s[i] << (i != s.size() - 1 ? '.' : ' ');

  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("C.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif


  int t; cin >> t;
  while (t --) {
    int n; cin >> n;
    vector<int> a(n); for (int &i : a) cin >> i;

    // try greedy
    vector<int> p; p.push_back(1);
    vector<int> m; m.push_back(1);

    print(p);

    for (int i = 1; i < n; i ++) {
      if (a[i] == 1) {
        p.push_back(1);
        m.push_back(1);
      } else {
        int d = a[i];
        while (d != m.back() + 1) {
          m.pop_back();
          p.pop_back();
        }
        m.back() ++;
        p.back() = d;
      }
      print(p);
    }
  }
}
