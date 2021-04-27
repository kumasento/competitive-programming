#include <bits/stdc++.h>

using namespace std;

#define LL long long

const int MOD = 1000000007;

void mul(LL F[2][2], LL M[2][2]) {
  LL x = ((LL)(F[0][0] * M[0][0]) % MOD + (LL)(F[0][1] * M[1][0]) % MOD) % MOD;
  LL y = ((LL)(F[0][0] * M[0][1]) % MOD + (LL)(F[0][1] * M[1][1]) % MOD) % MOD;
  LL z = ((LL)(F[1][0] * M[0][0]) % MOD + (LL)(F[1][1] * M[1][0]) % MOD) % MOD;
  LL w = ((LL)(F[1][0] * M[0][1]) % MOD + (LL)(F[1][1] * M[1][1]) % MOD) % MOD;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void pow(LL F[2][2], LL n) {
  LL M[2][2] = {{1, 1}, {1, 0}};

  while (n > 0) {
    if (n & 1)
      mul(M, F);
    mul(F, F);
    n >>= 1;
  }

  F[0][0] = M[0][0];
  F[0][1] = M[0][1];
  F[1][0] = M[1][0];
  F[1][1] = M[1][1];
}

// Lame's theorem: https://www.cut-the-knot.org/blue/LamesTheorem.shtml

LL fib(LL n) {
  LL F[2][2] = {{1, 1}, {1, 0}};

  if (n == 0 || n == 1)
    return 1;
  pow(F, n - 2);

  return F[0][0];
}

int main() {
  // for (int n = 3; n < 100000; n++)
  //   assert(fib(n) == (fib(n - 1) + fib(n - 2)) % MOD);
  int T;
  cin >> T;

  while (T--) {
    long long N;
    cin >> N;

    if (N == 0)
      cout << 0 << endl;
    else if (N == 1) // if we directly apply Lame, we have a larger sum.
      cout << 2 << endl;
    else // if N is the number of divisions, based on Lame's theorem:
      cout << fib(N + 3) << endl;
  }
}
