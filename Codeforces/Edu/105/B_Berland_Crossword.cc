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
    int n, U, R, D, L;
    cin >> n >> U >> R >> D >> L;

    bool hasAns = false;
    FOR(i, 0, 2, 1) {
      FOR(j, 0, 2, 1) {
        FOR(k, 0, 2, 1) {
          FOR(l, 0, 2, 1) {
            // cout << i << " " << j << " " << k << " " << l << endl;
            bool ok = true;

            if (U < i + j || R < j + l || D < k + l || L < i + k) ok = false;
            if (U > n - 2 + i + j || R > n - 2 + j + l || D > n - 2 + k + l ||
                L > n - 2 + i + k)
              ok = false;

            if (ok) hasAns = true;
          }
        }
      }
    }

    if (hasAns)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
