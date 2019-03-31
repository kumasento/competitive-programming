#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b.begin(), b.end());

  int max_cnt = 0, max_val = 0, cur = 0, cnt = 0;
  for (int i = 0; i < b.size(); i++) {
    if (i == 0) {
      cur = b[i];
      cnt = 1;
      max_cnt = 1;
      max_val = b[i];
    } else if (cur == b[i]) {
      cnt++;
    } else {
      if (cnt > max_cnt) {
        max_cnt = cnt;
        max_val = cur;
      }
      cnt = 1;
      cur = b[i];
    }
  }

  if (cnt > max_cnt) {
    max_cnt = cnt;
    max_val = cur;
  }
  int last = -1;

  cout << n - max_cnt << endl;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == max_val) {
      last = i;
      for (int j = i - 1; j >= 0; j--) {
        if (a[j] == max_val) break;

        if (a[j] > max_val)
          cout << 2 << " " << j + 1 << " " << j + 2 << endl;
        else
          cout << 1 << " " << j + 1 << " " << j + 2 << endl;
      }
    }
  }

  for (int i = last + 1; i < a.size(); i++) {
    if (a[i] > max_val)
      cout << 2 << " " << i + 1 << " " << i << endl;
    else
      cout << 1 << " " << i + 1 << " " << i << endl;
  }

  return 0;
}