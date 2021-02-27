#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  // all the sum of pairs
  vector<int> S(N * (N - 1) / 2);
  int cnt = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      S[cnt++] = A[i] + A[j];
    }
  }

  // sort it
  std::sort(S.begin(), S.end());

  // find the maximal range of equal values
  int cur = S[0];
  int len = 1;
  int max_len = 1;
  for (int i = 1; i < S.size(); i++) {
    if (cur == S[i]) {
      len++;
      max_len = max(len, max_len);
    } else {
      len = 1;
      cur = S[i];
    }
  }

  // output
  std::cout << max_len << std::endl;

  return 0;
}