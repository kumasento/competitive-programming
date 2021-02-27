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

#define MAXL 200002

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  char s[MAXL], t[MAXL];

  cin >> n >> m >> s >> t;

  // DP based solution.
  // Given that left[i] is the minimum possible p for p_i, right[i] is the
  // maximum possible p for p_i. left[i] and right[i] can be calculated in a
  // DP/greedy algorithm.

  // Suppose we are looking at s = "abbbab" and t = "aba"

  // To find right[i] -
  //
  //   a b b b a b | right
  // a T F F       | 0
  // b       T     | 3
  // a         T F | 4

  // To find left[i] -
  //
  //   a b b b a b | left
  // a T           | 0
  // b   T         | 1
  // a     F F T   | 4

  int left[MAXL], right[MAXL];

  // Initialize right.
  int p, q;  // p for s, q for t.
  p = n - 1;
  for (q = m - 1; q >= 0; q--) {
    while (s[p] != t[q]) p--;
    // s[p] == t[q];
    right[q] = p;
    p--;
  }

  // Initialize left.
  p = 0;
  for (q = 0; q < m; q++) {
    while (s[p] != t[q]) p++;
    left[q] = p;
    p++;
  }

  int ans = INT_MIN;
  for (int i = 0; i < m - 1; i++) {
    ans = max(right[i + 1] - left[i], ans);
  }
  cout << ans << endl;

  return 0;
}
