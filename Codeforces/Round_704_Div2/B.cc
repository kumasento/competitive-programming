#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define MAXN 100001

using namespace std;

int main(int argc, char *argv[]) {
  int t;
  int n, p[MAXN], q[MAXN];

  cin >> t;

  for (int ti = 0; ti < t; ti++) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];

    // greedy algorithm
    q[0] = p[0];
    for (int i = 1; i < n; i++) {
      q[i] = max(p[i], q[i - 1]);
      // cout << "q[i] = " << q[i] << endl;
    }

    int i = n - 2, j = n;
    while (i >= 0) {
      for (; i >= 0 && q[i] == q[i + 1]; i--)
        ;

      // i is the boundary.
      for (int k = i + 1; k < j; k++) cout << p[k] << " ";

      j = i + 1;
      i--;
    }

    if (j > 0)
      for (int k = i + 1; k < j; k++) cout << p[k] << " ";

    cout << endl;
  }

  return 0;
}
