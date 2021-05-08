#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int N = (int) 1e7 + 100;

LL s[N];
int d[N], ans[N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  fill (d, d + N, -1);
  d[1] = 1;

  for (int i = 2; i * i < N; i ++) {
    if (d[i] == -1) {
      d[i] = i;
      for (int j = i * i; j < N; j += i)
        if (d[j] == -1)
          d[j] = i;
    }
  }

  s[1] = 1;
  for (int i = 2; i < N; i ++) {
    if (d[i] == -1) {
      d[i] = i;
      s[i] = i + 1;
    } else {
      // given a prime factor p, suppose i % (p^k),
      // we calculate s[i] = 1 + p + p^2 + ... + p^k
      // by p(...(p(p + 1) + 1) ...) + 1
      int j = i;
      s[i] = 1;
      while (j % d[i] == 0) {
        j /= d[i];
        s[i] = s[i] * d[i] + 1;
      }
      s[i] *= s[j];
    }
  }

  fill(ans, ans + N, -1);
  // find the smallest i 
  for (int i = N - 1; i > 0; i --) {
    if (s[i] < N)
      ans[s[i]] = i;
  }

  int t; cin >> t;
  while (t --) {
    int c; cin >> c; 
    cout << ans[c] << endl;
  }
}
