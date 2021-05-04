#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s) {
  for (int i = 0, j =(int) s.length() - 1; i <= j; i ++, j --)
    if (s[i] != s[j])
      return false;

  return true;
}

int main() {
  int ans = 0;
  for (int i = 100; i <= 999; i ++) {
    for (int j = 100; j <= 999; j ++) {
      int prod = i * j;
      string s = to_string(prod);
      if (is_palindrome(s))
        ans = max(ans, prod);
    }
  }

  cout << ans << endl;
}
