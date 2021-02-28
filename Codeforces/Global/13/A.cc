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

#define FOR(i, j, k, s) for (int i = (j); i < (k); i += (s))

using namespace std;

int main(int argc, char *argv[]) {
  // Placeholder
  int N, Q;

  cin >> N >> Q;
  vector<int> A(N);
  int M = 0;  // number of 1s
  FOR(i, 0, N, 1) {
    cin >> A[i];
    if (A[i] == 1) M++;
  }

  FOR(q, 0, Q, 1) {
    int t, x;
    cin >> t >> x;

    if (t == 1) {
      if (A[x - 1] == 1)
        A[x - 1] = 0, M--;
      else
        A[x - 1] = 1, M++;
    } else if (t == 2) {
      if (x > M)
        cout << 0 << endl;
      else
        cout << 1 << endl;
    }
  }

  return 0;
}
