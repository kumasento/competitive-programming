// GIVEUP
#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<int>>;

/**
 * The key idea behind this solution is not to directly compare an original
 * matrix and its transposed string - we try to find the invariant that
 * doesn't change during transposing.
 *
 * And the invariant is the anti-diagonal.
 */
class Solution {
 public:
  bool CanBeTransposed(Matrix &A, Matrix &B) {
    int N = A.size(), M = A[0].size();

    // build the diagonals
    vector<vector<int>> AD(N + M), BD(N + M);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> A[i][j];
        AD[i + j].push_back(A[i][j]);
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> B[i][j];
        BD[i + j].push_back(B[i][j]);
      }
    }

    for (int i = 0; i < N + M; i++) {
      std::sort(AD[i].begin(), AD[i].end());
      std::sort(BD[i].begin(), BD[i].end());

      for (int j = 0; j < AD[i].size(); j++) {
        if (AD[i][j] != BD[i][j]) return false;
      }
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;

  Matrix A(n, vector<int>(m, 0)), B(n, vector<int>(m, 0));

  Solution sol;
  std::cout << (sol.CanBeTransposed(A, B) ? "YES" : "NO") << std::endl;

  return 0;
}