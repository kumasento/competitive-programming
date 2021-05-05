#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {

  int t; cin >> t;

  while (t --) {
    int n; cin >> n;
    vector<LL> a(n); for (auto &i : a) cin >> i;

    map<LL, LL> cnts;
    for (LL i = 0; i < a.size(); i ++)
      cnts[a[i] - i] ++;

    LL ans = 0;
    for (auto &it : cnts) {
      if (it.second > 1)
        ans += it.second * (it.second - 1) / 2;
    }

    cout << ans << endl;
  }

}
