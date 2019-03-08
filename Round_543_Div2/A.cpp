#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
  int m, n, k;

  std::cin >> n >> m >> k;

  vector<int> p(n);
  for (int i = 0; i < n; i++) std::cin >> p[i];

  vector<int> mp(m, 0);  // max power for each school
  vector<int> mi(m, 0);  // student indices
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    s--;
    if (mp[s] < p[i]) {
      mp[s] = p[i];
      mi[s] = i;
    }
  }

  int cnt = 0;
  std::sort(mi.begin(), mi.end());

  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;

    c--;

    if (std::binary_search(mi.begin(), mi.end(), c)) continue;

    cnt++;
  }

  std::cout << cnt << std::endl;

  return 0;
}