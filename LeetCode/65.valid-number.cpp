/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

/**
 * Author: kumasento
 * Date:   2021-05-15T10:00:19.000-05:00
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



// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        for (int i = 0; i < s.length(); i ++) s[i] = tolower(s[i]);

        int pos = 0;
        if (s[pos] == '+' || s[pos] == '-') pos ++;
        if (pos == s.length()) return false;
        
        int dpos = s.find('.');
        if (dpos != string::npos) {
            for (int i = pos; i < dpos; i ++) if (!isdigit(s[i])) return false;

            // for the case that '.' is not preceded by or followed by a digit. 
            if (dpos == pos &&
                (dpos + 1 == s.length() || !isdigit(s[dpos+1])))
                return false;
            pos = dpos + 1;
        } else {
            // otherwise, no matter whether there is an 'e' followed, there should
            // be at least one digit in between.
            if (!isdigit(s[pos])) return false;
        }

        int epos = s.find('e');
        if (epos != string::npos) {
            for (int i = pos; i < epos; i ++) if (!isdigit(s[i])) return false;
            pos = epos + 1;
            if (pos == s.length()) return false;
            if (s[pos] == '+' || s[pos] == '-') pos ++;
            if (pos == s.length()) return false;
        }

        for (int i = pos; i < s.length(); i ++) if (!isdigit(s[i])) return false;
        return true;
    }
};
// @lc code=end


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}

