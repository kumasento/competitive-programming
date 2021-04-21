#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

int fact(int n) {
  int ans = 1;
  for (int i = 1; i <= n; i++)
    ans = (1LL * ans * i) % MOD;
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    // first find the minimum value.
    int b1 = *min_element(a.begin(), a.end());
    int cnt = count(a.begin(), a.end(), b1);

    if (cnt < 2)
      cout << 0 << endl;
    else {
      bool supermask = true;
      for (int x : a) {
        if ((x & b1) != b1) {
          supermask = false;
          break;
        }
      }

      if (supermask) {
        int ans = (1LL * cnt * (cnt - 1)) % MOD;
        ans = (1LL * ans * fact(n - 2)) % MOD;
        cout << ans << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
}
