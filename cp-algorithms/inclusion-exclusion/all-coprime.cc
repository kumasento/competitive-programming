#include <bits/stdc++.h>
using namespace std;
#define LL long long

int solve(int n, int r) {
  vector<int> p;
  for (int i = 2; i <= n; i ++) {
    if (n % i == 0) {
      p.push_back(i);
      while (n % i == 0)
        n /= i;
    }
  }
  if (n > 1)
    p.push_back(n);

  int sum = 0;
  // msk select a subset of all prime factors.
  for (int msk = 1; msk < (1 << p.size()); ++ msk) {
    int mult = 1, bits = 0; // bits = number of selected primes.
    for (int i = 0; i < (int)p.size(); ++ i) {
      if (msk & (1 << i)) {
        ++ bits;
        mult *= p[i];
      }
    }

    int cur = r / mult;
    if (bits % 2 == 1) {
      sum += cur;
    } else {
      sum -= cur;
    }

    return r - sum;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
