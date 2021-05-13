#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class RadixTree {
  struct Node {
    bool val;
    bool end;
    unique_ptr<Node> children[2];
    // No need to support delete

    Node(bool val = false, bool end = false) : val(val), end(end) {}
  };

  unique_ptr<Node> root;

 public:
  RadixTree() : root(make_unique<Node>()) {}

  void insert(const vector<bool> &);
  auto sorted();
  void visit(Node *, vector<bool> &, vector<vector<bool>> &);
};

void RadixTree::insert(const vector<bool> &vec) {
  assert(vec.size() > 0);

  unique_ptr<Node> *curr = &root;

  for (auto v : vec) {
    if (!(*curr)->children[v]) (*curr)->children[v] = make_unique<Node>(v);
    curr = &((*curr)->children[v]);
  }

  (*curr)->end = true;
}

void RadixTree::visit(Node *node, vector<bool> &vec,
                      vector<vector<bool>> &vecs) {
  assert(node != nullptr);

  if (node->end) vecs.push_back(vec);
  for (int i = 0; i < 2; i++)
    if (node->children[i]) {
      vec.push_back(i);
      visit(node->children[i].get(), vec, vecs);
      vec.pop_back();
    }
}

auto RadixTree::sorted() {
  vector<vector<bool>> vecs;
  vector<bool> vec;

  visit(root.get(), vec, vecs);

  return vecs;
}

int main() {
  RadixTree rt;

  rt.insert({0});
  rt.insert({0, 1, 1});
  rt.insert({1, 0});
  rt.insert({1, 0, 0});
  rt.insert({1, 0, 1, 1});

  for (auto vec : rt.sorted()) {
    copy(vec.begin(), vec.end(), ostream_iterator<bool>(cout, ""));
    cout << endl;
  }
}
