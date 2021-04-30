#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int lo = INT_MIN, hi = INT_MAX, a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    lo = max(a, lo);
  }
  for (int i = 0; i < N; i++) {
    cin >> a;
    hi = min(a, hi);
  }

  if (lo <= hi)
    cout << hi - lo + 1 << endl;
  else
    cout << 0 << endl;
}
