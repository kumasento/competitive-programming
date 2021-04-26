/// This solution is based on the analysis provided.
#include <bits/stdc++.h>

using namespace std;

#define LL long long

const LL M = 360 * 12 * 1e10;

int main() {
  // Build the reverse dictionary.
  unordered_map<LL, unordered_map<LL, LL>> handMap;

  for (LL t = 0; t < 12 * 60 * 60; t++) {
    LL hands[3];
    hands[2] = (t * (LL)1e9 * 720) % M;
    hands[1] = (t * (LL)1e9 * 12) % M;
    hands[0] = (t * (LL)1e9) % M;

    sort(hands, hands + 3);

    for (int i = 0; i < 3; i++) {
      vector<LL> choices;
      for (int j = 0; j < 3; j++) {
        if (j == i)
          continue;
        LL k = (hands[j] - hands[i]) % M;
        if (k < 0)
          k += M;
        choices.push_back(k);
      }

      if (choices[0] > choices[1])
        swap(choices[0], choices[1]);

      handMap[choices[0]][choices[1]] = t;
    }
  }

  int choices[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                       {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    LL hands[3];
    cin >> hands[0] >> hands[1] >> hands[2];

    for (int i = 0; i < 6; i++) {
      LL A, B, C;
      A = hands[choices[i][0]];
      B = hands[choices[i][1]];
      C = hands[choices[i][2]];

      LL diff = A - B;
      LL hrs = 0LL, n = -1LL;
      while (hrs < 12LL) {
        LL d = hrs * 3600LL * (LL)1e9 - diff;
        d = (d % M);
        if (d < 0)
          d += M;
        if (d % 11 == 0) {
          n = d / 11;
          break;
        }
        hrs++;
      }

      if (n == -1)
        continue;

      LL n2 = n; // additional nanoseconds, to recover the real time later.
      n = n % ((LL)1e9); // nanoseconds

      LL hands2[3] = {A - n, B - 12LL * n, C - 720LL * n};
      for (int j = 0; j < 3; j++) {
        hands2[j] = hands2[j] % M;
        if (hands2[j] < 0)
          hands2[j] += M;
      }
      sort(hands2, hands2 + 3);

      LL k1 = hands2[1] - hands2[0], k2 = hands2[2] - hands2[0];

      if (handMap.count(k1) && handMap[k1].count(k2)) {
        LL h, m, s;
        // NOTE: This is to workaround the test cases. For Test Set 3, you can
        // give valid answers but in a different angle, which the tester won't
        // accept. So we should stick to the calculated hrs instead of the one
        // recorded in the reversed map.
        LL tm =
            (n == 0) ? handMap[k1][k2] : (hrs * 3600 * (LL)1e9 + n2 - n) * 1e-9;
        h = tm / 3600;
        tm -= h * 3600;
        m = tm / 60;
        tm -= m * 60;
        s = tm;

        cout << "Case #" << (t + 1) << ": " << h << " " << m << " " << s << " "
             << n << endl;
        break;
      }
    }
  }
}
