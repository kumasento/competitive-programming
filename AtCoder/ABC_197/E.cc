#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;
  vector<int> X(N), C(N); for (int i = 0; i < N; i ++) cin >> X[i] >> C[i];

  vector cmap(N + 1, set<int>{});
  for (int i = 0; i < N; i ++)
    cmap[C[i]].insert(X[i]);

  array<int, 2> last{0, 0};
  array<LL, 2> dp{0, 0};
  for (int i = 1; i <= N; i ++) {
    if (cmap[i].empty())
      continue;
    
    int left = *cmap[i].begin(), right = *cmap[i].rbegin();
    array<LL, 2> dp2(dp);
    dp[0] = right - left + min(abs(right - last[0]) + dp2[0],
                               abs(right - last[1]) + dp2[1]);
    dp[1] = right - left + min(abs(left - last[0]) + dp2[0],
                               abs(left - last[1]) + dp2[1]);
    last[0] = left, last[1] = right;
  }

  cout << min(dp[0] + abs(last[0]), dp[1] + abs(last[1])) << endl;
}
