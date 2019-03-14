#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> SplitArtists(int n, vector<char> &c, vector<char> &a) {
    // initialise four arrays that contain indices that have different
    // abilities.
    vector<int> co, ao, bo, em;

    for (int i = 0; i < n; i++) {
      if (c[i] == '1' && a[i] == '1')
        bo.push_back(i);
      else if (c[i] == '1' && a[i] == '0')
        co.push_back(i);
      else if (c[i] == '0' && a[i] == '1')
        ao.push_back(i);
      else
        em.push_back(i);
    }

    // now we iterate the boundaries of all arrays, below
    // which we should assign to the first half
    int i = 0, j = 0, k = 0, s = 0;

    // we can summarise the following equations
    // i + j + k + s == n / 2
    // i + k = (bo.size() - k) + (ao.size() - j)
    // -> j = bo.size() - 2 * k - i + ao.size()

    // we need to iterate i and k (or j)
    vector<int> ans;

    for (int i = 0; i <= co.size(); i++) {
      for (int k = 0; k <= bo.size(); k++) {
        int j = bo.size() - 2 * k - i + ao.size();
        if (j < 0 || j > ao.size()) continue;

        int s = n / 2 - i - j - k;
        if (s < 0 || s > em.size()) continue;

        // now we have the final answer
        for (int t = 0; t < i; t++) ans.push_back(co[t]);
        for (int t = 0; t < j; t++) ans.push_back(ao[t]);
        for (int t = 0; t < k; t++) ans.push_back(bo[t]);
        for (int t = 0; t < s; t++) ans.push_back(em[t]);
        return ans;
      }
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<char> c(n), a(n);
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) cin >> a[i];

  Solution sol;
  auto ans = sol.SplitArtists(n, c, a);

  if (ans.size() < n / 2)
    cout << -1 << endl;
  else {
    for (auto i : ans) {
      cout << i + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}