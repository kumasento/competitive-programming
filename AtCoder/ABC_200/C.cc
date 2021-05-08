#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int N; cin >> N;
  vector<int> A(N); for (int &i : A) cin >> i;

  vector<int> hash(200, 0);
  for (int i : A) hash[i % 200] ++;

  LL ans = 0;
  for (int i = 0; i < 200; i ++) {
    LL M = hash[i];
    if (M >= 2) {
      ans += M * (M - 1) / 2;
    }
  }

  cout << ans << endl;
}
