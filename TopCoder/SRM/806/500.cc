/**
 * Author: kumasento
 * Date:   2021-05-26T16:35:42.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// Constants:
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// Globals:

/// Solution:

const LL MOD = 1e9 + 7;

LL extgcd(LL a, LL b, LL &x, LL &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  LL x1, y1;
  LL g = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

LL invmod(LL a) {
  LL x, y;
  extgcd(a, MOD, x, y);
  x = (x % MOD + MOD) % MOD;
  return x;
}

LL modpow(LL base, LL exp) {
  LL res = 1;
  while (exp > 0) {
    if (exp & 1)
      res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return res;
}

vector<LL> fact;

LL C(LL n, LL i) { return fact[n] * invmod(fact[n - i] * fact[i]) % MOD; }

class MostSubstrings {
public:
  int count(string S, int L) {
    int n = S.length();

    fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
      fact[i] = (fact[i - 1] * i) % MOD;
 

    auto overlap = [](const string &T, int len) -> bool {
      int n = T.length();
      for (int i = 0; i < len; i++)
        if (T[i] != T[n - len + i])
          return false;
      return true;
    };

    // Cmax = 0
    if (L < n)
      return modpow(26, L);
    // Cmax = 1
    if (all_of(S.begin(), S.end(), [&](char c) { return c == S[0]; }))
      return 1;

    // Cmax = (L - |S|) / (|S| - overlap)
    int len = 0;
    for (int l = 1; l < n; l++)
      if (overlap(S, l))
        len = l;
    // no overlap. can insert inter-between every S.
    if (len == 0) {
      int k = L / n, t = L % n; // k - num of S, t - num of add chars.
      LL ans = modpow(26, t) * C(k + t, t) % MOD;
      // for (int i = 0; i < t; i++)
      //   ans = (((k + i + 1) * 26) * ans) % MOD;
      return ans;
    }

    int k = (L - n) % (n - len);
    return (k + 1) * modpow(26, k) % MOD;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("500.in");
  cin.rdbuf(in.rdbuf());
#endif

  MostSubstrings sol;
  cout << sol.count("dededeiauwhdiuwagbiucbiaulwhdiuhawiugfwauig", 1000)
       << endl;
  ;
}
