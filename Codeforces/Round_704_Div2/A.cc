#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int t;
  long long a, b, c, p;
  long long q;

  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    cin >> p >> a >> b >> c;

    q = min(min((p % a == 0) ? 0 : a - p % a, (p % b == 0) ? 0 : b - p % b),
            (p % c == 0) ? 0 : c - p % c);
    cout << q << endl;
  }

  return 0;
}
