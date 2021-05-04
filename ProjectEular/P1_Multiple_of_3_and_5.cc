#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
  LL sum = 0;
  for (int i = 1; i < 1000; i ++) {
    if (i % 3 == 0 || i % 5 == 0)
      sum += i;
  }
  cout << sum << endl;
}
