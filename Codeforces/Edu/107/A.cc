#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;
  while (t --) {
    int n; cin >> n;
    vector<int> r(n); for (int &i : r) cin >> i;

    array<int, 3> cnts{0};
    for (int i : r) cnts[i - 1] ++; 

    cout << cnts[0] + cnts[2] << endl;
  }
}
