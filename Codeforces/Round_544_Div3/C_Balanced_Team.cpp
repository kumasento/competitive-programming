#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  std::sort(a.begin(), a.end());

  int max_ = 0;
  for (int i = 0; i < n; i++) {
    // skip equal cases
    if (i != 0 && a[i] == a[i - 1]) continue;

    int j = i + max_;  // starting point
    while (j < n && a[j] - a[i] <= 5) j++;

    max_ = std::max(max_, j - i);
  }

  std::cout << max_ << std::endl;

  return 0;
}