#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  int cnt[26];

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    memset(cnt, 0, sizeof(int) * 26);

    bool ok = true;
    for (int j = 0; j < s.size(); j++) {
      char c = s[j];
      int k = c - 'a';
      if (cnt[k] != 0) {
        ok = false;
        break;
      }
      cnt[k]++;
    }

    if (ok) {
      int j = 0;
      while (j < 26 && cnt[j] != 1) j++;
      while (j < 26 && cnt[j] == 1) j++;
      while (j < 26 && cnt[j] != 1) j++;

      ok = j == 26;
    }

    if (ok)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}