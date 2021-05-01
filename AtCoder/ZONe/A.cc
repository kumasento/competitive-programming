#include <bits/stdc++.h>

#define LL long long

using namespace std;



int main() {
  string S;
  cin >> S;

  size_t pos = S.find("ZONe");
  LL ans = 0;
  while (pos != string::npos) {
    ans ++; 
    pos = S.find("ZONe", pos + 1); 
  }

  cout << ans << endl;
}
