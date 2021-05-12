#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int T; cin >> T;
  while (T --) {
    int N, x, k; cin >> N >> x >> k;

    if (x % k == 0 || (N + 1 - x) % k == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

}
