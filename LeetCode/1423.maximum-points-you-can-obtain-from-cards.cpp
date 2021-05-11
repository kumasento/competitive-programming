/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
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
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        // a sliding window approach
        int start = n - k;
        int sum = accumulate(cardPoints.begin() + start, cardPoints.end(), 0);
        int mx = sum;
        for (int i = 1; i <= k; i ++) {
            sum += cardPoints[i - 1] - cardPoints[start + i - 1];
            mx = max(sum, mx);
        }

        return mx;
    }
};
// @lc code=end

