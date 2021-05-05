#include <bits/stdc++.h>
using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;


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

bool MillerRabinDeterministic(u64 n) {
  if (n < 2)
    return false;

  int r = 0;
  u64 d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r ++;
  }

  for (int a : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
    if (n == a)
      return true;
    if (check_composite(n, a, d, r))
      return false;
  }

  return true;
}

int main() {
  int t; cin >> t;

  while (t --) {
    u64 n; cin >> n;
    if (MillerRabinDeterministic(n))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
