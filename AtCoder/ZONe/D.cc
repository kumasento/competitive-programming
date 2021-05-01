#include <bits/stdc++.h>

#define LL long long

using namespace std;



int main() {
  string S; cin >> S;
  string T;

  string T1, T2;
  int rev = 0;
  for (int i = S.length() - 1; i >= 0; i --) {
    if (S[i] == 'R')
      rev = 1 - rev;
    else {
      if (rev == 0)
        T2.push_back(S[i]);
      else
        T1.push_back(S[i]);
    }
  }
  reverse(T2.begin(), T2.end());
  T = T1 + T2;

  string G;
  for (char c : T) {
    if (c == G.back())
      G.pop_back();
    else
      G.push_back(c);
  }

  cout << G << endl;
}
