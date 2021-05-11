#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  string s; cin >> s;
  cout << s.substr(0, s.find('.')) << endl;

}
