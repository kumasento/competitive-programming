#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int nsqrt = sqrt(n);
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;

  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }

  int ans = 0;
  for (int i = 0; i < primes.size(); i++)
    for (int j = i + 1; j < primes.size(); j++)
      if (i != j) {
        int x = primes[i], y;
        for (; x <= n; x *= primes[i])
          for (y = primes[j]; x * y <= n; y *= primes[j], ans++)
            ;
      }

  cout << ans << endl;
}
