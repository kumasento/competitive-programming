#include <bits/stdc++.h>

using namespace std;

void naive(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++)
    if (is_prime[i] && (long long)i * i <= n)
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

  for (int i = 0; i <= n; i++)
    if (is_prime[i])
      cout << i << endl;
}

int count_primes(int n) {
  const int S = 10000;

  vector<int> primes;
  int nsqrt = sqrt(n);
  vector<bool> is_prime(nsqrt + 1, true);

  for (int i = 2; i <= nsqrt; i++)
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= nsqrt; j += i)
        is_prime[j] = false;
    }

  int result = 0;
  vector<char> block(S);
  for (int k = 0; k * S <= n; k++) {
    fill(block.begin(), block.end(), true);
    int start = k * S;
    for (int p : primes) {
      int start_idx = (start + p - 1) / p; // floor(start / p);
      int j = max(start_idx, p) * p - start;
      for (; j < S; j += p)
        block[j] = false;
    }

    if (k == 0)
      block[0] = block[1] = false;

    for (int i = 0; i < S && start + i <= n; i++)
      if (block[i])
        result++;
  }

  return result;
}

vector<bool> segmentedSieve(long long L, long long R) {
  long long lim = sqrt(R);
  vector<bool> mark(lim + 1, true);
  vector<long long> primes;

  for (long long i = 2; i <= lim; i++)
    if (mark[i]) {
      primes.push_back(i);
      for (long long j = i * i; j <= lim; j++)
        mark[i] = false;
    }

  vector<bool> isPrime(R - L + 1, true);
  for (long long i : primes)
    for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
      isPrime[j - L] = false;

  if (L == 1)
    isPrime[0] = false;
  return isPrime;
}

int main() {
  int n;
  cin >> n;

  // naive(n);
  cout << count_primes(n) << endl;
}
