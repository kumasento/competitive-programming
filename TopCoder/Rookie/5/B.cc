/**
 * Author: kumasento
 * Date:   2021-05-14T12:07:58.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// ---------- Globals   ---------

/// ---------- Solution  ---------

class PickTwoCards {
public:
  double equalProbability(string cards) {
    int cnts[26] = {0};
    int n = cards.size();

    for (char c : cards) cnts[c - 'A'] ++;

    double prob = 0;
    for (int i = 0; i < 26; i ++)
      prob += (double) cnts[i] * (cnts[i] - 1); 
    return prob / (n * (n - 1));
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

} 
