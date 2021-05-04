#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
  int prev = 1, curr = 1;
  LL sum = 0;

  while (curr <= 4e6) {
    if ((curr & 1) == 0)
      sum += curr;
    swap(prev, curr);
    curr += prev;
  }

  cout << sum << endl;
}
