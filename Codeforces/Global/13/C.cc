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
    int N;
    cin >> N;

    vector<int> S(N);
    FOR(i, 0, N, 1) { cin >> S[i]; }

    LL ans = 0L;
    vector<int> P(N + 1, 0);
    FOR(i, 0, N, 1) {
      LL tmp = P[i];
      if (tmp < S[i] - 1) {
        ans += S[i] - 1 - tmp;
        tmp += S[i] - 1 - tmp;
      }

      // Need to carry the extra stuff
      P[i + 1] += tmp - S[i] + 1;
      FOR(j, i + 2, min(i + S[i] + 1, N), 1) { P[j]++; }
    }

    cout << ans << endl;
  }

  return 0;
}
