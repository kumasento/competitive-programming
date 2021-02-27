#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define LL long long

using namespace std;

int main(int argc, char *argv[]) {
  int T, N;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i].first;
      A[i].second = i;
    }

    // Sort by the token numbers.
    sort(A.begin(), A.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.first < b.first;
         });

    // Calculate prefix sum for each of them.
    vector<LL> P(N);
    P[0] = A[0].first;
    for (int i = 1; i < N; i++) P[i] = P[i - 1] + A[i].first;

    // The winning player.
    int wp = N - 1;
    for (int i = N - 2; i >= 0; i--) {
      // Find the player with the largest token below P[i].
      auto it = upper_bound(
          A.begin(), A.end(), P[i],
          [](LL p, const pair<int, int> &a) { return p < a.first; });
      // cout << "p = " << P[i] << " ub = " << it - A.begin() << " wp = " << wp
      //      << endl;

      if (it - A.begin() - 1 >= wp)
        wp = i;
      else
        break;
    }

    vector<int> ans;
    for (int i = wp; i < N; i++) ans.push_back(A[i].second);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto v : ans) cout << v + 1 << " ";
    cout << endl;
  }

  return 0;
}
