#include <string>

using namespace std;

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
