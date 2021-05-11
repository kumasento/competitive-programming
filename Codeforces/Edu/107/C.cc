#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<int> a(n); for (int &i : a) cin >> i; 

  array<int, 51> top{0};
  for (int i = 0; i < a.size(); i ++)
    if (top[a[i]] == 0)
      top[a[i]] = i + 1;

  int cnt = 0;
  while (q --) {
    int t; cin >> t;

    cout << top[t] << " ";
    for (int i = 1; i <= 50; i ++) 
      if (top[i] != 0 && top[i] < top[t])
        top[i] ++;
    top[t] = 1;
  } 

  cout << endl;
}
