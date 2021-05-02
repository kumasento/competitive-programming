#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  int n, M; cin >> n >> M;

  // map set size to frequencies.
  map<int, LL> m1, m2, m3;
  m1[1] = 1;

  for (int i = 2; i <= n; i ++) {
    int s1 = 0;

    for (auto &it : m1) { cout << "m1: " << it.first << " " << it.second << endl; }
    for (auto &it : m2) { cout << "m2: " << it.first << " " << it.second << endl; }

    m3.clear();
    for (auto &it : m1) {
      int k; LL v; tie(k, v) = it;
      LL a = ((k + 1LL) * v) % M; // for size k
      if (m2.count(k - 1)) {
        LL b = (m2[k - 1] * k) % M;
        m3[k] = (m3[k] + b) % M; 
        a = (a - b) % M;
      }
      m3[k + 1] = a; 

      for (auto &it : m3) { cout << "m3: " << it.first << " " << it.second << endl; }
      cout << endl;
    }

    swap(m1, m2);
    swap(m1, m3);

    for (auto &it : m1) { cout << "m1: " << it.first << " " << it.second << endl; }
    for (auto &it : m2) { cout << "m2: " << it.first << " " << it.second << endl; }
  }

  LL sum = 0LL;
  for (auto &it : m1) {
    int k; LL v; tie(k, v) = it;
    sum = (sum + v) % M;
  }
  cout << sum << endl;
}
