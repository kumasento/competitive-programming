/**
 * Author: kumasento
 * Date:   2021-05-11T19:26:16.000-05:00
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

struct FenwickTree {
  vector<int> bit; // binary indexed tree.
  int n;

  FenwickTree(int n): n(n) {
    bit.assign(n, 0);    
  }

  FenwickTree(vector<int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); ++ i)
      add(i, a[i]);
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = r & (r + 1)) 
      ret += bit[r];
    return ret;
  }

  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }

  void add(int idx, int delta) {
    // h[j] = j | (j + 1);
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }
};

struct FenwickTreeOneBasedIndexing {

  vector<int> bit;
  int n;

  FenwickTreeOneBasedIndexing(int n) : n(n) {
    bit.assign(n + 1, 0);
  }

  FenwickTreeOneBasedIndexing(vector<int> &a) : FenwickTreeOneBasedIndexing(a.size()) {
    for (size_t i = 0; i < a.size(); ++i)
      add(i, a[i]);
  }

  int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
      ret += bit[idx];
    return ret;
  }

  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }

  void add(int idx, int delta) {
    for (++idx; idx < n; idx += idx & -idx)
      bit[idx] += delta;
  }

  void range_add(int l, int r, int val) {
    // values above l will be added with val. 
    // above r will be subtracted with val.
    add(l, val);
    add(r + 1, -val);
  }

  int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
      ret += bit[idx];
    return ret;
  }

};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
