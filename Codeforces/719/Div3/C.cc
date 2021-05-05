#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;
  while (t --) {
    int n; cin >> n;

    if (n == 2)
      cout << -1 << endl;
    else {
      vector a(n, vector<int>(n));

      if (n & 1) {
        for (int i = 0; i < n * n; i ++) {
          int j = (i * 2) % (n * n);
          int x = j / n, y = j % n;
          a[x][y] = i + 1;
        }
      } else {
        int k = 1;
        for (int i = 0; i < n; i ++) 
          for (int j = (i & 1); j < n; j += 2) 
            a[i][j] = k ++;
        for (int i = 0; i < n; i ++) 
          for (int j = (1 - (i & 1)); j < n; j += 2) 
            a[i][j] = k ++;
      }

      for (int i =0; i < n; i++) {
        for (int j = 0; j < n; j ++)
          cout << a[i][j] << ' '; 
        cout << '\n';
      }
    }
  }

}
