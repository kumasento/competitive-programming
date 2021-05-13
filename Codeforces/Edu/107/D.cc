#include <bits/stdc++.h>
using namespace std;
#define LL long long

int n, k;
int cur[26];
vector<int> path;

void dfs(int v) {
  while (cur[v] < k) {
    int u = cur[v] ++;
    dfs(u);
    path.push_back(u);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> k;
  dfs(0);
  cout << 'a';
  for (int i = 0; i < n - 1; i ++)
    cout.put(path[i % path.size()] + 'a');
  cout << endl;
}
