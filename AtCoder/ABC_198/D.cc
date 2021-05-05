#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  string S1, S2, S3; cin >> S1 >> S2 >> S3;

  set<char> A;
  for (char c : S1) A.insert(c);
  for (char c : S2) A.insert(c);
  for (char c : S3) A.insert(c);

  if (A.size() > 10) {
    cout << "UNSOLVABLE" << endl;
  } else {
    map<char, int> cmap; int id = 0; for (char c : A) cmap[c] = id ++;
    vector<char> T(10); for (int i = 0; i < T.size(); i ++) T[i] = i + '0';

    auto check = [](const string &S) { return S[0] == '0'; };

    string N1(S1.length(), '0'), N2(S2.length(), '0'), N3(S3.length(), '0');

    do {
      int i;
      i = 0; for (char c : S1) N1[i++] = T[cmap[c]];
      i = 0; for (char c : S2) N2[i++] = T[cmap[c]];
      i = 0; for (char c : S3) N3[i++] = T[cmap[c]];

      if (check(N1) || check(N2) || check(N3))
        continue;

      LL n1 = stoll(N1), n2 = stoll(N2), n3 = stoll(N3);
      if (n1 + n2 == n3) {
        cout << N1 << endl;
        cout << N2 << endl;
        cout << N3 << endl;
        return 0;
      }
    } while (next_permutation(T.begin(), T.end()));

    cout << "UNSOLVABLE" << endl;
  }
}
