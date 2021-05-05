#include <bits/stdc++.h>

using namespace std;

int main() {
  int num = 1;
  for (int i = 1; i <= 20; i ++)
    num = lcm(num, i);
  cout << num << endl;
}
