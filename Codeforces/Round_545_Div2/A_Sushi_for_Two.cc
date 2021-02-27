#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int FindMaxLengthOfValidSeg(int n, vector<int> &t) {
    int max_len = INT_MIN;

    for (int i = 0; i < n - 1; i++) {
      int j = i + 1;  // looking at t[i] and t[j]
      if (t[i] == t[j]) continue;

      int lt = t[i], rt = t[j];
      int k = 1;
      while (j + k < n && i - k >= 0 && t[i - k] == lt && t[j + k] == rt) k++;

      max_len = std::max(max_len, k * 2);
    }

    return max_len;
  }
};

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; i++) cin >> t[i];

  Solution sol;

  cout << sol.FindMaxLengthOfValidSeg(n, t) << endl;

  return 0;
}