#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;

  while (t --) {
    int n, k; cin >> n >> k;

    vector<int> a(n); for (int &i : a) cin >> i;

    int j = 0;
    for (int i = 0; i < k; i ++) {
      while (j < a.size() && a[j] == 0) j ++;

      if (j >= a.size() - 1) 
        break;

      a[j] --, a.back() ++;
    }

    for (int i : a) cout << i << ' ';
    cout << endl;
  }
}
