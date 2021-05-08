#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  LL N, K; cin >> N >> K;

  for (int i = 0; i < K; i ++) {
    if (N % 200 == 0)
      N /= 200;
    else {
      N *= 1000;
      N += 200;  
    }
  }

  cout << N << endl;
}
