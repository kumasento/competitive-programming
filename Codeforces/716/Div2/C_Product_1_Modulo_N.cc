#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main() {
  int n;
  cin >> n;

  set<int> coprimes;
  LL p = 1;
  for (int i = 1; i <= n - 1; i++)
    if (__gcd(i, n) == 1) {
      coprimes.insert(i);
      p = (p * i) % n;
    }

  if (p != 1)
    coprimes.erase(p);

  cout << coprimes.size() << endl;
  for (int v : coprimes)
    cout << v << " ";
  cout << endl;
}
