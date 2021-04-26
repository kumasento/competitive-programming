// TODO: stoll may have run-time issue. Try use big integer.
#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int ans = 0;

    int N;
    cin >> N;
    vector<string> X(N);
    for (int i = 0; i < N; i++)
      cin >> X[i];

    for (int i = 1; i < N; i++) {
      cout << X[i - 1] << " " << X[i] << endl;
      LL prev = stoll(X[i - 1]), curr = stoll(X[i]);
      if (curr > prev)
        continue;

      int L1 = X[i - 1].length(), L2 = X[i].length();

      if (L1 == L2) {
        X[i] += "0";
        ans++;
        continue;
      }

      int k = L1 - L2;
      string Y = X[i] + string(k, '0');
      if (stoll(Y) > prev) {
        X[i] = Y;
        ans += k;
        continue;
      }

      string Z = X[i] + string(k, '9');
      if (stoll(Z) > prev) {
        X[i] = to_string(prev + 1);
        ans += k;
        continue;
      }

      X[i] = Y + "0";
      ans += k + 1;
    }

    cout << "Case #" << (t + 1) << ": " << ans << endl;
  }
}
