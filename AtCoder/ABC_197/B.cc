#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int H, W, X, Y; cin >> H >> W >> X >> Y;
  vector<string> S(H); for (auto &s : S) cin >> s;

  int ans = 1;
  for (int i = X + 1; i <= H; i ++) { if (S[i-1][Y-1] == '#') break; ans ++; }
  for (int i = X - 1; i >= 1; i --) { if (S[i-1][Y-1] == '#') break; ans ++; }
  for (int i = Y + 1; i <= W; i ++) { if (S[X-1][i-1] == '#') break; ans ++; }
  for (int i = Y - 1; i >= 1; i --) { if (S[X-1][i-1] == '#') break; ans ++; }

  cout << ans << endl;
}
