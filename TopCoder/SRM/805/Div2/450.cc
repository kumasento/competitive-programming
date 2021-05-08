#include <bits/stdc++.h>
using namespace std;
#define LL long long

class CubeTower {
public:
  LL cube(LL k) { return k * k * k; }

  long long difference(int H, int N) {
    LL R = H % N;
    LL mn = cube(H / N + 1) * R + cube(H / N) * (N - R);
    LL mx = cube(H - N + 1) + N - 1;

    return mx - mn;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  CubeTower sol;
  cout << sol.difference(4, 2) << endl;
}
