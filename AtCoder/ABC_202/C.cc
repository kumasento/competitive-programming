/**
 * Author: kumasento
 * Date:   2021-05-22T13:03:10.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// Constants:
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// Globals:

/// Solution:



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("C.in"); cin.rdbuf(in.rdbuf());
#endif

  int N; cin >> N;

  vector<int> A(N), B(N), C(N);
  for (int &i : A) cin >> i;
  for (int &i : B) cin >> i;
  for (int &i : C) cin >> i;


  unordered_map<int, LL> ma, mb, mc;
  for (int i : A) ma[i] ++;
  for (int i : C) mc[i] ++;

  for (int i = 0; i < B.size(); i ++) {
    int k = B[i];
    mb[k] += mc[i + 1];
  }

  LL ans = 0;
  for (auto [k, v] : ma) 
    ans += ma[k] * mb[k];

  cout << ans << endl;
}
