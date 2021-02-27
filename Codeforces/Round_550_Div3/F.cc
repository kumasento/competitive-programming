#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> edges(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[u - 1].push_back(make_pair(v - 1, i + 1));
    edges[v - 1].push_back(make_pair(u - 1, -(i + 1)));
  }

  vector<int> dirs(m + 1, -1);  // directions

  queue<int> q;
  q.push(0);
  q.push(-1);  // when to change dir

  int dir = 0;
  bool ok = true;

  while (!q.empty() && ok) {
    int u = q.front();
    q.pop();
    // cout << u << " " << endl;

    if (u == -1) {
      dir = 1 - dir;
      if (q.empty()) break;
      q.push(-1);
    } else {
      for (auto p : edges[u]) {
        int v = p.first, e = p.second;
        int i = abs(e);
        // cout << "v = " << v << endl;

        if (dirs[i] == -1) {
          dirs[i] = e < 0 ? 1 - dir : dir;
          q.push(v);
        } else {
          if ((e > 0 && dirs[i] != dir) || (e < 0 && dirs[i] != (1 - dir))) {
            ok = false;
            break;
          }
        }
      }
    }
  }

  if (!ok)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 1; i < dirs.size(); i++) cout << dirs[i];
    cout << endl;
  }

  return 0;
}