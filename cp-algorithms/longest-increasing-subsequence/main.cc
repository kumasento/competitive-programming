#include <iostream>
#include <vector>

using namespace std;

int dp_lis(vector<int> a) {
  vector<int> d(a.size(), 1);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < i; j++)
      if (a[i] > a[j])
        d[i] = max(d[j] + 1, d[i]);
  }

  return *max_element(d.begin(), d.end());
}

vector<int> dp_lis_restore(vector<int> a) {
  vector<int> d(a.size(), 1), p(a.size(), -1);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < i; j++)
      if (a[i] > a[j] && d[j] + 1 > d[i]) {
        d[i] = d[j] + 1;
        p[i] = j;
      }
  }

  vector<int> seq;
  int e = max_element(d.begin(), d.end()) - d.begin();
  while (p[e] != -1) {
    seq.push_back(a[e]);
    e = p[e];
  }
  seq.push_back(a[e]);
  reverse(seq.begin(), seq.end());
  return seq;
}

int dp_lis2(vector<int> &a) {
  vector<int> d(a.size() + 1, INT_MAX);
  d[0] = INT_MIN;

  for (int i = 0; i < a.size(); i++) {
    for (int j = 1; j <= a.size(); j++) {
      // a[i] can be placed at d[j], if it is larger than d[j-1]
      // and also the current smallest d[j] candidates.
      // When d[j] is not there, it is INT_MAX.
      if (a[i] > d[j - 1] && a[i] < d[j]) {
        d[j] = a[i];
      }
    }
  }

  return lower_bound(d.begin(), d.end(), INT_MAX) - d.begin() - 1;
}

int dp_lis2_bs(vector<int> a) {
  int n = a.size();
  vector<int> d(n + 1, INT_MAX);
  d[0] = INT_MIN;

  for (int i = 0; i < n; i++) {
    // d[j] is strictly larger than a[i].
    int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
    // Do we need this condition?
    if (d[j - 1] < a[i] && a[i] < d[j])
      d[j] = a[i];
  }
  return lower_bound(d.begin(), d.end(), INT_MAX) - d.begin() - 1;
}

int main() {
  vector<int> a = {1, 9, 3, 6, 7, -8, 10, 25, 0};
  cout << dp_lis(a) << endl;

  vector<int> seq = dp_lis_restore(a);
  copy(seq.begin(), seq.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << dp_lis2(a) << endl;
  cout << dp_lis2_bs(a) << endl;
}
