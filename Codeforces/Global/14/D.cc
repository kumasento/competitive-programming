#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while (t --) {
    int n, l, r; cin >> n >> l >> r;

    vector<int> c(n);
    for (auto &i : c) cin >> i;

    // color frequencies
    vector<int> f1(n + 1, 0), f2(n + 1, 0);
    for (int i = 0; i < n; i ++) {
      if (i < l) f1[c[i]] ++;
      else f2[c[i]] ++;
    }

    if (l > r) { swap(l, r); swap(f1, f2); }

    for (int i = 1; i <= n; i ++) {
      int k = min(f1[i], f2[i]);
      f1[i] -= k, f2[i] -= k;
      l -= k, r -= k;
    }

    int cost = 0;
    for (int i = 1; r > l && i <= n; i ++) {
      int k = f2[i] / 2;
      int d = min((r - l) / 2, k);
      f2[i] -= d * 2;
      r -= d * 2;
      cost += d;
    }

    // R to L
    // cout << l << " " << r << endl;
    cost += (r - l) / 2;
    l += (r - l) / 2;
    cost += l;

    cout << cost << endl;
  }

}
