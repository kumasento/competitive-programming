#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
  LL n = 600851475143LL;
  LL nsqrt = sqrt(n);

  vector<LL> primes;
  vector<bool> is_prime(nsqrt + 1, true);

  for (LL i = 2; i <= nsqrt; i ++)
    if (is_prime[i]) {
      primes.push_back(i);
    
      for (LL j = i * i; j <= nsqrt; j += i)
        is_prime[j] = false;
    }

  LL largest = 0;
  for (LL p : primes) {
    if (p * p > n)
      break;
    
    while (n % p == 0) {
      n /= p;
      largest = p;
    }
  }

  if (n > 1)
    largest = max(n, largest);

  cout << largest << endl;
}


