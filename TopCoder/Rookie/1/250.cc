/**
 * Author: kumasento
 * Date:   2021-05-13T21:01:40.000-05:00
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

class ColorWheel {
public:

  string describePair(string color1, string color2) {
    map<string, int> colors {
      { "Red", 0 },
      { "Purple", 1 },
      { "Blue", 2 },
      { "Green", 3 },
      { "Yellow", 4 },
      { "Orange", 5 }
    };

    int i = colors[color1], j = colors[color2];
    if (i == j)
      return "Same";
    if (i == (j + 3) % 6)
      return "Complementary";
    if (i == (j + 1) % 6 || j == (i + 1) % 6)
      return "Adjacent";
    return "None";
  }
};


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}
