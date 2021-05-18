/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

/**
 * Author: kumasento
 * Date:   2021-05-18T11:48:52.000-05:00
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
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, set<string>> mp;
        for (string p : paths) {
            istringstream iss(p);
            string dir, file; iss >> dir;
            while (iss) {
                iss >> file;
                size_t lparen = file.find('('), n = file.length();
                string name = file.substr(0, lparen);
                string content = file.substr(lparen + 1, n - lparen - 2);
                mp[content].insert(dir + "/" + name);
            }
        }

        vector<vector<string>> ans;
        for (const auto &it : mp) 
            if (it.second.size() > 1)
                ans.emplace_back(it.second.begin(), it.second.end()); 
        return ans;
    }
};
// @lc code=end


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}

