#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class DisjointSetUnion {
  vector<int> parent;
  vector<int> size;

public:
  DisjointSetUnion(int n) : parent(n), size(n) {}

  void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
  }

  int find_set(int a) {
    if (parent[a] == a)
      return a;
    return parent[a] = find_set(parent[a]);
  }

  void union_sets(int a, int b) {
    int pa = find_set(a);
    int pb = find_set(b);
    if (pa == pb)
      return;

    if (size[pa] > size[pb])
      swap(pa, pb);
    parent[pa] = pb;
    size[pb] += size[pa];
  }
};

int main() {
  int n = 10;
  DisjointSetUnion u(n);

  for (int i = 0; i < n; i++) {
    u.make_set(i);
    assert(u.find_set(i) == i);
  }

  u.union_sets(0, 1);
  u.union_sets(2, 3);
  u.union_sets(0, 2);

  for (int i = 0; i < 4; i++)
    assert(u.find_set(i) == u.find_set(0));
}
