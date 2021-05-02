#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;

  while (t --) {
    int n, m, x; cin >> n >> m >> x;

    vector<int> h(n);
    for (int &i : h) cin >> i;

    vector<int> ord(n);
    for (int i = 0; i < n; i ++) ord[i] = i;

    sort(ord.begin(), ord.end(), [&](const int &a, const int &b) {
      return h[a] < h[b];
    });

    int i = 0, j = h.size() - 1;
    int dir = 0;

    vector<int> s(m);
    vector<int> ind(n);
    for (int k = 0; k < n; k ++) {
      if (k != 0 && k % m == 0) {
        dir = 1 - dir;
      }

      if (dir == 0) {
        ind[ord[i]] = (k % m) + 1;
        s[k % m] += h[ord[i ++]];
      } else {
        ind[ord[j]] = (k % m) + 1;
        s[k % m] += h[ord[j --]];
      }
    }

    sort(s.begin(), s.end());

    if (s.back() - s.front() <= x) {
      cout << "YES" << endl;
      copy(ind.begin(), ind.end(), ostream_iterator<int>(cout, " "));
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
