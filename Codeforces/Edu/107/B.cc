#include <bits/stdc++.h>
using namespace std;
#define LL long long


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;

  while (t --) {
    int a, b, c; cin >> a >> b >> c;

    // x, y, gcd(x, y)
    // Let's make gcd(x, y) = 10^{c-1}.
    // Then x can be 10^{a - 1}, and y can be 11...1 * 10^{c-1}.

    cout << (int) pow(10, a - 1) << " " << string(b - c, '1') << (int) pow(10, c - 1) << endl;
  }
}
