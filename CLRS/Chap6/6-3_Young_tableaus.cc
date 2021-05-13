#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class YoungTableau {
 public:
  static constexpr T INF = std::numeric_limits<T>::max();

  explicit YoungTableau(int M, int N)
      : M(M), N(N), data(M, vector<T>(N, INF)), size(0) {}

  T pop();

  void push(const T& val);

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const YoungTableau<U>& yt) {
    for (int i = 0; i < yt.M; i++) {
      for (int j = 0; j < yt.N; j++)
        os << std::setw(3)
           << (yt.data[i][j] == INF ? "INF" : std::to_string(yt.data[i][j]))
           << " ";

      os << std::endl;
    }

    return os;
  }

  bool empty() const { return size == 0; }

  bool contain(const T& val) const;

 private:
  vector<vector<T>> data;

  size_t size;
  const size_t M, N;
};

template <typename T>
bool YoungTableau<T>::contain(const T& val) const {
  // TBA
}

template <typename T>
void YoungTableau<T>::push(const T& val) {
  if (size == M * N) throw "Young tableau is full";

  int m = size / N, n = size % N;
  data[m][n] = val;

  int i = m, j = n;
  while (i > 0 && data[i][j] < data[i - 1][j]) {
    swap(data[i][j], data[i - 1][j]);
    i--;
  }
  while (j > 0 && data[i][j] < data[i][j - 1]) {
    swap(data[i][j], data[i][j - 1]);
    j--;
  }

  size++;
}

// NOTE: this is not a recursive solution.
template <typename T>
T YoungTableau<T>::pop() {
  if (size == 0) throw "Young tableau is empty";

  T ret = data[0][0];

  data[0][0] = INF;
  int i = 0, j = 0;
  while (i < M && j < N) {
    // choose whether to move
    bool canMoveDown = i < M - 1 && data[i][j] > data[i + 1][j];
    bool canMoveRight = j < N - 1 && data[i][j] > data[i][j + 1];
    if (canMoveDown || canMoveRight) {
      if (canMoveDown && (!canMoveRight || data[i + 1][j] < data[i][j + 1])) {
        swap(data[i][j], data[i + 1][j]);
        i++;
      } else if (canMoveRight &&
                 (!canMoveDown || data[i][j + 1] < data[i + 1][j])) {
        swap(data[i][j], data[i][j + 1]);
        j++;
      }
    } else {
      break;
    }
  }

  size--;
  return ret;
}

int main() {
  YoungTableau<int> yt(4, 4);
  yt.push(9);
  yt.push(16);
  yt.push(3);
  yt.push(2);
  yt.push(4);
  yt.push(8);
  yt.push(5);
  yt.push(14);
  yt.push(12);

  std::cout << yt << std::endl;

  assert(yt.pop() == 2);
  assert(yt.pop() == 3);

  while (!yt.empty()) {
    std::cout << yt.pop() << std::endl;
  }
}
