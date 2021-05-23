#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N, C;
    cin >> N >> C;

    cout << "Case #" << (t + 1) << ": ";

    int minCost = N - 1;
    int maxCost = (N + 2) * (N - 1) / 2;
    if (C > maxCost || C < minCost) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }

    vector<int> ans(N, 0);
    C -= (N - 1);

    int left = 0, right = N - 1;
    bool isRight = true;
    int i;
    for (i = 1; i <= N && C >= N - i; i++) {
      if (isRight)
        ans[right--] = i;
      else
        ans[left++] = i;
      C -= (N - i);
      isRight = !isRight;
    }

    if (i <= N) {
      if (isRight) {
        ans[left + C] = i++;
        for (int j = left + C - 1; j >= left; j--) ans[j] = i++;
        for (int j = left + C + 1; j <= right; j++) ans[j] = i++;
      } else {
        ans[right - C] = i++;
        for (int j = right - C + 1; j <= right; j++) ans[j] = i++;
        for (int j = right - C - 1; j >= left; j--) ans[j] = i++;
      }
    }

    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));

    cout << endl;
  }
}
