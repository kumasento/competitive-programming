/*
 * @lc app=leetcode id=906 lang=cpp
 *
 * [906] Super Palindromes
 */

#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}

// @lc code=start
class Solution {
    using ll = long long;
public:

    bool is_palindrome(const string &s) {
        for (int i = 0, j = s.length() - 1; i <= j; i ++, j --)
            if (s[i] != s[j])
                return false;
        return true;
    }

    void dfs(int len, int i, string &s, ll &cnt, const ll & L, const ll &R) {
        if (i > len - i - 1) { // palindrome constructed.
            ll num = stoll(s), sq = num * num;
            if (sq >= L && sq <= R && is_palindrome(to_string(sq)))
                cnt ++;
            return;
        }

        for (int k = 0; k < 9; k ++) {
            if (k == 0 && i == 0 && len != 1)
                continue;
            s[i] = s[len - i  - 1] = k + '0';
            dfs(len, i + 1, s, cnt, L, R);
        }
    }

    int superpalindromesInRange(string left, string right) {
        int n = left.length(), m = right.length();

        ll cnt = 0;
        ll L = stoll(left), R = stoll(right);
        int lo = (int)(ceil(n * 0.5)), hi = (int)(ceil(m * 0.5));
        for (int len = lo; len <= hi; len ++) {
            string s(len, '0');
            dfs(len, 0, s, cnt, L, R);
        }
        return cnt;
    }
};
// @lc code=end

