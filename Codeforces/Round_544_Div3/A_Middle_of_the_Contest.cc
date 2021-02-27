#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string st, ed;
  cin >> st >> ed;

  auto h1 = (st[0] - '0') * 10 + st[1] - '0';
  auto m1 = (st[3] - '0') * 10 + st[4] - '0';
  auto h2 = (ed[0] - '0') * 10 + ed[1] - '0';
  auto m2 = (ed[3] - '0') * 10 + ed[4] - '0';

  auto sm = h1 * 60 + m1;
  auto em = h2 * 60 + m2;

  auto mm = (sm + em) / 2;

  printf("%02d:%02d\n", mm / 60, mm % 60);

  return 0;
}
