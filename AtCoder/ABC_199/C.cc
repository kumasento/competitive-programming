#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, Q;
  string S;
  cin >> N >> S >> Q;

  string S1, S2;
  S1 = S.substr(0, N);
  S2 = S.substr(N);

  while (Q--) {
    int T, A, B;
    cin >> T >> A >> B;

    if (T == 1) {
      if (A - 1 >= N) {
        if (B - 1 >= N)
          swap(S2[A - 1 - N], S2[B - 1 - N]);
        else
          swap(S2[A - 1 - N], S1[B - 1]);
      } else {
        if (B - 1 >= N)
          swap(S1[A - 1], S2[B - 1 - N]);
        else
          swap(S1[A - 1], S1[B - 1]);
      }
    } else {
      swap(S1, S2);
    }
  }

  cout << S1 << S2 << endl;
}
