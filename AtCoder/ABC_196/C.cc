#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  LL N; cin >> N;

  LL cnt = 0, scale = 10;
  for (int i = 1; i <= N; i ++) {
    if (i >= scale)
      scale *= 10;
    LL n = scale * i + i;
    if (n > N)
      break;
    cnt ++;
  }

  cout << cnt << endl;
}
