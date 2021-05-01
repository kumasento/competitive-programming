#include <bits/stdc++.h>

#define LL long long

constexpr LL MOD = 1000000007;

using namespace std;

LL ans;
int a, b, n;

bool is_good(LL x) {
  while (x > 0) {
    if (!(x % 10 == a || x % 10 == b))
      return false;
    x /= 10;
  }
  return true;
}

LL extgcd(LL a, LL b, LL &x, LL &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  LL x1, y1;
  LL g = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

LL invmod(LL a) {
  LL x, y;
  extgcd(a, MOD, x, y);
  x = (x % MOD + MOD) % MOD;
  return x;
}

vector<LL> fact;

LL C(LL n, LL i) { return fact[n] * invmod(fact[n - i] * fact[i]) % MOD; }

int main() {
  cin >> a >> b >> n;

  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++)
    fact[i] = (fact[i - 1] * i) % MOD;

  ans = 0LL;

  for (int m = 0; m <= n; m++) {
    LL sum = m * a + (n - m) * b;
    if (is_good(sum)) {
      if (m == 0 || m == n)
        ans = (ans + 1) % MOD;
      else {
        ans = (ans + C(n, m)) % MOD;
      }
    }
  }

  cout << ans << endl;
}
