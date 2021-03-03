#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define LL long long

#define FOR(i, j, k, s) for (int(i) = (j); (i) < (k); (i) += (s))

using namespace std;

int solve(vector<int> &a, vector<int> &b) {
  int n = a.size(), m = b.size();
  if (m == 0) return 0;

  // FOR(i, 0, n, 1) { cout << a[i] << " "; }
  // cout << endl;
  // FOR(i, 0, m, 1) { cout << b[i] << " "; }
  // cout << endl;

  // Try to figure out for each half, what is the number of boxes currently in
  // the special positions, starting from index a[i].
  // nums[i] gives the # of boxes of the condition above including a[i].
  // a = { 1, 5, 9 };
  // b = { 5, 8 };
  // nums[a[3]] = 0
  // nums[a[2]] = find(a[2]) in b + nums[a[3]];
  vector<int> nums(n);
  for (int i = n - 1; i >= 0; i--) {
    nums[i] = binary_search(b.begin(), b.end(), a[i]);
    if (i != n - 1) nums[i] += nums[i + 1];
  }

  // for (int i = 0; i < n; i++) {
  //   cout << "nums[a[" << i << "] = " << a[i] << "] = " << nums[i] << endl;
  // }

  int maxVal = 0;

  // This queue is persist.
  queue<int> Q;  // will be filled with b index.

  // Try to maximize the right half first.
  for (int i = 0; i < n; i++) {
    // The moving range of the current box will be [a[i], a[i+1] or b[m-1]]
    int width = i + 1;
    // cout << "width = " << width << endl;

    int LB = a[i], UB = (i == n - 1 ? b[m - 1] + 1 : a[i + 1]);
    // cout << "[LB, UB) = [" << LB << ", " << UB << ")" << endl;

    // Find b's range in [LB, UB).
    vector<int>::iterator bi = lower_bound(b.begin(), b.end(), LB);
    vector<int>::iterator bj = lower_bound(b.begin(), b.end(), UB);

    if (bi == b.end()) {
      break;
    } else {
      // cout << "bi = " << bi - b.begin() << ", bj = " << bj - b.begin() <<
      // endl; cout << "b[bi] = " << *bi
      //      << ", b[bj] = " << (bj == b.end() ? "END" : to_string(*bj)) <<
      //      endl;

      if (*bi >= UB) {
        // cout << "NO b in [LB, UB) " << endl;
        continue;
      }

      for (vector<int>::iterator bk = bi; bk != bj; bk++) {
        while (!Q.empty() && *bk - b[Q.front()] >= width) Q.pop();
        Q.push(bk - b.begin());

        int currSize = Q.size() + (i == n - 1 ? 0 : nums[i + 1]);
        maxVal = max(maxVal, currSize);
        // cout << "maxVal = " << maxVal << endl;
      }
    }
  }
  // cout << "maxVal = " << maxVal << endl;
  return maxVal;
}

int main(int argc, char *argv[]) {
  // Placeholder

  int T;
  cin >> T;
  FOR(t, 0, T, 1) {
    int n, m;
    cin >> n >> m;

    vector<int> a1, a2, b1, b2;
    // a1.reserve(n);
    // a2.reserve(n);
    // b1.reserve(m);
    // b2.reserve(m);

    FOR(i, 0, n, 1) {
      int a;
      cin >> a;
      if (a > 0)
        a2.push_back(a);
      else
        a1.push_back(-a);
    }
    FOR(i, 0, m, 1) {
      int b;
      cin >> b;
      if (b > 0)
        b2.push_back(b);
      else
        b1.push_back(-b);
    }
    reverse(a1.begin(), a1.end());
    reverse(b1.begin(), b1.end());

    int ans = solve(a1, b1) + solve(a2, b2);
    cout << ans << endl;
    // cout << "ANS = " << ans << endl;
    // cout << "<<<<<<<<<<<<<<<<<<<" << endl;
  }

  return 0;
}
