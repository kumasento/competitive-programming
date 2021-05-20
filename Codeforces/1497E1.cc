/**
 * Author: kumasento
 * Date:   2021-05-19T13:47:01.000-05:00
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

const int N = 1e7;
int lp[N + 1];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  fill(lp, lp + N + 1, 0);
  vector<int> pr;

  for (int i = 2; i <= N; i ++) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++ j)
      lp[i * pr[j]] = pr[j];
  }


  int t; cin >> t;
  while (t --) {
    int n, k; cin >> n >> k;
    vector<int> a(n, 1);

    for (int i = 0; i < n; i ++) {
      int x; cin >> x;
      // cout << x << " -> ";
      int cnt = 0, last = 0;
      while (x > 1) {
        int p = lp[x];
        // cout << p << ", ";
        if (last == p)
          ++ cnt;
        else {
          if (cnt & 1) a[i] *= last;
          last = p;
          cnt = 1;
        }
        x /= p;
      }
      if (cnt & 1) a[i] *= last;

      // cout  << a[i] << endl;
    }


    // now every a[i] is p_k^q_k where q_k = 1 or 0.
    // if a[i] == a[j], then their original values being multiplied together will create a perfect square.
    // so any a[i] == a[j] pairs shouldn't be in the same segment.

    int L = 0, ans = 1;
    map<int, int> last; // last appearence of a[i].
    for (int i = 0; i < n; i ++) {
      // check if a[i] has appeared in the current segment (right to L, inclusive).
      if (last.find(a[i]) != last.end() && last[a[i]] >= L) {
        ++ans;
        L = i;
      }
      last[a[i]] = i;
    }

    cout << ans << endl;
  }
}
