#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define MX 100000      // max a
#define LOG 20         // 2^LOG is the maximum step (~10^6).
vector<int> p[100005]; // p[i]: the prime factors of value i, including itself.
int dp[LOG][100005];   // dp[i][j]:
int nex[100005];       //

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;

  for (int i = 2; i <= MX; i++) {
    if (p[i].empty()) { // i is prime.
      nex[i] = n; // nex[i] on prime will go out of scope.
      for (int j = i; j <= MX; j += i)
        p[j].push_back(i);
    }
  }

  dp[0][n] = n;
  for (int i = n - 1; i >= 0; i --) {
    dp[0][i] = dp[0][i + 1];
    // just take over from the next element.
    for (int j : p[a[i]]) { // all the prime factors of a[i].
      // j is a prime, nex[j] should be n + 1 in the beginning.
      dp[0][i] = min(dp[0][i], nex[j]);
      // now we update the furthest we can reach with j to i.
      nex[j] = i;
    }

    // dp[0][i] will be the min of the nex[j] among all its prime factors.
    // calculate from right to left.
  }

  for (int i = 1; i < 20; i ++) 
    for (int j = 0; j <= n; j ++)
      dp[i][j] = dp[i-1][dp[i-1][j]]; // when i = 1, it's like jumping twice.


  while (q --) {
    int l, r, ans = 0;
    cin >> l >> r; l --, r --;

    for (int i = 19; i >= 0; i --) {
      if (dp[i][l] <= r) {
        ans += (1 << i);
        l = dp[i][l];
      }
    }

    cout << ans + 1 << endl;
  }
}
