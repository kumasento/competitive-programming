#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class RangeSumQueryTable {
  vector<vector<int>> st;

public:
  RangeSumQueryTable(const vector<int> &data) {
    int N = data.size();
    int K = log2(N);

    cout << "N = " << N << " K = " << K << endl;
    st = vector<vector<int>>(N, vector<int>(K + 1, 0));

    preCompute(data);
  }

  void preCompute(const vector<int> &data) {
    int N = st.size(), K = st[0].size();

    for (int i = 0; i < N; i++)
      st[i][0] = data[i];

    for (int j = 1; j <= K; j++) {
      for (int i = 0; i + (1 << j) <= N; i++) {
        st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
      }
    }
  }

  int query(int x, int y) {
    assert(x <= y);

    int len = y - x + 1;
    int sum = 0;
    int i = 0; // 2^i
    while (len > 0) {
      if (len & 1) {
        sum += st[x][i];
        x += (1 << i);
      }
      i++;
      len >>= 1;
    }

    return sum;
  }
};

class RangeMinQueryTable {
  vector<vector<int>> st;

public:
  RangeMinQueryTable(const vector<int> &data) {
    int N = data.size();
    int K = log2(N);

    st = vector<vector<int>>(N, vector<int>(K + 1));

    preCompute(data);
  }

  void preCompute(const vector<int> &data) {
    int N = st.size(), K = st[0].size();
    for (int i = 0; i < N; i++)
      st[i][0] = data[i];

    for (int j = 1; j <= K; j++) {
      for (int i = 0; i + (1 << j) <= N; i++) {
        st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  int query(int L, int R) {
    int j = log2(R - L + 1);
    return min(st[L][j], st[R - (1 << j) + 1][j]);
  }
};

int main() {
  vector<int> data = {1, 9,  3,  2,  7,  4,   -6,   6, 3,
                      2, 10, 26, 54, 37, -87, -102, 77};

  RangeSumQueryTable rsq(data);
  assert(rsq.query(0, 1) == 10);
  assert(rsq.query(1, 2) == 12);
  assert(rsq.query(2, 6) == 10);

  RangeMinQueryTable rmq(data);
  assert(rmq.query(0, 1) == 1);
  assert(rmq.query(10, 16) == -102);
}
