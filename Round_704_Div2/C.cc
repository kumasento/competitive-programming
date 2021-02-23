#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define MAXL 200002

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  char s[MAXL], t[MAXL];

  vector<vector<int>> pos(26);
  vector<int> ptr(26, 0);
  vector<int> freq(26, 0);

  cin >> n >> m >> s >> t;

  vector<vector<int>> post(n + 1, vector<int>(26, 0));

  // Iterate the string s to build up the char to positions map.
  // Example:
  // a: [0, 1]
  // b: [2, 3]
  // for aabb

  for (int i = 0; i < n; i++) pos[s[i] - 'a'].push_back(i);
  for (int i = n - 1; i >= 0; i--) post[i][s[i] - 'a']++;
  for (int i = 0; i < m; i++) freq[t[i] - 'a']++;

  int ans = INT_MIN, last = -1;
  for (int i = 0; i < m - 1; i++) {
    // Find positions for t[i] and s[i+1].

    freq[t[i] - 'a']--;
    int L = pos[t[i] - 'a'][ptr[t[i] - 'a']];
    int j = pos[t[i + 1] - 'a'].size() - freq[t[i + 1] - 'a'];
    // cout << j << endl;
    while (j >= ptr[t[i + 1] - 'a']) {
      bool isOk = true;
      for (int c = 0; c < 26; c++) {
        if (c != t[i + 1] - 'a' &&
            freq[c] > post[pos[t[i + 1] - 'a'][j] + 1][c]) {
          // cout << ((char)c + 'a') << " " << j << " " << freq[c] << " "
          //      << post[pos[t[i + 1] - 'a'][j] + 1][c] << endl;
          isOk = false;
          break;
        }
      }

      if (isOk) break;
      j--;
    }
    // cout << t[i + 1] << " " << j << endl;
    int R = pos[t[i + 1] - 'a'][j];

    ans = max(R - L, ans);

    // Move forward the pointer.
    while (ptr[t[i + 1] - 'a'] < pos[t[i + 1] - 'a'].size() &&
           pos[t[i + 1] - 'a'][ptr[t[i + 1] - 'a']] <= L)
      ptr[t[i + 1] - 'a']++;
  }

  cout << ans << endl;

  return 0;
}
