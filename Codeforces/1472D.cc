#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while (t --) {
    int n; cin >> n;
    vector<LL> a(n); for (auto &i : a) cin >> i;

    sort(a.begin(), a.end());

    // Just simulate the game by asking Alice/Bob take 
    // the largest value in turn.

    LL scores[2] = {0, 0}, turn = 0;
    for (int i = a.size() - 1; i >= 0; i --) {
      if (turn)
        scores[turn] += (a[i] & 1) ? a[i] : 0;
      else
        scores[turn] += (a[i] & 1) ? 0 : a[i];
      turn = 1 - turn;
    }

    if (scores[0] == scores[1])
      cout << "Tie" << endl;
    else if (scores[0] > scores[1])
      cout << "Alice" << endl;
    else 
      cout << "Bob" << endl;

  }
}
