#include <bits/stdc++.h>
using namespace std;
#define LL long long

class MarriageAndChargingChallenge {
public:
  int solve(int forumLength, vector<int> relative, vector<int> greeting) {
    int cnt = 0, N = relative.size();

    for (int start = 0; start < N; start ++) {
      int curr = start, charge = 0;
      for (int n = 0; n < N; n ++) {
        int next = (curr + 1) % N;
        int dis;
        if (N == 1)
          dis = forumLength;
        else
          dis = (relative[next] - relative[curr] + forumLength) % forumLength;

        charge += greeting[curr] - dis;

        if (charge < 0)
          break;

        curr = next;
      }
      if (charge >= 0)
        cnt ++;
    }

    return cnt;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
