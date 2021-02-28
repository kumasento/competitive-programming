#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define LL long long

#define FOR(i, j, k, s) for (int(i) = (j); (i) < (k); (i) += (s))

using namespace std;

int main(int argc, char *argv[]) {
  // Placeholder
  int T;
  cin >> T;
  FOR(t, 0, T, 1) {
    int N, u, v;
    cin >> N >> u >> v;

    vector<int> A(N);
    FOR(i, 0, N, 1) { cin >> A[i]; }

    // No obstacle on the first column.
    int ans = INT_MAX;
    bool valid = true;
    for (int i = 1; i < N; i++) {
      if (A[i] != A[i - 1] - 1 && A[i] != A[i - 1] && A[i] != A[i - 1] + 1) {
        valid = false;
        break;
      }

      if (A[i] == A[i - 1])
        ans = min(min(u + v, v + v), ans);
      else
        ans = min(min(u, v), ans);
    }

    if (valid)
      cout << ans << endl;
    else
      cout << 0 << endl;
  }

  return 0;
}
