#include <bits/stdc++.h>
using namespace std;
#define LL long long

int win(vector<string> &board) {

  auto check_row = [&](char c, int i) {
    for (int j = 0; j < 3; j ++)
      if (board[i][j] != c)
        return 0;
    return 1;
  };

  auto check_col = [&](char c, int j) {
    for (int i = 0; i < 3; i ++)
      if (board[i][j] != c)
        return 0;
    return 1;
  };

  auto check_diag = [&](char c, int x, int y, int dx, int dy) {
    for (int d = 0; d < 3; d ++)
      if (board[x + dx * d][y + dy * d] != c)
        return 0;
    return 1;
  };

  auto check = [&](char c) {
    int cnt = 0;
    for (int i = 0; i < 3; i ++)
      cnt += check_row(c, i);
    for (int i = 0; i < 3; i ++)
      cnt += check_col(c, i);
    cnt += check_diag(c, 0, 0, 1, 1);
    cnt += check_diag(c, 0, 2, 1, -1);
    return cnt;
  };

  return check('X') ? 1 : (check('O') ? 2 : 0);
}

map<vector<string>, int> status;

void dfs(int step, vector<string> &board) {
  if (status.count(board))
    return ;
  if (win(board) || step == 9) {
    status[board] = 1;
    return ;
  }

  status[board] = 2;

  char piece = (step & 1) ? 'O' : 'X'; // 0 is X, 1 is O.
  for (int i = 0; i < 3; i ++)
    for (int j = 0; j < 3; j ++)
      if (board[i][j] == '_') {
        board[i][j] = piece;
        dfs(step + 1, board);
        board[i][j] = '_'; // unset
      }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int T; cin >> T;
  vector<string> board{"___", "___", "___"};
  dfs(0, board);

  while (T --) {
    int num = 0, numX = 0;
    for (int i = 0; i < 3; i ++) {
      string S; cin >> S;
      board[i] = S;
    }

    if (status.count(board))
      cout << status[board] << endl;
    else
      cout << 3 << endl;
  }
}
