#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a.begin(), a.end());

  vector<int> inc;
  vector<int> dec;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (inc.size() == 0 || a[i] != inc.back()) {
      inc.push_back(a[i]);
    } else if (dec.size() == 0 || a[i] != dec.back()) {
      dec.push_back(a[i]);
    } else {
      ok = false;
      break;
    }
  }

  if (!ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << inc.size() << endl;
    for (int i = 0; i < inc.size(); i++) cout << inc[i] << " ";
    cout << endl;
    cout << dec.size() << endl;
    for (int i = dec.size() - 1; i >= 0; i--) cout << dec[i] << " ";
    cout << endl;
  }

  return 0;
}