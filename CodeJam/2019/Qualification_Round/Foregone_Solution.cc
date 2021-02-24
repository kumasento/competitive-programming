#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;

  for (int t =0; t < T; t ++) {
    string N;
    cin >> N;

    string A, B;

    for (int i = N.size() - 1; i >= 0; i --) {
      if (N[i] != '4') {
        A.push_back(N[i]);
        B.push_back('0');
      } else {
        // Since at least one digit in N is 4, B should be a valid number.
        A.push_back('2');
        B.push_back('2');
      }
    }

    // Trim leading zeros.
    std::reverse(A.begin(), A.end());
    std::reverse(B.begin(), B.end());

    int firstNonZero = -1;
    for (int i = 0; i < B.size(); i ++) {
      if (B[i] != '0') {
        firstNonZero = i;
        break;
      }
    }

    B = B.substr(firstNonZero, B.size() - firstNonZero);

    cout << "Case #" << t + 1 << ": " << A << " " << B << endl;
  }

  return 0;
}
