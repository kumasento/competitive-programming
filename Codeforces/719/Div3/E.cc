#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  int t; cin >> t;
  while (t --) {
    // cout << " -- " << t << endl;
    int n; cin >> n; string s; cin >> s;

    vector<LL> pos; for (int i = 0; i < n; i ++) if (s[i] == '*') pos.push_back(i + 1); 
    LL m = pos.size();

    if (m == 0) {
      cout << 0 << endl;
      continue;
    }

    vector<LL> pre(m + 1, 0), suf(m + 1, 0);
    for (int i = 0; i < m; i ++)
      pre[i + 1] = pre[i] + pos[i] - 1;
    for (int i = 0; i < m; i ++)
      suf[i + 1] = suf[i] + (n - pos[m - i - 1]);

    LL ans = LONG_LONG_MAX;
    for (LL i = 0; i < m; i ++) {
      LL presum = 0, sufsum = 0;
      if (i > 0) 
        presum = (suf[m] - suf[m - i]) - i * (n - pos[i]) - ((i + 1) * i / 2);
      if (i < m - 1)
        sufsum = (pre[m] - pre[i + 1]) - (m - i - 1) * (pos[i] - 1) - ((m - i - 1) * (m - i) / 2); 

      // cout << presum << " " << sufsum << endl;
      ans = min(presum + sufsum, ans);
    }

    cout << ans << endl;
  }
}
