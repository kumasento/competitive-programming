#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class MinimumStack {
  stack<pair<int, int>> st;

public:
  void push(int val) {
    if (st.empty() || val < st.top().second)
      st.push(make_pair(val, val));
    else
      st.push(make_pair(val, st.top().second));
  }

  int pop() {
    auto top = st.top();
    st.pop();
    return top.first;
  }

  int minimum() {
    if (st.empty())
      return INT_MIN;
    return st.top().second;
  }
};

class MinimumQueue {
  stack<pair<int, int>> s1, s2;

public:
  void push(int val) {
    int min_elem = s1.empty() ? val : min(s1.top().second, val);
    s1.push({val, min_elem});
  }

  int pop() {
    if (s2.empty()) {
      while (!s1.empty()) {
        int min_elem =
            s2.empty() ? s1.top().first : min(s2.top().second, s1.top().first);
        s2.push({s1.top().first, min_elem});
        s1.pop();
      }
    }

    int elem_returned = s2.top().first;
    s2.pop();
    return elem_returned;
  }

  int minimum() {
    if (s1.empty() && s2.empty())
      return INT_MIN;
    if (s1.empty())
      return s2.top().second;
    if (s2.empty())
      return s1.top().second;
    return min(s1.top().second, s2.top().second);
  }
};

int main() {
  vector<int> a = {9, 8, 7, 1, 10, 5, 4, 2};

  MinimumStack st;
  cout << "Push" << endl;
  for (auto val : a) {
    st.push(val);
    cout << st.minimum() << endl;
  }
  cout << "Pop" << endl;
  for (int i = 0; i < a.size(); i++) {
    st.pop();
    cout << st.minimum() << endl;
  }

  MinimumQueue q;
  cout << "Push" << endl;
  for (auto val : a) {
    q.push(val);
    cout << q.minimum() << endl;
  }
  cout << "Pop" << endl;
  for (int i = 0; i < a.size(); i++) {
    q.pop();
    cout << q.minimum() << endl;
  }
}
