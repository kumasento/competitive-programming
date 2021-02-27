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

#define LL long long

using namespace std;

int main(int argc, char *argv[]) {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> A(N, vector<int>(M)), B(N, vector<int>(M));

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> A[i][j];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> B[i][j];

  // Check if the values on the diagonal is a permutation of another.
  for (int i = 0; i < N + M; i++) {
    multiset<int> S;

    int r = min(N - 1, i), c = max(i - N, 0);
    // cout << r << " " << c << endl;

    for (int d = 0; d < max(N, M); d++) {
      if (r - d < 0 || c + d >= M) break;

      // cout << "(" << r - d << ", " << c + d << ") ";

      S.insert(A[r - d][c + d]);
      // cout << "Insert " << A[r - d][c + d] << endl;
    }
    // cout << endl;
    for (int d = 0; d < max(N, M); d++) {
      if (r - d < 0 || c + d >= M) break;

      // cout << "Try to erase " << B[r - d][c + d] << endl;
      if (S.count(B[r - d][c + d])) {
        S.erase(S.find(B[r - d][c + d]));
      } else {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;

  return 0;
}
