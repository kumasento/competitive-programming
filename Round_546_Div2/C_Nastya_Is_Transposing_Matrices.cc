// GIVEUP
#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<int>>;

struct Trans {
  int x, y, s;
  Trans(int x, int y, int s) : x(x), y(y), s(s) {}
};

class Solution {
 public:
  bool CanBeTransposed(Matrix &A, Matrix &B) { return BFS(A, B, 0, 0, 0); }

  bool BFS(Matrix &A, Matrix &B, int x, int y, int s) {
    // x, y, k defines the previous transpose
    int n = A.size(), m = A[0].size();

    if (IsIdentical(A, B)) return true;

    for (int k = 2; k <= min(n, m); k++) {
      for (int i = 0; i + k <= n; i++) {
        for (int j = 0; j + k <= m; j++) {
          if (i == x && j == y && k == s) continue;

          Transpose(A, i, j, k);
          if (IsIdentical(A, B)) return true;
          Transpose(A, i, j, k);
        }
      }
    }

    for (int k = 2; k <= min(n, m); k++) {
      for (int i = 0; i + k <= n; i++) {
        for (int j = 0; j + k <= m; j++) {
          if (i == x && j == y && k == s) continue;

          Transpose(A, i, j, k);
          if (BFS(A, B, i, j, k)) return true;
          Transpose(A, i, j, k);
        }
      }
    }

    return false;
  }

  void Transpose(Matrix &A, int x, int y, int k) {
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        if (i < j) std::swap(A[x + i][y + j], A[x + j][y + i]);
      }
    }
  }

  bool IsIdentical(Matrix &A, Matrix &B) {
    for (int i = 0; i < A.size(); i++) {
      for (int j = 0; j < A[0].size(); j++) {
        if (A[i][j] != B[i][j]) return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;

  Matrix A(n, vector<int>(m, 0)), B(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> A[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> B[i][j];

  Solution sol;
  cout << (sol.CanBeTransposed(A, B) ? "YES" : "NO") << endl;

  return 0;
}