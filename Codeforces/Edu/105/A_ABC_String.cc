#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define LL long long

#define FOR(i, j, k, s) for (int(i) = (j); (i) < (k); (i) += (s))

using namespace std;

int main(int argc, char *argv[]) {
  // Placeholder
  int T;
  cin >> T;

  FOR(t, 0, T, 1) {
    string A;
    cin >> A;

    vector<int> cnts(3, 0);
    FOR(i, 0, A.size(), 1) { cnts[A[i] - 'A']++; }

    vector<int> grps(3, 0);
    grps[0] = 0, grps[1] = grps[2] = 1;
    if (cnts[0] != cnts[1] + cnts[2]) {
      if (cnts[1] == cnts[0] + cnts[2])
        swap(grps[0], grps[1]);
      else if (cnts[2] == cnts[0] + cnts[1])
        swap(grps[2], grps[0]);
      else {
        cout << "NO" << endl;
        continue;
      }
    }

    // cout << grps[0] << " " << grps[1] << " " << grps[2] << endl;

    // determine the binding.
    vector<char> brks(3);
    brks[A[0] - 'A'] = '(';
    FOR(i, 0, 3, 1) {
      if (grps[i] == grps[A[0] - 'A'])
        brks[i] = '(';
      else
        brks[i] = ')';
    }

    // FOR(i, 0, 3, 1) { cout << brks[i] << endl; }
    int x = 0;
    FOR(i, 0, A.size(), 1) {
      if (brks[A[i] - 'A'] == '(')
        x++;
      else
        x--;

      if (x < 0) break;
    }

    if (x != 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }

  return 0;
}
