#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int T; cin >> T;
  while (T --) {
    int X, A, B; cin >> X >> A >> B;

    cout << (A + B * (100 - X)) * 10 << endl;
  }
}
