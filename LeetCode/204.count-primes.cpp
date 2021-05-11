/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;

        vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i < n ; i ++) {
            if (is_prime[i] && (long long)i * i < n) {
                for (int j = i * i ; j < n; j += i)
                    is_prime[j] = false;
            }
        }

        return accumulate(is_prime.begin(), is_prime.end(), 0);
    }
};
// @lc code=end

