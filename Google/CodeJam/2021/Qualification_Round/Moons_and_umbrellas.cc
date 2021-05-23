#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int X, Y;
    cin >> X >> Y;

    string S;
    cin >> S;

    int minCost = 0;
    int i = 0;
    while (i < S.length() - 1) {
      int j = i + 1;
      while (S[j] == '?') j++;

      if (j == S.length()) break;
      if (S[i] == 'C' && S[j] == 'J')
        minCost += X;
      else if (S[i] == 'J' && S[j] == 'C')
        minCost += Y;
      i = j;
    }

    cout << "Case #" << (t + 1) << ": " << minCost << endl;
  }
}
