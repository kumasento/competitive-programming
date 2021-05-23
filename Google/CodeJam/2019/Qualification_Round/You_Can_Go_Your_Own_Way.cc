#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    string P;
    cin >> P;

    string path(P.size(), 'S');
    for (int i = 0; i < P.size(); i++) path[i] = P[i] == 'S' ? 'E' : 'S';

    cout << "Case #" << t + 1 << ": " << path << endl;
  }

  return 0;
}
