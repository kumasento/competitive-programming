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
  int a, b, k;

  cin >> a >> b >> k;

  if (((a == 0 || b == 1) && k != 0) || (a != 0 && b != 1 && a + b - 2 < k)) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;

    for (int i = 0; i < b; i++) cout << '1';
    for (int i = 0; i < a; i++) cout << '0';
    cout << endl;

    cout << '1';
    if (k <= a) {
      for (int i = 0; i < b - 2; i++) cout << '1';
      for (int i = 0; i < k; i++) cout << '0';
      if (b >= 2) cout << '1';
      for (int i = 0; i < a - k; i++) cout << '0';
    } else {
      for (int i = 0; i < a + b - k - 2; i++) cout << '1';
      cout << '0';
      for (int i = 0; i < k - a; i++) cout << '1';
      for (int i = 0; i < a - 1; i++) cout << '0';
      cout << '1';
    }
    cout << endl;
  }

  return 0;
}
