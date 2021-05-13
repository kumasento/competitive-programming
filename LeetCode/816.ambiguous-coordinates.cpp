/**
 * Author: kumasento
 * Date:   2021-05-13T09:38:05.000-05:00
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



/*
 * @lc app=leetcode id=816 lang=cpp
 *
 * [816] Ambiguous Coordinates
 */

// @lc code=start
class Solution {
public:

    vector<string> ambiguousCoordinates(string s) {
        int N = s.length();
        string n = s.substr(1, N - 2);        

        
        auto check = [](const string &S) {
            // first check if there is any leading zeros.
            int nz = 0;
            for (int i = 0; i < S.length() && S[i] == '0'; i ++)
                nz ++;
            if (min(S.length(), S.find('.') - 0) > 1 && nz > 0)
                return false;

            // then check trailing zeros for fractional numbers.
            nz = 0;
            for (int i = S.length() - 1; i >= 0 && S[i] == '0'; i --)
                nz ++;
            if (nz > 0 && S.find('.') != string::npos)
                return false;

            return true;
        };

        vector<string> ans;

        for (int i = 1; i < n.length(); i ++) {
            string n1 = n.substr(0, i), n2 = n.substr(i, n.length() - i);

            // cout << n1 << " " << n2 << endl;

            for (int j = 0; j < n1.length(); j ++) {
                string m1{n1}; if (j > 0) m1.insert(m1.begin() + j, '.');
                if (!check(m1)) continue;

                for (int k = 0; k < n2.length(); k ++) {
                    string m2{n2}; if (k > 0) m2.insert(m2.begin() + k, '.');
                    if (!check(m2)) continue;

                    // cout << m1 << " " << m2 << endl;

                    ans.push_back("(" + m1 + ", " + m2 + ")");
                }
            }
        }

        return ans;
    }
};
// @lc code=end



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  Solution sol;
  sol.ambiguousCoordinates("(0123)");

}
