#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define MX (LL)2000000000

LL a[100005];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;

  while (t --) {
    int n; cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];

    int min_i = 0; LL min_a = a[0];
    for (int i = 1; i < n; i ++) {
      if (a[i] < min_a) {
        min_i = i;
        min_a = a[i];
      }
    }

    vector<tuple<int, int, LL, LL>> ans;
    for (int i = 0; i < n; i ++) {
      if (i == min_i) continue;
      if ((i < n - 1 && gcd(a[i], a[i + 1]) != 1) ||
          (i > 0 && gcd(a[i - 1], a[i]) != 1)) {
        LL k = min_a + 1LL;
        for (; k <= MX; k ++) {
          if ((i == n - 1 || gcd(k, a[i + 1]) == 1) &&
              (i == 0 || gcd(k, a[i - 1]) == 1))
            break;
        }

        a[i] = k;
        ans.emplace_back(i + 1, min_i + 1, k, min_a);
      }
    }

    cout << ans.size() << endl;
    for (auto [i, j, x, y] : ans) 
      cout << i << " " << j << " " << x << " " << y << endl;
  }
}
