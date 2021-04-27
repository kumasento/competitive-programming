#include <bits/stdc++.h>

using namespace std;

#define LL long long

constexpr LL MOD = 1000000007;

void mul(LL F[2][2], LL M[2][2]) {
  LL x = ((F[0][0] * M[0][0]) % MOD + (F[0][1] * M[1][0]) % MOD) % MOD;
  LL y = ((F[0][0] * M[0][1]) % MOD + (F[0][1] * M[1][1]) % MOD) % MOD;
  LL z = ((F[1][0] * M[0][0]) % MOD + (F[1][1] * M[1][0]) % MOD) % MOD;
  LL w = ((F[1][0] * M[0][1]) % MOD + (F[1][1] * M[1][1]) % MOD) % MOD;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void pow(LL F[2][2], LL N) {
  LL M[2][2] = {{1, 1}, {1, 0}};
  while (N > 0) {
    if (N & 1)
      mul(M, F);
    mul(F, F);
    N >>= 1;
  }
  F[0][0] = M[0][0];
  F[0][1] = M[0][1];
  F[1][0] = M[1][0];
  F[1][1] = M[1][1];
}

LL fib(LL N) {
  LL F[2][2] = {{1, 1}, {1, 0}};

  if (N == 0 || N == 1)
    return 1;

  pow(F, N - 2);

  return F[0][0];
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;

    // sum_{i = 1}^{N} F_{i} = F_{N + 2} - 1
    // sum_{i = 1}^{M} F_{i} = F_{M + 2} - 1
    // sum_{i = N}^{M} F_{i} = F_{M + 2} - F_{N + 1}

    LL ans = (fib(M + 2) % MOD - fib(N + 1) % MOD + MOD) % MOD;
    cout << ans << endl;
  }
}
