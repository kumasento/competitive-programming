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

  int Q;
  cin >> Q;
  FOR(q, 0, Q, 1) {
    LL u, v;
    cin >> u >> v;

    if (v < u) {
      cout << "NO" << endl;
      continue;
    }

    int c = 0;
    while (u > 0) {
      if (u & 1) {
        c++;
      }
      if (v & 1) {
        if (c == 0) {
          cout << "NO" << endl;
          break;
        }
        c--;
      }
      u = u >> 1;
      v = v >> 1;
    }

    if (u != 0) continue;

    while (v > 0) {
      if (v & 1) {
        if (c == 0) {
          cout << "NO" << endl;
          break;
        }

        c--;
      }

      v = v >> 1;
    }

    if (v != 0) continue;

    cout << "YES" << endl;
  }

  return 0;
}
