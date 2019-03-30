#include <bits/stdc++.h>

using namespace std;

struct Node {
  int i, p, c;
  Node *parent;
  unordered_map<int, Node *> child_map;
  unordered_set<int> cs;

  Node(int i, int p, int c) : i(i), p(p), c(c) {}
};

struct Comparer {
  bool operator()(const Node *a, const Node *b) { return a->i < b->i; }
};

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<Node *> tree;

  for (int i = 0; i < n; i++) {
    int p, c;
    cin >> p >> c;
    tree.push_back(new Node(i + 1, p, c));
  }

  Node *root = NULL;
  for (int i = 0; i < n; i++) {
    if (tree[i]->p == -1)
      root = tree[i];
    else {
      // update tree structure
      tree[i]->parent = tree[tree[i]->p - 1];
      tree[tree[i]->p - 1]->child_map[tree[i]->i] = tree[i];

      if (tree[i]->c) {
        tree[tree[i]->p - 1]->cs.insert(tree[i]->i);
      }
    }
  }

  map<int, Node *> m;
  for (int i = 0; i < n; i++)
    if (tree[i]->parent != NULL && tree[i]->c &&
        tree[i]->cs.size() == tree[i]->child_map.size()) {
      m[tree[i]->i] = tree[i];
    }

  vector<int> q;

  while (!m.empty()) {
    // smallest node
    auto node = (*m.begin()).second;
    m.erase(node->i);
    q.push_back(node->i);

    // node will be removed
    auto p = node->parent;
    p->child_map.erase(node->i);
    if (p->cs.find(node->i) != p->cs.end()) p->cs.erase(node->i);

    // insert node's children
    for (auto it = node->child_map.begin(); it != node->child_map.end(); it++) {
      auto child = it->second;
      child->parent = p;
      p->child_map[child->i] = child;
      if (child->c) {
        p->cs.insert(child->i);
      } else {
        m.erase(p->i);
      }
    }
  }

  if (q.size() == 0)
    cout << -1 << endl;
  else {
    for (int i = 0; i < q.size(); i++) cout << q[i] << " ";
    cout << endl;
  }

  return 0;
}
