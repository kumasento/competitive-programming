#include <bits/stdc++.h>

using u64 = uint64_t;
using u128 = __uint128_t;

using namespace std;

u64 binpower(u64 base, u64 exp, u64 mod) {
  u64 res = 1;
  base %= mod;
  while (exp > 0) {
    if (exp & 1) res = ((u128)base * res) % mod;
    base = ((u128)base * base) % mod;
    exp >>= 1;
  }
  return res;
}

bool isPrime(int x) {
  for (int d = 2; d * d <= x; d++)
    if (x % d == 0)
      return false;
  return true;
}

bool probablyPrimeFermat(int n, int iter=5) {
  if (n < 4)
    return n == 2 || n == 3;

  for (int i = 0; i < iter; i ++) {
    // we want a to be a value between [2, n - 1]
    int a = 2 + rand() % (n - 3);

    if (binpower(a, n - 1, n) != 1)
      return false;
  }

  return true;
}

// ------ Miller Rabin

// Check either a^d = 1 mod n or a^{2^r d} = -1 mod n for r in 1 to s - 1
bool check_composite(u64 n, u64 a, u64 d, int s) {
  u64 x = binpower(a, d, n);
  if (x == 1 || x == n - 1)
    return false;
  for (int r = 1; r < s; r ++) {
    x = (u128) x * x % n;
    if (x == n - 1)
      return false;
  }
  return true;
}

bool MillerRabin(u64 n, int iter=5) {
  if (n < 4)
    return n == 2 || n == 3;

  int s = 0;
  u64 d = n - 1;

  // Find the 2^s d == n - 1 factorization
  while ((d & 1) == 0) {
    d >>= 1;
    s ++;
  }

  for (int i = 0; i < iter; i ++) {
    int a = 2 + rand() % (n - 3);
    if (check_composite(n, a, d, s))
      return false;
  }

  return true;
}

bool MillerRabinDeterministic(u64 n) {
  if (n < 2)
    return false;

  int r = 0;
  u64 d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r ++;
  }

  for (int a : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 })
    if (n == a)
      return true;
    if (check_composite(n, a, d, r))
      return false;

  return true;
}

int main() {
  cout << probablyPrimeFermat(111) << endl;
  cout << probablyPrimeFermat(7727) << endl;
}
