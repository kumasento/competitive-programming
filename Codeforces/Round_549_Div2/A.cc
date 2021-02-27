#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];

  int ll = 0, lr = 0;
  for (int i = 0; i < n; i++) {
    if (d[i] == 0)
      ll = i;
    else
      lr = i;
  }

  cout << std::min(ll, lr) + 1 << endl;

  return 0;
}