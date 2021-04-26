#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define MOD ((LL)(1e9 + 7))

LL modPow(LL base, LL exp) {
  LL result = 1;
  base %= MOD;
  while (exp > 0) {
    if (exp & 1)
      result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    LL n, k;
    cin >> n >> k;

    cout << modPow(n, k) << endl;
  }
}
