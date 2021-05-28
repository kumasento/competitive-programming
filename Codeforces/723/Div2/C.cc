/**
 * Author: kumasento
 * Date:   2021-05-28T16:00:52.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// --------------------- Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// --------------------- Constants:
constexpr int IINF = 1000000000;
constexpr LL LINF = 10000000000000000LL;
constexpr LL MOD = 1e9 + 7;

/// --------------------- Helpers:
#define DEBUG_VAR(x) { cout << #x << " = " << x << '\n'; }
#define DEBUG_VEC(vec) { for (auto i : (vec)) cout << i << " "; cout << '\n'; }

/// --------------------- Globals:

/// --------------------- Solution:


struct node {
  int s, e, m;
  LL val = 0; LL lazy = 0;
  node *l, *r;

  node(int S, int E) {
    s = S, e = E, m = (s + e) / 2;
    if (s != e) {
      l = new node(s, m);
      r = new node(m+1, e);
    }
  }

  void apply(LL L) {
    val += L;
    lazy += L;
  }

  void push() {
    if (s == e) return ;
    l->apply(lazy);
    r->apply(lazy);
    lazy = 0;
  }

  void update(int S, int E, LL L) {
    push();

    if (s == S && E == e) {
      apply(L);
      return;
    }

    else if (E <= m) l->update(S, E, L);
    else if (S >= m + 1) r->update(S, E, L);
    else l->update(S, m, L), r->update(m+1, E, L);
    val = min(l->val, r->val);
  }

  LL query(int S, int E) {
    push();
    if (s == S && E == e) return val;
    else if (E <= m) return l->query(S, E);
    else if (S >= m + 1) return r->query(S, E);
    else return min(l->query(S, m), r->query(m+1, E));
  }

};



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("C.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif

  int n; cin >> n;

#if 0
  vector<LL> a(n); for (LL &i: a) cin >> i; 
  vector<LL> dp(n + 1, LINF); // dp[i] the minimum health to get i potions
  dp[0] = 0;
  for (int i = n - 1; i >= 0; i --) {
    if (a[i] >= 0) {
      for (int j = n; j >= 1; j --) {
        dp[j] = max(dp[j] - a[i], 0LL);
      }
    } else {
      for (int j = n; j >= 1; j --) {
        dp[j] = min(dp[j-1] - a[i], dp[j]); 
      }
    }
  }

  int num_pos = 0; for (int i : a) num_pos += (i >= 0);

  int bst = 0;
  for (int i = 0; i <= n; i ++) 
    if (dp[i] == 0)
      bst = i;
  
  cout << bst + num_pos << endl;
#endif

#if 0
  vector<LL> a(n); for (LL &i: a) cin >> i; 
  // DP from the editorial
  // dp[i][k] - maximum health considering the first i potions and taking k of them.
  vector<vector<LL>> dp(n+1, vector<LL>(n+1, -1));

  // dp[i][k] = max(dp[i-1][k-1] + a[i], dp[i-1][k]) where dp[i-1][k-1]+a[i] >= 0.
  for (int i = 0; i <= n; i ++) dp[i][0] = 0;
  for (int i = 0; i < n; i ++) {
    for (int k = 0; k <= i; k ++) {
      dp[i+1][k+1] = dp[i][k+1]; 
      if (dp[i][k] != -1 && dp[i][k] + a[i] >= 0)
        dp[i+1][k+1] = max(dp[i][k] + a[i], dp[i][k+1]);
    }

    // DEBUG_VEC(dp[i+1]);
  }


  int bst = 0;
  for (int i = 1; i <= n; i ++)
    if (dp[n][i] >= 0) 
      bst = i;

  cout << bst << endl;

#endif 


  // Greedy & Segment tree
#if 0
  vector<PLL> a(n); for (int i = 0; i < n; i ++) { cin >> a[i].first; a[i].second = i; } 

  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  int ans = 0;

  node *root = new node(0, n - 1);
  for (int i = 0; i < n; i ++) {
    int pos = a[i].second; // the original index of the i-th largest potion.
    LL x = a[i].first;

    // query the minimum value starting from pos
    // if adding x won't make the min potion less than 0, we take x, and propagate
    // this effect to all the rest.
    if (x + root->query(pos, n - 1) >= 0) {
      ans ++;
      root->update(pos, n-1, x);
    }
  }

  cout << ans << endl;

#endif

  vector<LL> a(n); for (LL &i: a) cin >> i; 
  
  priority_queue<LL, vector<LL>, greater<LL>> pq;
  LL sum = 0;

  for (int i = 0; i < n; i ++) {
    sum += a[i];
    pq.push(a[i]);

    while (sum < 0) {
      sum -= pq.top();
      pq.pop();
    }
  }

  cout << pq.size() << endl;
}
