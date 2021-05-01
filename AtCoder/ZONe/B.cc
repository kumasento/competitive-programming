#include <bits/stdc++.h>

#define LL long long

using namespace std;



int main() {
  int N, D, H; cin >> N >> D >> H;

  double max_h = 0;
  for (int i = 0; i < N; i ++) {
    double d, h; cin >> d >> h;

    double new_h = h - (H - h) / (D - d) * d;
    max_h = max(new_h, max_h);
  }
  cout << max_h << endl;
}
