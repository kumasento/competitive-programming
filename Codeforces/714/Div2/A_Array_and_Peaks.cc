#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int n, k;
    cin >> n >> k;

    if (k > (n - 1) / 2) {
      cout << -1 << endl;
      continue;
    }

    for (int i = 0; i < n; i++) {
      if (i == 0)
        cout << i + 1 << " ";
      else if (i <= k * 2) {
        if (i % 2)
          cout << i + 2 << " ";
        else
          cout << i << " ";
      } else {
        cout << i + 1 << " ";
      }
    }

    cout << endl;
  }
}
