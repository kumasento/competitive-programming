#include <bits/stdc++.h>
using namespace std;
#define LL long long

int N;
vector<int> C;
vector<vector<int>> adj;
multiset<int> path;
vector<int> ans;

void dfs(int i, int p = -1) {
  if (!path.count(C[i]))
    ans.push_back(i + 1);

  path.insert(C[i]);
  for (int to : adj[i])
    if (to != p)
      dfs(to, i);

  path.erase(path.find(C[i]));
}

int main() {
  cin >> N;

  adj.resize(N);
  C.resize(N);

  for (auto &i : C) cin >> i;
  for (int i = 0; i < N - 1; i ++) {
    int u, v; cin >> u >> v; u --, v --;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0);
  sort(ans.begin(), ans.end());
  for (int i : ans) cout << i << endl;
}
