#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vector<int> u(n);
    vector<vector<LL>> uni(n);
    vector<vector<LL>> suf(n + 1);

    for (int i = 0; i < n; i++)
      cin >> u[i];

    LL total = 0LL;
    for (int i = 0; i < n; i++) {
      LL s;
      cin >> s;
      total += s;
      uni[u[i] - 1].push_back(s);
    }

    for (int i = 0; i < n; i++)
      sort(uni[i].begin(), uni[i].end());

    for (int i = 0; i < n; i++) {
      int m = int(uni[i].size());
      if (suf[m].empty())
        suf[m].assign(m + 1, 0);

      LL partial = 0;

      for (int j = 0; j < m; j++) {
        partial += uni[i][j];
        suf[m][j + 1] += partial;
      }
    }

    vector<LL> lose(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (!suf[i].empty()) {
        for (int k = 1; k <= n; k++)
          lose[k] += suf[i][i % k];
      }
    }

    for (int k = 1; k <= n; k++)
      cout << total - lose[k] << " ";
    cout << endl;
  }
}
