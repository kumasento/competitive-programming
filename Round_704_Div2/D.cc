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

  if (a < k) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;

    for (int i = 0; i < b - 1; i++) cout << '1';
    for (int i = 0; i < a - k; i++) cout << '0';
    cout << '1';
    for (int i = 0; i < k; i++) cout << '0';
    cout << endl;

    for (int i = 0; i < b - 1; i++) cout << '1';
    for (int i = 0; i < a - k; i++) cout << '0';
    for (int i = 0; i < k; i++) cout << '0';
    cout << '1' << endl;
  }

  return 0;
}
