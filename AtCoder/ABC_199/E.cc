// bitmask DP

#include <bits/stdc++.h>

using namespace std;

#define LL long long

vector<LL> dp;
vector<bool> valid;
LL ans;
int N, M;

LL dfs(int S) {
  if (dp[S] != -1)
    return dp[S];

  int ones = __builtin_popcount(S);
  dp[S] = 0LL;
  if (!valid[S])
    return dp[S];

  for (int i = 0; i < N; i++) {
    int mask = (1 << i);
    if (S & mask) {

      dp[S] += dfs(S - mask);
    }
  }

  return dp[S];
}

int main() {
  cin >> N;
  cin >> M;

  dp.assign((1 << N), -1);
  // every condition should be satisfied for an empty set.
  dp[0] = 1LL;

  ans = 0LL;
  valid.assign((1 << N), true);

  // Precompute whether a subset is valid or not. We only need to look at the
  // case that X_i == |S|.
  for (int i = 0; i < M; i++) {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    for (int S = 0; S < (1 << N); S++) {
      if (!valid[S])
        continue;

      int ones = __builtin_popcount(S);
      if (ones == X) {
        int mask = ((1 << Y) - 1);
        // Count the total number of elements in S that are <= Y.
        int num = __builtin_popcount(mask & S);

        if (num > Z)
          valid[S] = false;
      }
    }
  }

  cout << dfs((1 << N) - 1) << endl;
}
