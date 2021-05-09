/*
 * @lc app=leetcode id=1354 lang=cpp
 *
 * [1354] Construct Target Array With Multiple Sums
 */

#include <bits/stdc++.h>
using namespace std;
#define LL long long

// @lc code=start
class Solution {
    using ll = long long;
public:
    bool isPossible(vector<int>& target) {
        priority_queue<ll> pq; ll sum = 0;
        for (int a: target) { pq.push(a); sum += a; }

        while (!pq.empty()) {
            auto num = pq.top(); pq.pop();
            if (num == 1)
                break;
            if (pq.size() == 0 && num != 1)
                return false;

            ll pre = sum - num;
            ll k = (num - 1) / pre;
            ll new_num = num - k * pre;
            if (new_num == num)
                return false;

            pq.push(new_num);
            sum = pre + new_num;
        }

        return true;
    }
};
// @lc code=end


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  Solution sol;

  int T; cin >> T;
  while (T --) {
    int N; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;

    cout << sol.isPossible(A) << endl;
  }
}

