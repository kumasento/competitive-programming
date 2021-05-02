#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while (t --) {
    int n, x; cin >> n >> x;

    vector<int> w(n);
    for (auto &i: w) cin >> i;

    sort(w.begin(), w.end());

    int sum = 0;
    bool failed = false;
    for (int i = 0; i < n; i ++) {
      if (sum + w[i] == x) {
        if (i == n - 1) {
          failed = true;
          break;
        }
        swap(w[i], w[i + 1]);
      }
      sum += w[i];
    }

    if (failed)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      copy(w.begin(), w.end(), ostream_iterator<int>(cout, " "));
      cout << endl;
    }
  }

}
