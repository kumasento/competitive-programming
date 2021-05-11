#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define MAXN 200001

int main(int argc, char *argv[]) {
  int t, n, a[MAXN], b[MAXN];

  // <freq, freq of freq>
  map<int, int> freqMap;

  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    freqMap.clear();

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    // Calculate the frequency.
    int freq = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1])
        freq++;
      else {
        freqMap[freq]++;
        freq = 1;
      }
    }
    freqMap[freq]++;

    int nFreq = freqMap.size();
    long long sum = 0, ans = INT_MAX;
    int keyId = 0;
    // freqMap is sorted by key in an ascending order.
    for (const auto &it : freqMap) b[keyId++] = it.first;

    for (int i = 0; i < nFreq; i++) {
      // cout << "b[" << i << "] = " << b[i] << ", freq = " << freqMap[b[i]]
      //      << endl;

      long long c1 = sum;
      for (int j = i + 1; j < nFreq; j++) c1 += freqMap[b[j]] * (b[j] - b[i]);
      ans = min(c1, ans);

      sum += freqMap[b[i]] * b[i];
      if (sum >= ans) break;
    }

    cout << ans << endl;
  }

  return 0;
}
