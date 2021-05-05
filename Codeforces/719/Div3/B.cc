#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  int t; cin >> t;
  while (t --) {
    LL n; cin >> n;

    LL base = 1;
    LL cnt = 0;
    while (base <= n) {
      for (LL k = 1; k <= 9; k ++) {
        if (base * k <= n)
          cnt ++;
        else
          break;
      }

      base = base * 10 + 1;
    }

    cout << cnt << endl;
  }
}
