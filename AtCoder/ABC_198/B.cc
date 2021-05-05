#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  string S; cin >> S;

  while (!S.empty() && S.back() == '0') S.pop_back();

  if (S.empty())
    cout << "Yes" << endl; 
  else {
    for (int i = 0, j = S.length() - 1; i <= j; i ++,j --)
      if (S[i] != S[j]) {
        cout << "No" << endl;
        return 0;
      }

    cout << "Yes" << endl;
  }
}
