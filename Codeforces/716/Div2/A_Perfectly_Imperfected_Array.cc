#include <bits/stdc++.h>

using namespace std;
int n;

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    cin >> n;
    bool YES = false;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;

      int root = (int)sqrt(a);
      if (root * root != a) {
        YES = true;
      }
    }

    if (YES)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
