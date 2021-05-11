#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<int> solve(vector<int> &a, vector<int> &b) {
  int n = a.size(), m = b.size();

  // d[i][j] - L(LIS) ending at a[i] and b[j] where a[i] == b[j].
  vector<vector<int>> dp(n, vector<int>(m, 0));
  vector<int> p(n, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = 1;
        for (int k = 0; k < i; k++) {
          for (int t = 0; t < j; t++) {
            if (a[k] == b[t] && a[i] > a[k] && dp[i][j] < dp[k][t] + 1) {
              dp[i][j] = dp[k][t] + 1;
              p[i] = k;
            }
          }
        }
      }
    }
  }

  int maxLen = 0, maxIdx = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (dp[i][j] > maxLen) {
        maxLen = dp[i][j];
        maxIdx = i;
      }
    }

  vector<int> seq;
  if (maxIdx == -1)
    return seq;
  while (p[maxIdx] != -1) {
    seq.push_back(a[maxIdx]);
    maxIdx = p[maxIdx];
  }
  seq.push_back(a[maxIdx]);

  reverse(seq.begin(), seq.end());

  return seq;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];

  vector<int> seq = solve(a, b);
  cout << seq.size() << endl;
  copy(seq.begin(), seq.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}
