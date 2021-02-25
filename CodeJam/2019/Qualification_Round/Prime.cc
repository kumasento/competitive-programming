/// Some experiments regarding prime numbers.

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> generatePrimesUnder(const int N) {
  vector<bool> sieve(N + 1, true);
  sieve[0] = false, sieve[1] = false;

  for (int i = 2; i <= N; i++) {
    if (sieve[i]) {
      for (int j = i + 1; j <= N; j++) {
        if (j % i == 0) sieve[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i <= N; i++)
    if (sieve[i]) primes.push_back(i);

  return primes;
}

#define LL long long

int main(int argc, char *argv[]) {
  srand(time(NULL));

  int N = 101;
  vector<int> primes = generatePrimesUnder(N);

  int M = 26, nPrimes = primes.size();
  set<int> selected;
  for (int i = 0; i < M; i++) {
    int j;
    do {
      j = (int)(((double)rand() / RAND_MAX) * nPrimes);
    } while (selected.count(primes[j]));

    selected.insert(primes[j]);
  }

  cout << "Selected primes: " << endl;
  for (const auto &elem : selected) {
    cout << elem << " ";
  }
  cout << endl;

  vector<pair<LL, LL>> primePairs;
  for (const auto &e1 : selected) {
    for (const auto &e2 : selected) {
      if (e2 >= e1) primePairs.push_back(make_pair(e1, e2));
    }
  }

  cout << "Prime pairs: " << endl;
  for (int i = 0; i < primePairs.size(); i++) {
    cout << "(" << primePairs[i].first << ", " << primePairs[i].second << ") ";
  }
  cout << endl;

  cout << "Products: " << endl;
  for (int i = 0; i < primePairs.size(); i++) {
    cout << primePairs[i].first * primePairs[i].second << " ";
  }
  cout << endl;

  for (int d = 1; d <= 6; d++) {
    cout << "Checking distinct last " << d << " digits." << endl;

    unordered_set<int> lastDigits;
    for (int i = 0; i < primePairs.size(); i++) {
      auto prod = primePairs[i].first * primePairs[i].second;
      auto last = prod % ((LL)pow(10, d));
      // cout << last << " ";
      lastDigits.insert(last);
    }

    cout << lastDigits.size() << endl;
  }

  return 0;
}
