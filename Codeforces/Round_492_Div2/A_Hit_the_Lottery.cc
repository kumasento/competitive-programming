#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define LL long long

using namespace std;

int main(int argc, char *argv[]) {
  int N;
  cin >> N;

  LL ans = 0;
  if (N >= 100) ans += N / 100, N = N % 100;
  if (N >= 20) ans += N / 20, N = N % 20;
  if (N >= 10) ans += N / 10, N = N % 10;
  if (N >= 5) ans += N / 5, N = N % 5;
  ans += N;

  cout << ans << endl;

  return 0;
}
