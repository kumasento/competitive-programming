#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

}

class MarriageAndTravelingChallenge {
public:
  string solve(string S) {
    string T;
    int i = 0;
    int j = 1;
    while (i < S.length()) {
      T.push_back(S[i]);

      i += j;
      j++;
    }

    return T;
  }
};
