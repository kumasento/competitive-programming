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

struct Node {
  int num;
  set<Node *> neighbours;

  Node(int num) : num(num) {}
};

int findSplit(int u, vector<pair<int, bool>> *G, set<int> &vis,
              const vector<int> &fibs, int n, pair<int, int> &e) {
  vis.insert(u);

  int sum = 0;
  // for (Node *v : u->neighbours) {

  for (pair<int, bool> edge : G[u]) {
    // e is not there anymore.
    if (edge.second) continue;

    int v = edge.first;
    // if v hasn't been visited earlier.
    if (!vis.count(v)) {
      int size = findSplit(v, G, vis, fibs, n, e);
      // Found a valid split.
      if (size == fibs[n - 1])
        e = make_pair(v, u);
      else if (size == fibs[n - 2])
        e = make_pair(u, v);

      sum += size;
    }
  }

  return sum + 1;
}

bool isFibTree(int node, vector<pair<int, bool>> *G, const vector<int> &fibs,
               int n, const int N) {
  // cout << node << endl;
  // Reach to a leaf node that has been split.
  if (n <= 1) return true;

  set<int> vis;
  pair<int, int> e(-1, -1);
  findSplit(node, G, vis, fibs, n, e);

  if (e.first == -1) return false;

  // Perform the spliting
  int u = e.first, v = e.second;
  // cout << u << " " << v << endl;
  for (int i = 0; i < G[u].size(); i++)
    if (G[u][i].first == v) {
      G[u][i].second = true;
      break;
    }
  for (int i = 0; i < G[v].size(); i++)
    if (G[v][i].first == u) {
      G[v][i].second = true;
      break;
    }

  return isFibTree(u, G, fibs, n - 1, N) && isFibTree(v, G, fibs, n - 2, N);
}

const int MAXN = 2e5 + 5;
vector<pair<int, bool>> G[MAXN];

int main(int argc, char *argv[]) {
  // Placeholder

  int N;
  cin >> N;

  if (N == 1) {
    cout << "YES" << endl;
    return 0;
  }

  // Calculate the Fibonacci sequence.
  vector<int> fibs;
  fibs.resize(N);

  int n;
  fibs[0] = 1, fibs[1] = 1;
  for (n = 2; n <= N; n++) {
    fibs[n] = fibs[n - 1] + fibs[n - 2];
    if (fibs[n] == N) break;
  }

  // Create the tree.
  // vector<Node *> nodes;

  // adjacent matrix with edge split marked.

  // for (int i = 0; i < N; i++) nodes.push_back(new Node(i + 1));

  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;

    G[u - 1].push_back(make_pair(v - 1, false));
    G[v - 1].push_back(make_pair(u - 1, false));

    // nodes[u - 1]->neighbours.insert(nodes[v - 1]);
    // nodes[v - 1]->neighbours.insert(nodes[u - 1]);
  }

  if (isFibTree(0, G, fibs, n, N))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
