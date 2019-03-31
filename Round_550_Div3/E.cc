#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int k;
  cin >> k;
  string s, t;
  cin >> s >> t;

  int mi[k + 1];
  int carry = 0;
  for (int i = k - 1; i >= 0; i--) {
    int val = (t[i] - 'a') + (s[i] - 'a') + carry;
    mi[i + 1] = val % 26;
    carry = val / 26;
  }
  mi[0] = carry;

  // do division
  carry = 0;
  for (int i = 0; i < k + 1; i++) {
    int val = carry * 26 + mi[i];
    mi[i] = val / 2;
    carry = val % 2;
  }

  string m(k, ' ');
  for (int i = 1; i < k + 1; i++) {
    m[i - 1] = mi[i] + 'a';
  }

  cout << m << endl;

  return 0;
}