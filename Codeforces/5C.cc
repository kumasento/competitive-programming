/**
 * Author: kumasento
 * Date:   2021-05-23T16:41:04.000-05:00
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


void no() {
  cout << 0 << " " << 1 << endl;
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("5C.in"); cin.rdbuf(in.rdbuf());
#endif

  string s; cin >> s;
  int n = s.length();

  stack<int> st;
  vector<int> dp(n + 1, -1);

  for (int i = 0; i < n; i ++) {
    if (s[i] == '(') st.push(i);
    else {
      if (!st.empty()) {
        int j = st.top(); st.pop();
        dp[i] = j; 
        if (j > 0 && dp[j - 1] != -1)
          dp[i] = dp[j - 1];
      }
    }
  }

  map<int, int> cnt;
  for (int i = 0; i < n; i ++) 
    if (dp[i] != -1) 
      cnt[i - dp[i] + 1] ++;

  if (cnt.empty())
    no();
  cout << cnt.rbegin()->first << " " << cnt.rbegin()->second << endl;
}
