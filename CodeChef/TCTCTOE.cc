#include <bits/stdc++.h>
using namespace std;
#define LL long long


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int T; cin >> T;
  int board[3][3];

  auto check_row = [&](int c, int i) {
    for (int j = 0; j < 3; j ++)
      if (board[i][j] != c)
        return 0;
    return 1;
  };

  auto check_col = [&](int c, int j) {
    for (int i = 0; i < 3; i ++)
      if (board[i][j] != c)
        return 0;
    return 1;
  };

  auto check_diag = [&](int c, int x, int y, int dx, int dy) {
    for (int d = 0; d < 3; d ++)
      if (board[x + dx * d][y + dy * d] != c)
        return 0;
    return 1;
  };

  auto check = [&](int c) {
    int cnt = 0;
    for (int i = 0; i < 3; i ++)
      cnt += check_row(c, i);
    for (int i = 0; i < 3; i ++)
      cnt += check_col(c, i);
    cnt += check_diag(c, 0, 0, 1, 1);
    cnt += check_diag(c, 0, 2, 1, -1);
    return cnt;
  };


  while (T --) {
    int num = 0, numX = 0;
    for (int i = 0; i < 3; i ++) {
      string S; cin >> S;
      for (int j = 0; j < 3; j ++) {
        board[i][j] = S[j] == '_' ? 0 : (S[j] == 'X' ? 1 : 2);
        if (!board[i][j])
          num ++;
        if (board[i][j] == 1)
          numX ++;
      }
    }

    int cnt1 = check(1), cnt2 = check(2);

    if (cnt1 + cnt2 > 1 || (abs(numX - (9 - num - numX)) > 1)) {
      cout << 3 << endl;
    } else if (cnt1 + cnt2 == 1) {
      cout << 1 << endl;
    } else {
      cout << ((num == 0) ? 1 : 2) << endl;
    }
  }

}
