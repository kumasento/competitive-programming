#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int r, b, d;
    cin >> r >> b >> d;

    int x = max(r, b), y = min(r, b);
    int z = (int)ceil((double)x / y);
    if (z - 1 > d)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
