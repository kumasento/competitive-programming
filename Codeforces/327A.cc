#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n); for (int &i : a) cin >> i;

  int total = accumulate(a.begin(), a.end(), 0);
  vector<int> b(n); for (int i = 0; i < n; i ++) b[i] = a[i] ? -1 : 1;

  vector<int> bst(n);
  bst[0] = b[0];
  for (int i = 1; i < n; i ++)
    bst[i] = max(b[i], bst[i-1] + b[i]);

  cout << total + *max_element(bst.begin(), bst.end()) << endl;
}
