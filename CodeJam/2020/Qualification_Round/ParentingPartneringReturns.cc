#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;

    // <S, E, i>
    vector<tuple<int, int, int>> acts(N);

    for (int i = 0; i < N; i++) {
      int S, E;
      cin >> S >> E;
      acts[i] = make_tuple(S, E, i);
    }

    sort(acts.begin(), acts.end(),
         [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
           int S1, E1, I1, S2, E2, I2;
           tie(S1, E1, I1) = a;
           tie(S2, E2, I2) = b;
           return S1 < S2 || (S1 == S2 && E1 < E2);
         });

    string ans;
    ans.resize(N);

    int E_C = -1, E_J = -1;
    for (int i = 0; i < N; i++) {
      int S, E, I;
      tie(S, E, I) = acts[i];

      if (S < E_C) {
        // Try J.
        if (S < E_J) {
          ans = "IMPOSSIBLE";
          break;
        }

        E_J = E;
        ans[I] = 'J';
      } else {
        E_C = E;
        ans[I] = 'C';
      }
    }

    cout << "Case #" << t + 1 << ": " << ans << endl;
  }

  return 0;
}
