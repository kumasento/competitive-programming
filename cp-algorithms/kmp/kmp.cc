/**
 * Author: kumasento
 * Date:   2021-05-26T18:53:48.000-05:00
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

vector<int> prefix_function(string s) {
  int n = (int) s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; ++ i) {
    int j = pi[i-1];
    while (j > 0 && s[i] != s[j])
      j = pi[j-1];
    if (s[i] == s[j]) j ++;
    pi[i] = j;
  }
  return pi;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("kmp.in"); cin.rdbuf(in.rdbuf());
#endif


  vector<int> pi = prefix_function("abc#abcdabcabc");
  copy(pi.begin(), pi.end(), ostream_iterator<int>(cout, " ")); cout << '\n';




}
