/**
 * Author: kumasento
 * Date:   2021-05-22T13:01:05.000-05:00
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
  ifstream in("B.in"); cin.rdbuf(in.rdbuf());
#endif


  string S; cin >> S;

  reverse(S.begin(), S.end());
  for (int i = 0; i < S.length(); i ++) {
    if (S[i] == '6') S[i] = '9';
    else if (S[i] == '9') S[i] = '6';
  }

  cout << S << endl;
}
