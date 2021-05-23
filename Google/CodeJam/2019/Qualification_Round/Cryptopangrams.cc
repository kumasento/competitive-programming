#include <algorithm>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

inline bool greater(const string &a, const string &b) {
  return a.size() > b.size() || (a.size() == b.size() && a > b);
}

/// a is larger than b.
inline string sub(const string &a, const string &b) {
  string r;
  int d = 0;

  for (int i = 0; i < a.size(); i++) {
    int x = a[a.size() - i - 1] - '0';
    int y = (i < b.size()) ? b[b.size() - i - 1] - '0' : 0;
    if (x + d >= y) {
      r.push_back(x + d - y + '0');
      d = 0;
    } else {
      r.push_back(x + d - y + 10 + '0');
      d = -1;
    }
  }

  reverse(r.begin(), r.end());

  // trim leading zeros.
  int i = 0;
  while (r[i] == '0') i++;

  if (i == r.size()) return "0";

  return r.substr(i, r.size() - i);
}

/// Assuming a is greater than b.
inline string add(const string &a, const string &b) {
  string r;
  int c = 0;

  for (int i = 0; i < a.size(); i++) {
    int x = a[a.size() - i - 1] - '0';
    int y = (i < b.size()) ? b[b.size() - i - 1] - '0' : 0;

    int z = x + y + c;
    if (z >= 10)
      c = 1;
    else
      c = 0;
    r.push_back((z % 10) + '0');
  }

  if (c > 0) r.push_back('1');

  reverse(r.begin(), r.end());
  return r;
}

/// Assuming a is larger than b and a is divisible by b.
inline string div(const string &a, const string &b) {
  string ans = "0";
  string r = a;
  while (r != "0") {
    r = sub(r, b);
    ans = add(ans, "1");
  }
  return ans;
}

/// Doing gcd between two very large numbers.
string gcd(string a, string b) {
  while (a != b) {
    if (::greater(a, b)) {
      a = sub(a, b);
    } else {
      b = sub(b, a);
    }
  }
  return a;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    string N;
    int L;
    cin >> N >> L;

    vector<string> cipher(L);
    for (int i = 0; i < L; i++) cin >> cipher[i];

    vector<string> primes(L + 1);
    primes[1] = gcd(cipher[0], cipher[1]);
    primes[0] = div(cipher[0], primes[1]);
    for (int i = 2; i < L + 1; i++)
      primes[i] = div(cipher[i - 1], primes[i - 1]);

    set<string, decltype(&::greater)> distinctPrimes(&::greater);
    for (int i = 0; i < L + 1; i++) distinctPrimes.insert(primes[i]);

    unordered_map<string, char> primeToChar;
    char curr = 'Z';
    for (const auto &elem : distinctPrimes) {
      primeToChar[elem] = curr;
      curr--;
    }

    cout << "Case #" << (t + 1) << ": ";
    for (int i = 0; i < L + 1; i++) {
      cout << primeToChar[primes[i]];
    }
    cout << endl;
  }

  return 0;
}
