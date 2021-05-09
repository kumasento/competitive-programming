#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  LL t, N; cin >> t >> N;

  for (LL i = 0; i <= 99; i ++) {
    LL tA = 100LL * N + i;
    if (tA % t == 0 && tA % 100 == i) {
      cout << tA / t + (tA / 100) - 1 << endl;
      return 0;
    }
  }
}
