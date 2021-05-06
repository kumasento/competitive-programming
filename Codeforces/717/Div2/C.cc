#include <bits/stdc++.h>
using namespace std;
#define LL long long

bool bad(vector<int> &v) {
  int s = accumulate(v.begin(), v.end(), 0);
  if (s & 1) // odd sum cannot be partitioned.
    return false;

  // b[i] indicates i can be summed from a subset of v.
  bitset<200005> b;
  b[0] = 1; for (int i : v) b |= (b << i);
  return b[s / 2];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n; vector<int> a(n); for (int &i: a) cin >> i;

  if (bad(a)) {
    // find the element with the smallest LSB.
    // It can be odd, or an even value that will first become odd.

    pair<int, int> mn(20, 0); // {# trailing zeros, idx}
    for (int i = 0; i < n; i ++)
      mn = min(mn, make_pair(__builtin_ctz(a[i]), i + 1));
    cout << 1 << '\n' << mn.second << '\n';
  } else {
    cout << 0 << '\n';
  }
}
