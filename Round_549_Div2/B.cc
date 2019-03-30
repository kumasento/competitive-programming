#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;

  int m = n;
  long long ans = 1;

  while (m > 0) {
    if (m % 10 == 0) {
      m--;
    }
    ans *= (long long)(m % 10);
    m /= 10;
  }

  cout << ans << endl;

  return 0;
}