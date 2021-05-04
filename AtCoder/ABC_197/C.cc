#include <bits/stdc++.h>

#define LL long long

using namespace std;

int N; 
int bst;

void dfs(vector<int> &points, vector<vector<int>> &dp) {
  int cur = points.back();
  if (cur == N) {
    int ans = dp[points[0]][points[1]-1];
    for (int i = 1; i < points.size() - 1; i ++) 
      ans ^= dp[points[i]][points[i+1]-1];

    bst = min(bst, ans);

    return;
  }

  for (int i = cur + 1; i <= N; i ++) {
    points.push_back(i);
    dfs(points, dp);
    points.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  vector<int> A(N); for (int &i: A) cin >> i;

  vector dp(N, vector<int>(N)); 
  for (int i = 0; i < N; i ++)
    for (int j = i; j < N; j ++)
      dp[i][j] = (j == i) ? A[j] : (A[j] | dp[i][j-1]);

  bst = INT_MAX;
  vector<int> points{0};
  dfs(points, dp);
  cout << bst << endl;  
}
