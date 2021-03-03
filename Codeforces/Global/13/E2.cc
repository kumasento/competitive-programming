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
  unordered_set<Node *> neighbours;

  Node(int num) : num(num) {}
};

int findSplit(Node *u, vector<bool> &vis, const vector<int> &fibs, int n,
              pair<Node *, Node *> &e) {
  vis[u->num - 1] = true;

  int sum = 0;
  for (Node *v : u->neighbours) {
    if (!vis[v->num - 1]) {
      int size = findSplit(v, vis, fibs, n, e);
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

bool isFibTree(Node *node, const vector<int> &fibs, int n, const int N) {
  if (node->neighbours.size() == 0) return true;

  vector<bool> vis(N, false);
  pair<Node *, Node *> e(nullptr, nullptr);
  findSplit(node, vis, fibs, n, e);

  if (e.first == nullptr) return false;

  // Perform the spliting
  Node *u = e.first, *v = e.second;
  u->neighbours.erase(v);
  v->neighbours.erase(u);

  return isFibTree(u, fibs, n - 1, N) && isFibTree(v, fibs, n - 2, N);
}

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
  vector<Node *> nodes;
  for (int i = 0; i < N; i++) nodes.push_back(new Node(i + 1));

  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;

    nodes[u - 1]->neighbours.insert(nodes[v - 1]);
    nodes[v - 1]->neighbours.insert(nodes[u - 1]);
  }

  if (isFibTree(nodes[0], fibs, n, N))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
