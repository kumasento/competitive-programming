#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;

  auto dom = std::vector<int>{1, 5, 10, 20, 100};
  std::vector<int> dp(n + 1, 0);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    int min_val = INT_MAX;

    // try to find the minimal times to get changes
    // if d cannot be changed, dp[i-d] == 0 or i < d
    for (auto d : dom) {
      if (i - d > 0 && dp[i - d] != 0) {
        min_val = std::min(min_val, dp[i - d]);
      } else if (i - d == 0) {
        min_val = 0;
      }
    }

    dp[i] = min_val + 1;
  }

  std::cout << dp[n] << std::endl;

  return 0;
}