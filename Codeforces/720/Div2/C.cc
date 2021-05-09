#include <bits/stdc++.h>
using namespace std;
#define LL long long

int query(int t, int i, int j, int x) {
  cout << "? " << t << " " << i + 1 << " " << j + 1 << " " << x << endl;
  cout.flush();
  int val; cin >> val;
  return val;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int T; cin >> T;

  while (T --) {
    int n; cin >> n;

    vector<LL> ans(n, 0);
    for (int i = 0; i < n; i += 2) {
      if (i == n - 1) {
        LL sum = accumulate(ans.begin(), ans.end(), 0);
        ans[i] = (1LL + n) * n / 2 - sum;
        break;
      }

      // query max       
      int mx = query(1, i, i + 1, n - 1);
      if (mx == n - 1) {
        if (query(1, i + 1, i, n - 1) == n) {
          ans[i] = n;
          ans[i + 1] = query(2, i + 1, i, 1); 
          continue;
        }
      }

      // query which is max?
      int val = query(1, i, i + 1, mx - 1);
      if (val == mx) {
        // pj == mx;
        ans[i + 1] = mx;
        ans[i] = query(2, i, i + 1, 1);
      } else { // val == mx - 1
        // pi == mx
        ans[i] = mx;
        ans[i + 1] = query(2, i + 1, i, 1);
      }
    } 

    cout << "! ";
    for (int i : ans) cout << i << " ";
    cout << endl;
    cout.flush();
  }
}
