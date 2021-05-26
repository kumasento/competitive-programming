/**
 * Author: kumasento
 * Date:   2021-05-26T16:01:22.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// Constants:
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// Globals:

/// Solution:

class TransposeColors {
public:

  vector<int> move(int N) {
    if (N == 1) return {};

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i ++) A[i].assign(N, i);

    // for (int i = 0; i < N; i ++){
    //   for (int j = 0; j < N; j ++)
    //     cout << A[i][j] << " ";
    //   cout << endl;
    // }
    
    vector<int> ans;
    ans.push_back(1);
    A[0][1] = N;

    for (int i = 0; i < N * N - N - 1; i ++) {
      int pos = ans.back(); int x = pos / N, y = pos % N;

      // for (int i = 0; i < N; i ++){
      //   for (int j = 0; j < N; j ++)
      //     cout << A[i][j] << " ";
      //   cout << endl;
      // }
      

      A[x][y] = y;
      for (int j = N - 1; j >= 0; j --) 
        if (A[y][j] == y && j != y) {
          A[y][j] = N;
          ans.push_back(y * N + j);
          break;
        }

      // cout << ans.back() << endl;
    }

    ans.push_back(N * N);

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("300.in"); cin.rdbuf(in.rdbuf());
#endif

  TransposeColors sol;
  cout << sol.move(39).size() << endl;;

}
