#include <bits/stdc++.h>
using namespace std;
#define LL long long

bool solve(string &s, int a, int b) {
  LL n = a + b;

  if (n % 2 == 0) {
    // odd + odd cannot work.
    if (a % 2 == 1)
      return false;
  }

  array<LL, 2> cnts{a, b};

  for (LL i = 0, j = n - 1; i <= j; i ++, j --) {
    if (s[i] != '?' || s[j] != '?') {
      if (s[i] == '?')
        s[i] = s[j], cnts[s[i] - '0'] -= 2;
      else if (s[j] == '?')
        s[j] = s[i], cnts[s[i] - '0'] -= 2;
      else {
        if (s[i] != s[j])
          return false;
        cnts[s[i] - '0'] -= 2;
      }

      if (i == j) cnts[s[i] - '0'] ++;
      if (cnts[0] < 0 || cnts[1] < 0)
        return false;
    }
  }


  for (LL i = 0, j = n - 1; i <= j; i ++, j --) {
    if (s[i] == '?' && s[j] == '?') {
      if (cnts[0] >= cnts[1])
        s[i] = s[j] = '0', cnts[0] -= (1 + (i != j));
      else
        s[i] = s[j] = '1', cnts[1] -= (1 + (i != j));
    }

    if (cnts[0] < 0 || cnts[1] < 0)
      return false;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;
  while (t --) {
    int a, b; cin >> a >> b;
    string s; cin >> s;

    if (solve(s, a, b)) {
      cout << s << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
