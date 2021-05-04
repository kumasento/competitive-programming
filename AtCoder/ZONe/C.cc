// From the editorial
#include <bits/stdc++.h>

#define LL long long

using namespace std;

// Problems of the form of “maximum value of minimum value” can sometimes be
// solved easily by boiling it down to a yes-no problem of “can the answer be
// more than x?” and do binary search for the answer.

int main() {
  int N;
  cin >> N;

  vector A(N, array<int, 5>{});
  for (auto &a : A) for (auto &i : a) cin >> i;  

  // binary search the answer.
  int lo = 0, hi = 1000000001;

  auto check = [&](int x) -> bool {
    set<int> s;
    for (auto &a : A) {
      int bit = 0;
      // check if there is any value >= x
      for (int &i : a) {
        bit <<= 1;
        bit |= i >= x;
      }
      s.insert(bit);
    }

    // s only has space of O(32)

    for (int x : s) for (int y : s) for (int z : s) {
      // b11111
      if ((x | y | z) == 31) return 1;
    }

    return 0;
  };

  while (abs(lo - hi) > 1) {
    int mid = (lo + hi) / 2;
    (check(mid) ? lo : hi) = mid;
  }
  cout << lo << endl;
}
