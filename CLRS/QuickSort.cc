#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void PrintVector(vector<int> &A, int start, int end) {
  assert(end <= A.size());
  assert(start < end);

  cout << "[ ";
  copy(A.begin() + start, A.begin() + end, ostream_iterator<int>(cout, " "));
  cout << "]" << endl;
}

/// Return the pivot.
int PartitionByValue(vector<int> &A, int start, int end) {
  assert(end <= A.size());
  assert(start < end);

  int pivot = start;
  for (int i = start + 1; i < end; i++) {
    if (A[i] < A[pivot]) {
      // pivot == end - 1?
      swap(A[i], A[pivot + 1]);
      swap(A[pivot], A[pivot + 1]);
      pivot++;
    }
  }

  return pivot;
}

/// Sort between [start, end).
void QuickSort(vector<int> &A, int start, int end) {
  assert(end <= (int)A.size());

  // Tail recursive version.
  while (start < end) {
    cout << " -- Sorting between [" << start << ", " << end << ") ...\n";

    PrintVector(A, start, end);
    int pivot = PartitionByValue(A, start, end);

    cout << "Selected pivot: id = " << pivot << " A[pivot] = " << A[pivot]
         << endl;

    if (pivot - start < end - pivot) {
      QuickSort(A, start, pivot);
      start = pivot + 1;
    } else {
      QuickSort(A, pivot + 1, end);
      end = pivot;
    }

    // QuickSort(A, pivot + 1, end);
  }
}

void QuickSort(vector<int> &A) { QuickSort(A, 0, A.size()); }

int main() {
  vector<int> v1{2, 3, 1, 6, 7, -5, 0};
  vector<int> v2{-4, 9, 1, 3};

  QuickSort(v1);
  copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  QuickSort(v2);
  copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}
