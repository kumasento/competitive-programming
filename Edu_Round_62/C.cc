#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main(int argc, char* argv[]) {
  int n, k;
  cin >> n >> k;

  // <beauty, length>
  vector<pair<int, int>> s(n);
  for (int i = 0; i < n; i++) cin >> s[i].second >> s[i].first;

  // sort
  sort(s.begin(), s.end());

  // set of selected songs
  // <length, id>
  set<pair<int, int>> a;
  LL sum = 0L;
  LL res = 0L;

  for (int i = n - 1; i >= 0; i--) {
    a.insert(make_pair(s[i].second, i));
    sum += s[i].second;

    while (a.size() > k) {
      // pop out the shortest
      auto it = a.begin();
      sum -= it->first;
      a.erase(it);
    }

    res = max(res, sum * s[i].first);
  }

  cout << res << endl;

  return 0;
}