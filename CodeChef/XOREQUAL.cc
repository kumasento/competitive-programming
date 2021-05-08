#include <bits/stdc++.h>
using namespace std;
#define LL long long

int binpower(int base, int exp, int mod) {
  int res = 1;
  while (exp > 0) {
    if (exp & 1) res = ((LL)res * base) % mod;
    base = ((LL)base * base) % mod;
    exp >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);


  int T; cin >> T;
  while (T --) {
    int N; cin >> N;

    cout << binpower(2, N - 1, 1000000007) << endl;
  }
}
