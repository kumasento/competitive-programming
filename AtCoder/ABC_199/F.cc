#include <bits/stdc++.h>

using namespace std;

#define LL long long

constexpr LL MOD = 1000000007;

typedef vector<vector<LL>> Mat;

Mat mul(Mat A, Mat B) {
  int N = A.size();
  Mat C(N, vector<LL>(N, 0));

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++)
        C[i][j] = (C[i][j] + ((A[i][k] * B[k][j]) % MOD)) % MOD;
  return C;
}

LL extended_euclidean(LL a, LL b, LL &x, LL &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  LL x1, y1;
  LL g = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

LL invmod(LL a) {
  LL x, y;
  extended_euclidean(a, MOD, x, y);
  return (x % MOD + MOD) % MOD;
}

vector<vector<int>> adj;
Mat A; // weight
Mat m; // transition matrix

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  A.resize(N);
  adj.resize(N);
  m.resize(N);

  for (int i = 0; i < N; i++) {
    A[i].resize(1);
    cin >> A[i][0];
  }

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // calculate the matrix.
  LL inv2M = invmod(2 * M);
  for (int i = 0; i < N; i++) {
    m[i].assign(N, 0);
    m[i][i] = 1LL;

    for (int j : adj[i]) {
      m[i][j] = inv2M;
      m[i][i] = (m[i][i] - inv2M + MOD) % MOD;
    }
  }

  // If you calculate the other way around, m^K * A, then there will be 3 WAs.
  // Not sure why.
  while (K > 0) {
    if (K & 1)
      A = mul(m, A);
    m = mul(m, m);
    K >>= 1;
  }

  for (int i = 0; i < N; i++)
    cout << A[i][0] << endl;
}
