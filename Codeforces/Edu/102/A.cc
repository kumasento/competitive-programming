/**
 * Author: kumasento
 * Date:   2021-05-14T09:55:40.000-05:00
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

void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;
  while (t --) {
    int n, d; cin >> n >> d;

    vector<int> a(n); for (int &i : a) cin >> i;

    auto check = [&]() {
      for (int i = 0; i < n; i ++) 
        if (a[i] > d) 
          return false;
      return true;
    };

    if (check()) 
      yes();
    else {

      for (int i = 0; i < n; i ++) 
        if (a[i] > d) 
          for (int j = 0; j < n; j ++) 
            for (int k = j + 1; k < n; k ++) 
              if (j != i && k != i && a[k] + a[j] <= d) 
                a[i] = a[k] + a[j];
      
      if (check())
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
