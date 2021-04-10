#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, int> cnts, inds;
    for (int i = 0; i < n; i++) cnts[a[i]]++, inds[a[i]] = i + 1;
    for (const auto &it : cnts)
      if (it.second == 1) cout << inds[it.first] << endl;
  }
}
