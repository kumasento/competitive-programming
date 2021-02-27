#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define LL long long

int main(int argc, char *argv[]) {
  int T, N;

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;

    LL n = 2L * N - 1;
    LL upper = (LL)sqrt((double)n);
    // cout << upper << endl;

    cout << ((upper % 2) ? (upper / 2) : (upper / 2 - 1)) << endl;
  }

  return 0;
}
