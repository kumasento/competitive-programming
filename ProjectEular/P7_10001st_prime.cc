#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  vector<LL> primes{2, 3, 5, 7, 11, 13}; 
  int cnt = 7;
  LL x = 14;
  while (cnt <= 10001) {
    bool is_prime = true;
    for (LL p : primes)
      if ((x % p) == 0) {
        is_prime = false;
        break;
      }

    if (is_prime) {
      primes.push_back(x);
      cnt ++;
    }
    x ++;
  }

  cout << primes.back() << endl;
}
