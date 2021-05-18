/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

/**
 * Author: kumasento
 * Date:   2021-05-17T10:08:23.000-05:00
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
    vector<set<int>> adj;
    vector<int> h;

public:
    void dfs(int u, int p = -1) {
        if (h[u] != -1) return; 
        h[u] = 1;
        for (int v : adj[u]) {
            if (v == p)
                continue;
            dfs(v, u);
            h[u] = max(1 + h[v], h[u]); 
        }
        return;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        adj.resize(n);
        h.assign(n, -1);

        unordered_map<string, int> m; for (int i = 0; i < n; i ++) m[words[i]] = i;

        for (int i = 0; i < n; i ++) {
            int l = words[i].length();
            for (int k = 0; k <= l; k ++) {
                for (int c = 'a'; c <= 'z'; c ++) {
                    string s = words[i].substr(0, k);
                    s.push_back(c);
                    if (k < l) s += words[i].substr(k, l - k);
                    if (m.count(s)) adj[i].insert(m[s]);
                }
                    
            }
        }

        for (int i = 0; i < n; i ++) dfs(i);

        return *max_element(h.begin(), h.end());
    }
};
// @lc code=end


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<string> strs{"xbc","pcxbcf","xb","cxbc","pcxbc"};
    Solution sol;
    sol.longestStrChain(strs);
}
