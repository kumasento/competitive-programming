#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int N; cin >> N;
  vector<int> A(N); for (int &i: A) cin >> i;

  // knapsack
  vector seqs(201, vector<int>());
  vector<bool> dp(201, false);
  dp[0] = true;

  vector<int> ans1, ans2;
  for (int i = 0; ans1.empty() && ans2.empty() && i < N; i ++) {
    vector<bool> dp2(dp);
    for (int S = 199; S >= 0; S --) {
      int T = ((((LL) S - A[i]) % 200) + 200) % 200;
      if (dp2[T]) {
        // A[i] + T = S mod 200
        // If T == S, we should make sure that A[i] itself can form a subsequence
        // whose sum is T (or S).
        if (dp2[S] && (T != S || A[i] % 200 == S) && !seqs[S].empty()) {
          ans1 = seqs[S];
          ans2 = (S == T) ? vector<int>() : seqs[T];
          ans2.push_back(i);
          break;
        } else {
          dp[S] = true;
          seqs[S] = seqs[T];
          seqs[S].push_back(i);
        }
      }
    }
  }

  if (ans1.empty() || ans2.empty())
    cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    cout << ans1.size() << " ";
    for (int i : ans1) cout << i + 1 << " ";
    cout << endl;
    cout << ans2.size() << " ";
    for (int i : ans2) cout << i + 1 << " ";
    cout << endl;
  }
}
