#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    string s;
    cin >> n >> s;

    int lc = 0, rc = 0;  // count < from left and > from right
    while (lc < n && s[lc] != '>') lc++;
    while (rc < n && s[n - rc - 1] != '<') rc++;

    cout << std::min(lc, rc) << endl;
  }

  return 0;
}