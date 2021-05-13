/**
 * Author: kumasento
 * Date:   2021-05-13T21:06:10.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// ---------- Globals   ---------

/// ---------- Solution  ---------

class OverallScores {
public:
  int findWinner(int N, vector<int> scores) {
    int M = scores.size() / N;
    vector<int> sums(N, 0);

    for (int i = 0; i < M; i ++) 
      for (int j = 0; j < N; j ++) 
        sums[j] += scores[i * N + j];

    int max_sum = sums[0], max_idx = 0;
    for (int i = 1; i < N; i ++) {
      if (max_sum < sums[i]) {
        max_idx = i;
        max_sum = sums[i];
      }
    }

    return max_idx;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

} 
