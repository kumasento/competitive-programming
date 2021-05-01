#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;

    int t = (m - 1) + m * (n - 1);
    if (t == k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
