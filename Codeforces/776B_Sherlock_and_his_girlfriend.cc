#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << endl << 1 << endl;
    return 0;
  }
  if (n == 2) {
    cout << 1 << endl << 1 << " " << 1 << endl;
    return 0;
  }

  n++;

  vector<bool> is_prime(n + 1, true);
  for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }

  cout << 2 << endl;
  for (int i = 2; i <= n; i++)
    cout << (is_prime[i] ? 1 : 2) << " ";
  cout << endl;
}
