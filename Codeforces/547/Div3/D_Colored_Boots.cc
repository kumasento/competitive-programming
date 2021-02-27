#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define LL long long

int main(int argc, char *argv[]) {
  int N;
  cin >> N;

  string L, R;
  cin >> L >> R;

  // Position map
  map<char, vector<int>> lm, rm;
  for (int i = 0; i < N; i++) lm[L[i]].push_back(i + 1);

  vector<pair<int, int>> ans;
  for (int i = 0; i < N; i++) {
    if (R[i] != '?') {
      // If R[i] can be matched by L.
      if (lm[R[i]].size() > 0) {
        ans.push_back(make_pair(lm[R[i]].back(), i + 1));
        lm[R[i]].pop_back();
        continue;
      }
    }
    // Otherwise, push the index in the map.
    rm[R[i]].push_back(i + 1);
  }

  for (auto &it : rm) {
    if (it.first == '?') continue;

    for (const auto &pos : it.second) {
      if (lm['?'].size() > 0) {
        ans.push_back(make_pair(lm['?'].back(), pos));
        lm['?'].pop_back();
      } else {
        break;
      }
    }
  }

  for (auto &it : lm) {
    if (it.first == '?') continue;

    for (const auto &pos : it.second) {
      if (rm['?'].size() > 0) {
        ans.push_back(make_pair(pos, rm['?'].back()));
        rm['?'].pop_back();
      } else {
        break;
      }
    }
  }

  for (int i = 0; i < lm['?'].size() && i < rm['?'].size(); i++)
    ans.push_back(make_pair(lm['?'][i], rm['?'][i]));

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }

  return 0;
}
