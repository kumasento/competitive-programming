/**
 * Author: kumasento
 * Date:   2021-05-14T11:57:42.000-05:00
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

class LongestPalindrome {
public:
  int longestLength(string s) {
    int n = s.length();
    int len = 0;
    for (int i = 0; i < n; i ++) {
      for (int j = i; j < n; j ++) {
        bool ok = true;
        for (int k = i, t = j; k <= t; k ++, t --) {
          if (s[k] != s[t]) {
            ok = false;
            break;
          }
        } 
        if (ok)
          len = max(j - i + 1, len);
      }
    }

    return len;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
