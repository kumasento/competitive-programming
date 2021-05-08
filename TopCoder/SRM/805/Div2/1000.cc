#include <bits/stdc++.h>
using namespace std;
#define LL long long

class ThreeDChessRooks {
public:
  long long count(int C, int R, vector<int> XP, vector<int> YP, vector<int> ZP,
                  int seed) {
    vector<array<int, 3>> cells(R);

    int L = XP.size();
    for (int i = 0; i < L; ++i) {
      cells[i] = {XP[i], YP[i], ZP[i]};
    }

    long long state = seed;
    for (int i = L; i < R; ++i) {
      state = (state * 1103515245 + 12345) % (1LL << 31);
      cells[i][0] = state % C;
      state = (state * 1103515245 + 12345) % (1LL << 31);
      cells[i][1] = state % C;
      state = (state * 1103515245 + 12345) % (1LL << 31);
      cells[i][2] = state % C;
    }

    // dedup
    map<array<int, 3>, LL> S;
    for (int i = 0; i < R; i++)
      S[cells[i]]++;

    array<map<int, LL>, 3> hash;
    array<map<pair<int, int>, LL>, 3> hash2;

    auto plane = [](array<int, 3> cell, int k) -> pair<int, int> {
      if (k == 0)
        return {cell[1], cell[2]};
      if (k == 1)
        return {cell[0], cell[2]};
      return {cell[0], cell[1]};
    };

    for (auto cell : cells)
      for (int k = 0; k < 3; k++) {
        hash[k][cell[k]]++;
        hash2[k][plane(cell, k)]++;
      }

    // for (int k = 0; k < 3; k++) {
    //   cout << k << endl;
    //   for (auto &it : hash[k]) {
    //     cout << it.first << " -> " << it.second << "; ";
    //   }
    //   cout << endl;
    // }

    // for (int k = 0; k < 3; k++) {
    //   cout << k << endl;
    //   for (auto &it : hash2[k]) {
    //     cout << it.first.first << ", " << it.first.second << " -> " << it.second << "; ";
    //   }
    //   cout << endl;
    // }

    // if we use cell as Wanda
    LL ans = 0;
    for (auto cell : cells) {
      for (int k = 0; k < 3; k++)
        ans += hash[k][cell[k]] - 1;
      for (int k = 0; k < 3; k++)
        ans -= hash2[k][plane(cell, k)] - 1;
      // cout << ans << endl;

      for (int k = 0; k < 3; k++) {
        if (cell[k] == 0) {
          auto cell2(cell);
          cell2[k]++;
          if (S.count(cell2))
            ans -= S[cell2];
        } else if (cell[k] == C - 1) {
          auto cell2(cell);
          cell2[k]--;
          if (S.count(cell2))
            ans -= S[cell2];
        }
      }
      // cout << ans << endl;
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ThreeDChessRooks sol;
  cout << sol.count(2, 2, {1, 1}, {0, 1}, {0, 0}, 0) << endl;
}
