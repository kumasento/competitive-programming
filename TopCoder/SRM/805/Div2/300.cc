#include <bits/stdc++.h>
using namespace std;
#define LL long long

class GalleryIllumination {
public:
  int countDarkCells(int R, int C, vector <string> floorPlan) {
    vector<vector<bool>> dark(R, vector<bool>(C, true));

    for (int i = 0; i < R; i ++) {
      for (int j = 0; j < C; j ++) {
        if (floorPlan[i][j] == 'O') {
          for (int k = 1; j + k < C && floorPlan[i][j + k] != '#'; k ++)
            dark[i][j + k] = false;
          for (int k = 1; j - k >= 0 && floorPlan[i][j - k] != '#'; k ++)
            dark[i][j - k] = false;
          for (int k = 1; i + k < R && floorPlan[i + k][j] != '#'; k ++)
            dark[i + k][j] = false;
          for (int k = 1; i - k >= 0 && floorPlan[i - k][j] != '#'; k ++)
            dark[i - k][j] = false;
        }
      }
    }

    LL cnt = 0;
    for (int i = 0; i < R; i ++) {
      for (int j = 0; j < C; j ++) {
        if (dark[i][j] && floorPlan[i][j] == '.') {
          cnt ++;
        }
      }
    }
    return cnt;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
