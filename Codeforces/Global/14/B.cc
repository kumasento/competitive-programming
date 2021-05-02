#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  set<int> powers;
  for (int i = 1; (1LL << i) <= 1000000001; i ++)
    powers.insert((1 << i));

  int t; cin >> t;
  while (t --) {
    int n; cin >> n;

    bool ok = false;
    for (int p : powers) {
      if (n % p)
        continue;

      int m = n / p;
      double s = sqrt((double) m);
      if ((int) s * s != m) 
        continue;

      ok = true;
      break;
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
