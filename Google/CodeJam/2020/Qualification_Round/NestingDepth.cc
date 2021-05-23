#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    string S;
    cin >> S;

    string ans;
    for (int i = 0; i < S.size(); i++) {
      if (i == 0)
        ans += string(S[i] - '0', '(');
      else if (S[i] > S[i - 1])
        ans += string(S[i] - S[i - 1], '(');

      ans += S[i];

      if (i == S.size() - 1)
        ans += string(S[i] - '0', ')');
      else if (S[i] > S[i + 1])
        ans += string(S[i] - S[i + 1], ')');
    }

    cout << "Case #" << t + 1 << ": " << ans << endl;
  }

  return 0;
}
