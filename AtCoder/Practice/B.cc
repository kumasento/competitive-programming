#include <bits/stdc++.h>

using namespace std;

void mergesort(string &s, int start, int end) {
  if (start == end)
    return;
  if (start == end - 1)
    return;
  if (start + 2 == end) {
    cout << "? " << s[start] << " " << s[start + 1] << endl;
    string c;
    cin >> c;

    if (c == ">")
      swap(s[start], s[start + 1]);
    return;
  }

  int mid = start + (end - start) / 2;
  mergesort(s, start, mid);
  mergesort(s, mid, end);

  string t(s.begin() + start, s.begin() + end);
  int i = 0, j = mid - start;
  int k = start;
  while (i < mid - start || j < end - start) {
    if (i == mid - start)
      s[k++] = t[j++];
    else if (j == end - start)
      s[k++] = t[i++];
    else {
      cout << "? " << t[i] << " " << t[j] << endl;
      string c;
      cin >> c;

      if (c == ">")
        s[k++] = t[j++];
      else
        s[k++] = t[i++];
    }
  }
}

bool query(char A, char B) {
  cout << "? " << A << " " << B << endl;
  char c;
  cin >> c;
  return c == '>';
}

int main() {
  int N, Q;
  cin >> N >> Q;

  string s;
  for (int i = 0; i < N; i++)
    s.push_back('A' + i);

  // https://stackoverflow.com/questions/1534748/design-an-efficient-algorithm-to-sort-5-distinct-keys-in-fewer-than-8-comparison
  if (N == 5 && Q == 7) {
    if (query(s[0], s[1]))
      swap(s[0], s[1]);
    if (query(s[2], s[3]))
      swap(s[2], s[3]);      // swap C D
    if (query(s[0], s[2])) { // A > C
      swap(s[0], s[2]);      // swap A C
      swap(s[1], s[3]);      // swap B D
    }

    string t;
    if (query(s[4], s[2])) {       // E > C
      if (query(s[4], s[3])) {     // E > D -> C - D - E
        if (query(s[1], s[3])) {   // B > D
          if (query(s[1], s[4])) { // B > E -> C - D - E - B
            t = {s[0], s[2], s[3], s[4], s[1]};
          } else { // B < E -> C - D - B - E
            t = {s[0], s[2], s[3], s[1], s[4]};
          }
        } else {                 // B < D
          if (query(s[1], s[2])) // B > C -> C - B - D - E
            t = {s[0], s[2], s[1], s[3], s[4]};
          else // A - B - C - D - E
            t = {s[0], s[1], s[2], s[3], s[4]};
        }
      } else {                     // E < D -> C - E - D
        if (query(s[1], s[4])) {   // B > E
          if (query(s[1], s[3])) { // B > D -> C - E - D - B
            t = {s[0], s[2], s[4], s[3], s[1]};
          } else { // B < D -> C - E - B - D
            t = {s[0], s[2], s[4], s[1], s[3]};
          }
        } else {                 // B < E
          if (query(s[1], s[2])) // B > C -> C - B - E - D
            t = {s[0], s[2], s[1], s[4], s[3]};
          else // A - B - C - E - D
            t = {s[0], s[1], s[2], s[4], s[3]};
        }
      }
    } else {                       // E < C
      if (query(s[4], s[0])) {     // E > A -> A - E - C - D
        if (query(s[1], s[2])) {   // B > C
          if (query(s[1], s[3])) { // B > D -> A - E - C - D - B
            t = {s[0], s[4], s[2], s[3], s[1]};
          } else { // B < D -> A - E - C - B - D
            t = {s[0], s[4], s[2], s[1], s[3]};
          }
        } else {                 // B < C
          if (query(s[1], s[4])) // B > E -> A - E - B - C - D
            t = {s[0], s[4], s[1], s[2], s[3]};
          else // B < E -> A - B - E - C - D
            t = {s[0], s[1], s[4], s[2], s[3]};
        }
      } else {                     // E < A -> E - A - C - D
        if (query(s[1], s[2])) {   // B > C
          if (query(s[1], s[3])) { // B > D -> E - A - C - D - B
            t = {s[4], s[0], s[2], s[3], s[1]};
          } else { // B < D -> E - A - C - B - D
            t = {s[4], s[0], s[2], s[1], s[3]};
          }
        } else { // E - A - B - C - D
          t = {s[4], s[0], s[1], s[2], s[3]};
        }
      }
    }

    s = t;
  } else {
    mergesort(s, 0, s.length());
  }

  cout << "! " << s << endl;
}
