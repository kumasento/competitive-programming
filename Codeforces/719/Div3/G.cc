#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m, w; cin >> n >> m >> w;
  vector cells(n, vector<LL>(m));
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
      cin >> cells[i][j];

  map<pair<int, int>, LL> cmap1, cmap2;
  vector vis(n, vector<bool>(m, false));

  queue<tuple<int, int, LL>> q1, q2;
  q1.push({0, 0, 0});
  vis[0][0] = true;
  if (cells[0][0] > 0)
    cmap1[{0, 0}] = 0;

  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  LL bst = LONG_LONG_MAX;

  while (!q1.empty()) {
    int i, j; LL c; tie(i, j, c) = q1.front(); q1.pop();

    if (i == n - 1 && j == m - 1) {
      bst = min(bst, c);
      break;
    }

    for (auto d : dirs) {
      int x, y; x = d[0] + i, y = d[1] + j;
      if (x < 0 || x >= n || y < 0 || y >= m)
        continue;
      if (vis[x][y] || cells[x][y] == -1)
        continue;
      vis[x][y] = true;
      q1.push({x, y, c + w});

      if (cells[x][y] != 0) 
        cmap1[{x, y}] = c + w;
    }
  }

  if (cells[n-1][m-1] > 0)
    cmap2[{n-1, m-1}] = 0;
  q2.push({n - 1, m - 1, 0});
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
      vis[i][j] = false;
  vis[n - 1][m - 1] = true;
  
  while (!q2.empty()) {
    int i, j; LL c; tie(i, j, c) = q2.front(); q2.pop();

    for (auto d : dirs) {
      int x, y; x = d[0] + i, y = d[1] + j;
      if (x < 0 || x >= n || y < 0 || y >= m)
        continue;
      if (vis[x][y] || cells[x][y] == -1)
        continue;
      vis[x][y] = true;
      q2.push({x, y, c + w});

      if (cells[x][y] != 0) 
        cmap2[{x, y}] = c + w;
    }
  }

  for (auto &it1 : cmap1) {
    for (auto &it2 : cmap2) {
      if (it1.first != it2.first) {
        bst = min(bst, it1.second + it2.second + cells[it1.first.first][it1.first.second] + cells[it2.first.first][it2.first.second]);
      }
    }
  }

  if (bst == LONG_LONG_MAX)
    cout << -1 << endl;
  else
    cout << bst << endl;
}
