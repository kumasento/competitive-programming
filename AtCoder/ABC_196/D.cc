#include <bits/stdc++.h>
using namespace std;
#define LL long long

int H, W, A, B, ans = 0; 

// bit defines the current board. If bit is set, then that place
// has been covered by a mat already.
void dfs(int i, int bit, int A, int B) {
  // i is the counter, from left to right, top to bottom.
  if (i == H * W) { ans ++; return; }

  // If the previous setting has already covered this point.
  // e.g., a 1x2 mat, or a 2x1 mat from the top,
  // then we can skip to the next.
  if (bit & (1 << i))
    return dfs(i + 1, bit, A, B);
  
  // Use B and simply set the next mat.
  if (B)
    dfs(i + 1, bit | (1 << i), A, B - 1);

  // Use A
  if (A) {
    // Set as 1 x 2
    if (i % W != W - 1 && ~(bit & (1 << (i + 1))))
      dfs(i + 1, bit | 1 << i | 1 << (i + 1), A - 1, B);
    // Set as 2 x 1
    if (i + W < H * W)
      dfs(i + 1, bit | 1 << i | 1 << (i + W), A - 1, B);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> H >> W >> A >> B;
  dfs(0, 0, A, B);
  cout << ans << endl;
}
