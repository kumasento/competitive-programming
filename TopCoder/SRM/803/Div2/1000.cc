#include <bits/stdc++.h>
using namespace std;
#define LL long long

class MarriageAndCirclingChallenge {

  public:

  void dfs(int i, vector<bool> &vis, vector<vector<int>> &adj, LL &cnt, int depth = 0) {
    vis[i] = true;

    if (depth == 3) {
      for (int to : adj[i]) 
        if (vis[to])
          cnt ++;
    } else {
      for (int to : adj[i]) 
        if (!vis[to])
          dfs(to, vis, adj, cnt, depth + 1);
    }

    vis[i] = false;
  }

  long long solve(int N, int threshold, int state) {
    auto rnd = [&]() {
      state = ((LL) state * 1103515245 + 12345) % (1LL<<31);
      return state % 100;
    };

    vector<vector<int>> adj(N);

    for (int i = 0; i < N; i ++) {
      for (int j = i + 1; j < N; j ++) {
        if (rnd() < threshold) {
          adj[i].push_back(j);
        } else {
          adj[j].push_back(i);
        }
      }
    }

    vector<bool> vis(N, false); 
    LL ans = 0;
    for (int i = 0; i < N; i ++) 
      dfs(i, vis, adj, ans);

    return ans / 4;
  }

};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
