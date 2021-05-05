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

  vector vis(n, vector<bool>(m, false));

  queue<tuple<int, int, LL>> q;
  q.push({0, 0, 0});
  vis[0][0] = true;

  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  map<pair<int, int>, LL> cmap1, cmap2;

  LL bst = LONG_LONG_MAX;

  while (!q.empty()) {
    int i, j; LL c; tie(i, j, c) = q.front(); q.pop();

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
      q.push({x, y, c + w});

      if (cells[x][y] != 0) 
        cmap1[{x, y}] = c + w;
    }
  }

  q.push({n - 1, m - 1, 0});
  for (int i = 0; i < n; i ++)
  for (int j = 0; j < m; j ++)
    vis[i][j] = false;
  
  while (!q.empty()) {
    int i, j; LL c; tie(i, j, c) = q.front(); q.pop();

    for (auto d : dirs) {
      int x, y; x = d[0] + i, y = d[1] + j;
      if (x < 0 || x >= n || y < 0 || y >= m)
        continue;
      if (vis[x][y] || cells[x][y] == -1)
        continue;
      vis[x][y] = true;
      q.push({x, y, c + w});

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
