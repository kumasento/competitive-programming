#include <bits/stdc++.h>
using namespace std;
#define LL long long

class MarriageAndCirclingChallenge {

public:

  long long solve(int N, int threshold, int state) {
    auto rnd = [&]() {
      state = ((LL) state * 1103515245 + 12345) % (1LL<<31);
      return state % 100;
    };

    vector<bitset<601>> g(N, bitset<601>(0));
    vector<bitset<601>> rg(N, bitset<601>(0));

    for (int i = 0; i < N; i ++) {
      for (int j = i + 1; j < N; j ++) {
        LL r = rnd();
        if (r < threshold) {
          g[i][j] = rg[j][i] = true;
        } else {
          g[j][i] = rg[i][j] = true;
        }
      }
    }

    LL ans = 0;
    for (int i = 0; i < N; i ++) {
      for (int j = i + 1; j < N; j ++) {
        auto u1 = g[i] & rg[j], u2 = rg[i] & g[j];
        u1 >>= i, u2 >>= i;
        ans += u1.count() * u2.count();
      }
    }

    return ans;
  }

};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  MarriageAndCirclingChallenge sol;
  cout << sol.solve(600, 47, 42) << endl;
}
