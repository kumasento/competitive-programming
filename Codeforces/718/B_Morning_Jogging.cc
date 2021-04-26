#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;

    vector<deque<int>> b(n, deque<int>(m));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> b[i][j];

    for (int i = 0; i < n; i++)
      sort(b[i].begin(), b[i].end());

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < m; i++) {
      int minIdx = 0, minVal = INT_MAX;
      for (int j = 0; j < n; j++) {
        if (minVal > b[j][0]) {
          minIdx = j;
          minVal = b[j][0];
        }
      }

      for (int j = 0; j < n; j++) {
        if (j == minIdx)
          a[j][i] = b[j].front(), b[j].pop_front();
        else
          a[j][i] = b[j].back(), b[j].pop_back();
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << a[i][j] << " ";
      cout << endl;
    }
  }
}
