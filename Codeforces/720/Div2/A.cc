#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;

  while (t --) {
    LL A, B; cin >> A >> B;

    if (B == 1) cout << "NO" << endl;
    else {
      LL x, y, z;

      if (B == 2) B *= 2;
      x = A, y = A * (B - 1), z = A * B;
      cout << "YES" << endl;
      cout << x << " " << y << " " << z << endl;
    }

  }
}
