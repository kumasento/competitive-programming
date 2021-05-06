#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;
  while (t --) {
    int n; cin >> n; vector<LL> a(n); for (LL &i: a) cin >> i;

    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i ++)
      pre[i + 1] = pre[i] ^ a[i];

    bool ok = !pre[n]; // the last two numbers should be the same.
    for (int i = 1; i <= n; i ++) {
      // pre[i] = a[0] ^ a[1] ^ ... ^ a[i - 1]
      for (int j = i + 1; j < n; j ++) {
        // pre[j] ^ pre[i] = a[i] ^ ... ^ a[j - 1];
        // pre[n] ^ pre[j] = a[j] ^ ... ^ a[n - 1];
        ok |= (pre[i] == (pre[j] ^ pre[i]) && pre[i] == (pre[n] ^ pre[j]));
      }
    }

    cout << (ok ? "YES" : "NO") << endl;
  }
}
