#include <bits/stdc++.h>

using namespace std;

#define LL long long

int main() {
  int T;
  cin >> T;
  while (T--) {
    LL n;
    cin >> n;

    if (n % 2050) {
      cout << -1 << endl;
      continue;
    }

    LL m = n / 2050;
    int ans = 0;
    while (m > 0) {
      ans += m % 10;
      m /= 10;
    }
    cout << ans << endl;
  }
}
