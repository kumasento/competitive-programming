#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

#define MAX_N 200001

using namespace std;

int main(int argc, char *argv[]) {
  int t, n, m, a[MAX_N], x;
  vector<long long> pSum(MAX_N);
  long long maxSum, lastSum;

  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    maxSum = INT_MIN;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pSum[i] = (i > 0) ? pSum[i - 1] + a[i] : a[i];
      maxSum = max(maxSum, pSum[i]);
    }

    lastSum = pSum[n - 1];

    for (int i = 1; i < n; i++) pSum[i] = max(pSum[i - 1], pSum[i]);

    for (int i = 0; i < m; i++) {
      cin >> x;

      long long ans = 0;
      if (lastSum > 0 && x > maxSum) {
        long long round = (long long)ceil((double)(x - maxSum) / lastSum);
        ans += round * n;
        x -= round * lastSum;
      }

      vector<long long>::iterator it =
          lower_bound(pSum.begin(), pSum.begin() + n, x);
      if (it == pSum.begin() + n)
        cout << -1;
      else
        cout << ans + (it - pSum.begin());

      if (i == m - 1)
        cout << endl;
      else
        cout << ' ';
    }
  }

  return 0;
}
