#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;

    vector<vector<int>> coords;

    vector<vector<char>> board(N, vector<char>(N));
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        cin >> board[i][j];

        if (board[i][j] == '*')
          coords.push_back({i, j});
      }

    // Two cases
    // 1. if two points are not on the same axis
    // 2. if they are on the same axis, we should figure out it is the y or the
    // x axis. And then we find two other points that draw a segment in
    // parallel.

    if (coords[0][0] != coords[1][0]) {
      if (coords[0][1] != coords[1][1]) {
        // Case #1
        board[coords[0][0]][coords[1][1]] = '*';
        board[coords[1][0]][coords[0][1]] = '*';
      } else {
        // Case #2: parallel to x
        int newY = (coords[0][1] + 1) % N;

        board[coords[0][0]][newY] = '*';
        board[coords[1][0]][newY] = '*';
      }
    } else {
      // Case #2: parallel to y
      int newX = (coords[0][0] + 1) % N;
      board[newX][coords[1][1]] = '*';
      board[newX][coords[0][1]] = '*';
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
        cout << board[i][j];
      cout << endl;
    }
  }
}
