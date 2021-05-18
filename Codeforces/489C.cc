/**
 * Author: kumasento
 * Date:   2021-05-18T12:22:06.000-05:00
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

int no() {
  cout << -1 << " " << -1 << endl;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int m, s; cin >> m >> s;

  if (m == 1 && s == 0) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }

  if (s == 0) return no();
  if (s > 9 * m) return no();


  int s1, s2; s1 = s2 = s;

  string mx;
  for (int i = 0; s1 > 0 && i < m; i ++) {
    int d = min(s1, 9);
    mx.push_back(d + '0');
    s1 -= d;
  } 
  mx += string(m - mx.length(), '0');

  string mn(m, '0'); mn[0] = '1';
  s2 --;
  for (int i = mn.length() - 1; s2 > 0 && i >= 0; i --) {
    int d = min(s2, 9 - (mn[i] - '0'));
    mn[i] += d;
    s2 -= d;
  }

  cout << mn << " " << mx << endl;
}
