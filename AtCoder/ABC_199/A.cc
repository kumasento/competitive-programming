#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  if (A * A + B * B < C * C)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
