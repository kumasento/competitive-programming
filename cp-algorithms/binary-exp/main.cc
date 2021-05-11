#include <bits/stdc++.h>

using namespace std;

#define LL long long

LL binpow(LL b, LL e) {
  LL r = 1LL;
  while (e > 0) {
    if (e & 1)
      r *= b;
    b *= b;
    e >>= 1;
  }

  return r;
}

int main() {
  for (int i = 0; i < 20; i++)
    cout << binpow(2, i) << endl;
}
