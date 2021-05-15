/**
 * Author: kumasento
 * Date:   2021-05-15T12:54:05.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// ---------- Globals   ---------

/// ---------- Solution  ---------



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int N; cin >> N;
  vector<string> S(N);
  vector<int> T(N); 
  
  for (int i = 0; i < N; i ++) cin >> S[i] >> T[i];

  int idx = max_element(T.begin(), T.end()) - T.begin();

  int max_t = 0, max_i = -1;
  for (int i = 0; i < T.size(); i ++) {
    if (i != idx && max_t < T[i]) {
      max_t = T[i];
      max_i = i;
    }
  }

  cout << S[max_i] << endl;
}
