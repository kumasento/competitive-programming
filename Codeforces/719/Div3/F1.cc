#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  int n, t, k; cin >> n >> t >> k;

  int lo = 0, hi = n;

  while (lo < hi) {
    int mi = lo + (hi - lo) / 2;
    if (lo + 2 == hi) {
      if (k == 2) {
        cout << "! " << lo + 2 << endl; cout.flush();
      } else {
        cout << "? " << lo + 1 << " " << lo + 1 << '\n';
        cout.flush();
        int cnt; cin >> cnt; if (cnt == -1) exit(0);
        int ans = cnt == 0 ? lo + 1 : lo + 2;

        cout << "! " << ans << endl; cout.flush();
      }
      break;
    }

    cout << "? " << lo + 1 << " " << mi + 1 << '\n';
    cout.flush();

    int cnt; cin >> cnt; if (cnt == -1) exit(0);
    int nz = (mi - lo + 1) - cnt;
    if (nz == 1 && mi == lo) {
      cout << "! " << lo + 1 << '\n';
      cout.flush();
      break;
    } else if (nz < k) {
      k -= nz;
      lo = mi + 1;
    } else {
      hi = mi + 1;
    }
  }
}
