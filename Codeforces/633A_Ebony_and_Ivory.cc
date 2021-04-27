#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  int x1, y1;
  int g = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;

  return g;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int x, y;
  int g = gcd(a, b, x, y);

  if (c % g) {
    cout << "No" << endl;
    return 0;
  }

  a /= g;
  b /= g;
  x *= c / g;
  y *= c / g;

  int mink = (int)ceil((double)-x / b);
  int maxk = (int)floor((double)y / a);

  // cout << x << " " << y << " " << mink << " " << maxk << endl;
  // cout << x + mink * b << " " << x + maxk * b << endl;
  // cout << y - maxk * a << " " << y - mink * a << endl;

  if (mink > maxk)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}
