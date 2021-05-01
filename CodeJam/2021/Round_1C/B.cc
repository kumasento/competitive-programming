#include <bits/stdc++.h>

#define LL long long

using namespace std;

string inc(string S) {
  int carry = 1;
  string T;
  for (int i = S.length() - 1; i >= 0; i --) {
    int n = S[i] - '0' + carry;
    if (n >= 10) {
      carry = n / 10;
      T.push_back((n % 10) + '0');
    } else {
      carry = 0;
      T.push_back(n + '0');
    }
  }
  if (carry)
    T.push_back('0' + carry);
  reverse(T.begin(), T.end());
  return T;
}

bool check(const string &S, int i) {
  string num = S.substr(0, i);
  string nxt = inc(num);
  int cur = i;

  while (cur < S.length()) {
    if (S.substr(cur, nxt.length()) != nxt) 
      return false;
    cur += nxt.length();
    nxt = inc(nxt);
  }

  return true;
}

bool is_roaring(string S) {
  for (int i = 1; i <= S.length() / 2; i ++) 
    if (check(S, i))
      return true;
  return false;
}

int main() {

  int T; cin >> T;

  for (int t = 1; t <= T; t ++) {
    string Y; cin >> Y; 
    Y = inc(Y);
    while (!is_roaring(Y)) 
      Y = inc(Y);

    cout << "Case #" << t << ": " << Y << endl;
  }

}
