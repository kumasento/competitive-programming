#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  double r = 0.5 * sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  double x3 = (x1 + x2) / 2, y3 = (y1 + y2) / 2;
  double deg1 = atan2(y1 - y3, x1 - x3) / M_PI * 180;
  double deg2 = deg1 + 360.0 / N;
  double dx = r * cos(deg2 * M_PI / 180), 
         dy = r * sin(deg2 * M_PI / 180);
  cout.precision(17);
  cout << x3 + dx << " " << y3 + dy << endl;
}
