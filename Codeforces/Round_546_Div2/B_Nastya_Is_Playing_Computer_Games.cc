#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int MinimumMoves(int n, int k) {
    if (k == 1 || k == n) return 3 * n;

    int m = min(n - k, k - 1);
    return 3 * n + m;
  }
};

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;

  Solution sol;
  cout << sol.MinimumMoves(n, k) << endl;

  return 0;
}