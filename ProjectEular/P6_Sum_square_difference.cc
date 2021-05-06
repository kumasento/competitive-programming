#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  LL ans = 0;
  for (int i = 1; i <= 100; i ++)
    for (int j = 1; j <= 100; j ++)
      if (i != j)
        ans += i * j;

  cout << ans << endl;
}
