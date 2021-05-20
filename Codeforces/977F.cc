/**
 * Author: kumasento
 * Date:   2021-05-20T09:28:00.000-05:00
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
  ifstream in("977F.in"); cin.rdbuf(in.rdbuf());
#endif

  int n; cin >> n;
  vector<int> a(n); for (int &i : a) cin >> i;

  map<int, int> dp; 
  int ans = 0, lst = 0;
  for (int i = 0; i < n; ++i) {
    if (dp.count(a[i]-1))
      dp[a[i]] = dp[a[i]-1] + 1;
    else
      dp[a[i]] = 1;
    
    if (ans < dp[a[i]]) {
      ans = dp[a[i]];
      lst = a[i];
    }
  }

  cout << ans << endl;
  vector<int> res;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == lst) {
      res.push_back(i + 1);
      -- lst;
    }
  }
  reverse(res.begin(), res.end());

  for (int i = 0; i < ans; ++i)
    cout << res[i] << " ";
  cout << endl;
}
