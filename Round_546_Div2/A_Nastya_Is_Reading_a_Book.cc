#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int NumberOfChaptersNotRead(vector<int> &L, vector<int> &R, int k) {
    for (int i = 0; i < L.size(); i++) {
      // if i is within the page range of the current chapter,
      // then this chapter is not finished yet, we should count it.
      if (k >= L[i] && k <= R[i]) return L.size() - i;
    }
  }
};

int main(int argc, char *argv[]) {
  int n;
  cin >> n;

  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

  int k;
  cin >> k;

  Solution sol;
  cout << sol.NumberOfChaptersNotRead(l, r, k) << endl;

  return 0;
}