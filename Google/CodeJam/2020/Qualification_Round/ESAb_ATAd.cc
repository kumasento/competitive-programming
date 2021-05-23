#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int T, B;
  cin >> T >> B;

  string S(B, '0');

  for (int t = 0; t < T; t++) {
    int p, q;  // p move to left, q move to right
    if (B % 2 == 0)
      p = B / 2 - 1, q = p + 1;
    else
      p = B / 2 - 1, q = p + 2;

    // Use p to track  the current progress.
    int i = 1;             // The query time.
    int ep = -1, eq = -1;  // pair of equal bits
    int np = -1, nq = -1;  // pair of not-equal bits.

    while (p >= 0) {
      if (i % 10 == 1 && i > 1) {
        // There could be an update to the original string.
        // Detect what the update is and apply it to S[p...q].

        // If seen equal pair
        if (eq != -1 && ep != -1) {
          // Check if one of them has been flipped.
          char s1, s2;
          cout << ep + 1 << endl;
          cin >> s1;

          if (np != -1 && nq != -1) {
            if (s1 == S[ep]) {
              // Not flipped.
              // Then we check a seen pair that is different.
              cout << np + 1 << endl;
              cin >> s2;

              if (s2 != S[nq]) {
                // new S[np] != S[nq], e.g., 1 0 -> 1 0.
                // Given the equal pair doesn't flip, this is the do nothing
                // case. No need to query more. p and q can remain the same.
              } else {
                // new S[np] == S[nq], e.g., 1 0 -> 0 1.
                // Reversed (no flip).
                // Update the existing S.
                for (int i = p + 1, j = q - 1; i < j; i++, j--)
                  swap(S[i], S[j]);
                // No need further query.
              }
            } else {
              // Flipped
              cout << np + 1 << endl;
              cin >> s2;

              if (s2 != S[nq]) {
                // not equal, 1 0 -> 1 0
                // flip and reversed.
                for (int i = p + 1, j = q - 1; i < j; i++, j--) {
                  S[i] = (1 - (S[i] - '0')) + '0';
                  S[j] = (1 - (S[j] - '0')) + '0';
                  swap(S[i], S[j]);
                }
              } else {
                // equal, 1 0 -> 0 1
                // simply flip
                for (int i = p + 1; i < q; i++) S[i] = (1 - (S[i] - '0')) + '0';
              }
            }

            // Need 2 queries for all the cases above
            i += 2;
          } else {
            // But not an inequality pair.
            // One more dummy input
            cout << ep + 1 << endl;
            cin >> s1;

            if (s1 == S[ep]) {
              // Not flipped, do nothing
            } else {
              // Flipped
              for (int i = p + 1; i < q; i++) S[i] = (1 - (S[i] - '0')) + '0';
            }
            i += 2;
          }
        } else {
          // Haven't seen an equal pair.
          // Flip and reverse are the same thing.
          // Nothing and (flip + reverse) are the same thing.
          char s1;
          cout << np + 1 << endl;
          cin >> s1;
          // I may use a dummy query here.
          cout << np + 1 << endl;
          cin >> s1;

          if (s1 == S[nq])
            for (int i = p + 1, j = q - 1; i < j; i++, j--) swap(S[i], S[j]);
          i += 2;
        }
        // p and q remain unchanged.

      } else {
        // query p and q.
        cout << p + 1 << endl;
        cin >> S[p];
        cout << q + 1 << endl;
        cin >> S[q];

        // Set the equal pair.
        if (S[p] == S[q]) {
          if (ep == -1 && eq == -1) ep = p, eq = q;
        } else if (np == -1 && nq == -1) {
          // Set the not-equal pair.
          np = p, nq = q;
        }

        i += 2, p--, q++;
      }
    }

    if (B % 2 != 0) {
      cout << (B / 2) << endl;
      cin >> S[(B / 2)];
    }

    cout << S << endl;

    char r;
    cin >> r;
    if (r == 'N') break;
  }

  return 0;
}
