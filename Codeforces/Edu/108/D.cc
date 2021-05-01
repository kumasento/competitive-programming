#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<LL> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  LL total = 0LL;
  for (int i = 0; i < n; i++)
    total += a[i] * b[i];

  LL best = total;
  for (int center = 0; center < n; center++) {
    LL curr = total;
    for (int x = center - 1, y = center + 1; x >= 0 && y < n; x--, y++) {
      curr -= a[x] * b[x] + a[y] * b[y];
      curr += a[x] * b[y] + a[y] * b[x];
      best = max(best, curr);
    }
  }

  for (int between = 0; between < n - 1; between++) {
    LL curr = total;
    for (int x = between, y = between + 1; x >= 0 && y < n; x--, y++) {
      curr -= a[x] * b[x] + a[y] * b[y];
      curr += a[x] * b[y] + a[y] * b[x];
      best = max(best, curr);
    }
  }

  cout << best << endl;
}
