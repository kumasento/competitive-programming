#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<int>> a(2);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    a[num % 2].push_back(num);
  }

  std::sort(a[0].begin(), a[0].end());
  std::sort(a[1].begin(), a[1].end());

  int N = a[0].size(), M = a[1].size();
  int sum = 0;
  if (N > M)
    for (int i = 0; i < N - M - 1; i++) sum += a[0][i];
  else if (M > N)
    for (int i = 0; i < M - N - 1; i++) sum += a[1][i];

  cout << sum << endl;

  return 0;
}