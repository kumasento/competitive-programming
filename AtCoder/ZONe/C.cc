#include <bits/stdc++.h>

#define LL long long

using namespace std;

int min5(int a, int b, int c, int d,int e) {
  return min(min(a, b), min(c, min(d, e)));
}

int max3(int a, int b, int c) {
  return max(a, max(b, c));
}

int main() {
  int N; cin >> N;

  vector<int> A(N), B(N), C(N), D(N), E(N);
  for (int i = 0; i < N; i ++)
    cin >> A[i] >> B[i] >> C[i] >> D[i] >> E[i];
  

  array<int, 5> best;
  best[0] = max_element(A.begin(), A.end()) - A.begin();
  best[1] = max_element(B.begin(), B.end()) - B.begin();
  best[2] = max_element(C.begin(), C.end()) - C.begin();
  best[3] = max_element(D.begin(), D.end()) - D.begin();
  best[4] = max_element(E.begin(), E.end()) - E.begin();

  int ans =0;
  for (int i = 0; i < N; i ++)
    for (int j = 0; j < N; j ++) {
      if (i == j)
        continue;

      array<int, 5> power{
        max(A[i], A[j]),
        max(B[i], B[j]),
        max(C[i], C[j]),
        max(D[i], D[j]),
        max(E[i], E[j])
      };
      for (int k = 0; k < best.size(); k ++) {
        power[0] = max(A[best[k]], power[0]);
        power[1] = max(B[best[k]], power[1]);
        power[2] = max(C[best[k]], power[2]);
        power[3] = max(D[best[k]], power[3]);
        power[4] = max(E[best[k]], power[4]);
      }
      int strength = *min_element(power.begin(), power.end());
      ans = max(ans, strength);
    }

  cout << ans << endl;
}
