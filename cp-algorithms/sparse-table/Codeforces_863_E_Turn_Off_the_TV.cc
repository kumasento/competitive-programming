#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cmath>

using namespace std;

#define MAXL ((int) 1e9 + 1)

int main() {
  int n; cin >> n;

  vector<int> L(n), R(n);
  vector<pair<int, int>> queries(n);
  for (int i = 0; i < n; i ++) {
    int l, r; cin >> l >> r;
    L[i] = l, R[i] = r;
    queries[i].first = l;
    queries[i].second = r;
  }

  sort(L.begin(), L.end());
  sort(R.begin(), R.end());
  
  int m = max(L[n-1], R[n-1]) + 1;
  int k = log2(m);

  vector<vector<uint16_t>> st(m, vector<uint16_t>(k + 1));

  int cur = 0;
  int li = 0, ri = 0;
  for (int i = 0; i < m; i ++) {
    while (li < L.size() && i == L[li]) {cur ++; li ++; }
    st[i][0] = cur;
    while (ri < R.size() && i == R[ri]) {cur --; ri ++; }
  }

  for (int j = 1; j <= k; j ++) {
    for (int i = 1; i + (1 << j) <= m; i ++) {
      st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; i ++) {
    int x = queries[i].first, y = queries[i].second;

    int j = log2(y - x + 1);
    int minCnt = min(st[x][j], st[y-(1<<j)+1][j]);
    if (minCnt != 1) {
      ans.push_back(i + 1);
      break;
    }
  }

  if (ans.empty())
    cout << -1 << endl;
  else {
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }
}
