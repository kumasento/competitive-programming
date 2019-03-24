#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  int sum = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (i == max) {
      sum += 1;
      max = 0;
    }
    if (a[i] > max) {
      max = a[i];
    }
  }

  cout << sum << endl;

  return 0;
}