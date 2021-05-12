/**
 * Author: kumasento
 * Date:   2021-05-11T22:04:07.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// ---------- Globals   ---------

/// ---------- Solution  ---------

struct item {
  int key, prior;
  item *l, *r;
  item() {}
  item(int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) {}
};
typedef item *pitem;

// l & r are the point to be appended.
// This is like slicing through a BST vertically.
void split(pitem t, int key, pitem &l, pitem &r) {
  if (!t)
    l = r = NULL;
  else if (key < t->key) 
    // t will be r, t->l will be r's left child.
    split(t->l, key, l, t->l), r = t;
  else
    split(t->r, key, t->r, r), l = t;
}

// insert it into t?
void insert(pitem &t, pitem it) {
  if (!t) // t is NULL, then insert it directly
    t = it;
  else if (it->prior > t->prior)  // insert only happens when the priority is higher.
    split(t, it->key, it->l, it->r), t = it;
  else
    insert(it->key < t->key ? t->l : t->r, it);
}


void merge(pitem &t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    // merge r into l
    merge(l->r, l->r, r), t = l;
  else
    // merge l into r.
    merge(r->l, l, r->l), t = r;
}

void erase(pitem &t, int key) {
  if (t->key == key) {
    pitem th = t;
    merge(t, t->l, t->r);
    delete th;
  }
  else
    erase(key < t->key ? t->l : t->r, key);
}

pitem unite(pitem l, pitem r) {
  if (!l || !r) return l ? l : r;
  if (l->prior < r->prior) swap(l, r);
  pitem lt, rt;
  split(r, l->key, lt, rt);
  l->l = unite(l->l, lt);
  l->r = unite(l->r, rt);
  return l;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
