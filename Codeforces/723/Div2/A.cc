/**
 * Author: kumasento
 * Date:   2021-05-28T15:01:20.000-05:00
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
constexpr int IINF = 1000000000;
constexpr LL LINF = 10000000000000000LL;
constexpr LL MOD = 1e9 + 7;

/// --------------------- Helpers:
#define DEBUG_VAR(x) { cout << #x << " = " << x << '\n'; }
#define DEBUG_VEC(vec) { for (auto i : (vec)) cout << i << " "; cout << '\n'; }

/// --------------------- Globals:

/// --------------------- Solution:



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("A.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  int t; cin >> t;

  while (t --) {
    int n; cin >> n;
    vector<int> a(2 * n); for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    vector<int> b(2 * n);
    for (int i = 0; i < n; i ++) b[2*i] = a[i];
    for (int i = 0; i < n; i ++) b[2*i + 1] = a[i + n];

    for (int i : b) cout << i << ' '; cout << '\n';
  }

}
