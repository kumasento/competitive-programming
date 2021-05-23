#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {

  int T; cin >> T;

  for (int t = 1; t <= T; t ++) {
    int N, K; cin >> N >> K;

    vector<int> P(N);
    for (int i = 0; i < N; i ++) cin >> P[i];
    sort(P.begin(), P.end());

    // find all the intervals in between.
    priority_queue<int> pq;
    pq.push(0);

    int best = 0;
    for (int i = 0; i <= P.size(); i ++) {
      // lo = P[i - 1], hi = P[i].
      int lo = (i == 0) ? 0 : P[i - 1];
      int hi = (i == P.size()) ? K + 1 : P[i];

      int num;
      if (lo == 0) {
        num = hi - 1;
      } else if (hi == K + 1) {
        num = K - lo;
      } else {
        best = max(best, hi - lo - 1);
        num = (int)ceil((double)(hi - lo - 1) / 2);
      }

        // cout << num << endl;
      pq.push(num);
      // if (pq.size() == 3)
      //   pq.pop();
    }

    int top1 = pq.top(); pq.pop();
    int top2 = (pq.empty()) ? 0 : pq.top(); pq.pop();

    // cout << top1 << " " << top2 << endl;

    best = max(best, top1 + top2);

    double prob = (double)(best) / K;

    cout << "Case #" << t << ": " << prob << endl;
  }

}
