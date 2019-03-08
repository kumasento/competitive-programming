#include <bits/stdc++.h>

using namespace std;

struct Task {
  int s, e;
  int v = -1;
  Task() : s(-1), e(0) {}
  Task(int s, int e) : s(s), e(e) {}

  bool operator>(const Task &rhs) { return e > rhs.e; }
};

struct Compare {
  bool operator()(pair<Task, int> &p1, pair<Task, int> &p2) {
    return p1.first.e > p2.first.e;
  }
};

int main(int argc, char *argv[]) {
  // input
  int n, k;
  cin >> n >> k;

  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  // store the task status
  vector<Task> p(k);  // current start time of each process

  // build the priority queue
  // sort by the first by default
  // <end_time, pid>
  priority_queue<pair<Task, int>, vector<pair<Task, int>>, Compare> pq;

  int cur = 0;
  while (cur < k && cur < n) {
    p[cur].s = 0;
    p[cur].e = a[cur];

    pq.push(make_pair(p[cur], cur));

    cur++;
  }

  // track towards the end of execution
  int ans = 0;
  int cnt = 0;
  int last_et = 0;
  int d = -1;  // not initialised
  double f = 0.0;
  while (!pq.empty()) {
    auto task = pq.top();
    pq.pop();

    cnt++;
    auto st = task.first.s;
    auto et = task.first.e;
    auto pid = task.second;

    // before we update d, let's see the status of all tasks
    // std::cout << "Current end time=" << et << std::endl;

    // check whether this task has met the previous d
    for (int i = 0; i < k; i++) {
      printf("pid=%2d vis=%d last_et=%5d cur_et=%5d st=%5d et=%5d d=%5d\n", i,
             p[i].v, last_et, et, p[i].s, p[i].e, d);
      if (d != -1 && p[i].v != d && p[i].s != -1 && p[i].s + d < et &&
          p[i].s + d > last_et) {
        printf("ADDED!\n");
        p[i].v = d;
        ans++;
      }
    }

    // compute d
    f = 100 * static_cast<double>(cnt) / n;
    d = static_cast<int>(std::floor(f + 0.5));

    // let's see what the status of all other processes
    for (int i = 0; i < k; i++) {
      if (i != pid && p[i].s != -1) {  // 0 means ended
        printf("d = %d et - p[i].s + 1 = %d\n", d, et - p[i].s + 1);
        if (d == et - p[i].s + 1) {
          printf("ADDED!\n");
          ans++;
          p[i].v = d;
        }
      }
    }

    // insert new task
    if (cnt + pq.size() < n) {
      p[pid].s = et;
      p[pid].e = et + a[cnt + pq.size()];

      pq.push(make_pair(p[pid], pid));
    } else {
      p[pid].s = -1;  // decommission
    }

    last_et = et;
  }

  std::cout << ans << std::endl;

  return 0;
}