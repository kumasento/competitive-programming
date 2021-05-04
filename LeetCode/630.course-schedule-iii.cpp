/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    sort(
        courses.begin(), courses.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    int curTime = 0, count = 0;

    priority_queue<int> pq;

    for (int i = 0; i < courses.size(); i++) {
      if (curTime + courses[i][0] <= courses[i][1]) {
        pq.push(courses[i][0]);
        curTime += courses[i][0];
        count++;
      } else {
        // try to replace a taken course that has the maximum duration and
        // longer than the current course's duration. If that course's duration
        // is not longer, the replacement may not be helpful to fit the current
        // course in, or we just add a new course that make the total duration
        // longer, which is not helpful.

        int max_dur = courses[i][0];
        if (!pq.empty() && pq.top() > courses[i][0]) {
          curTime += courses[i][0] - pq.top();
          pq.pop();
          pq.push(courses[i][0]);
        }

        // total count won't change.
      }
    }

    return count;
  }
};
// @lc code=end
