#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  double R, X, Y; cin >> R >> X >> Y;

  double D = sqrt(X * X + Y * Y);
  if (D < R)
    cout << 2 << endl;
  else 
    cout << (int)ceil(D / R) << endl;
}
