#include <bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
  int n;
  cin >> n;

  LL ans = 4LL * ((n - 3) * pow(4LL, n - 4) * 9 + 3 * pow(4LL, n - 3) * 2);
  cout << ans << endl;
}
