#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  int n, q, k;
  cin >> n >> q >> k;

  vector<int> a(n);
  for (auto &i : a) cin >> i;

  vector<LL> dp(n, 0);
  dp[0] = 1;
  for (int i = 1; i < n - 1; i ++)  
    dp[i] = dp[i - 1] + (a[i + 1] - a[i - 1] - 2);

  for (int i = 0; i < q; i ++) {
    int l, r; cin >> l >> r;
    l --, r --;

    if (l == r) {
      cout << k - 1 << endl;
      continue;
    }

    LL ans = (a[l + 1] - 2) + (k - a[r - 1] - 1) + (dp[r - 1] - dp[l]);
    cout << ans << endl;
  }
}
