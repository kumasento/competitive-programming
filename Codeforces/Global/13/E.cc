#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define LL long long

#define FOR(i, j, k, s) for (int(i) = (j); (i) < (k); (i) += (s))

using namespace std;

int main(int argc, char *argv[]) {
  // Placeholder

  int N;
  cin >> N;
  vector<vector<int>> G(N);

  for (int i = 0; i < N; i++) {
    int u, v;
    cin >> u >> v;

    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }

  return 0;
}
