#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;
  while (t --) {
    int n; cin >> n; string s; cin >> s;

    vector<bool> seen(26, false);

    char c = s[0];
    bool ok = true;
    for (int i = 1; i < s.length(); i ++) {
      if (s[i] == c)
        continue; 
      
      seen[c - 'A'] = true;

      if (seen[s[i] - 'A']) {
        ok = false;
        break;
      }

      c = s[i];
    }

    if (ok) cout  << "YES" << endl;
    else cout  << "NO" << endl;

  }
}
