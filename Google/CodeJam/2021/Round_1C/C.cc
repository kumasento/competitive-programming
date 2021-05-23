#include <bits/stdc++.h>

#define LL long long

using namespace std;

string Trim(const string &S) {
  if (S.length() == 1)
    return S;

  assert(!S.empty());
  string T;
  bool is_lead = true;
  for (int i = 0; i < S.length(); i ++) {
    if (is_lead) {
      if (S[i] == '0') continue;
      is_lead = false;
      T.push_back(S[i]);
    } else {
      T.push_back(S[i]);
    }
  }
  if (T.empty())
    T.push_back('0');
  return T;
}

string Not(const string &S) {
  assert(!S.empty());
  string T;
  for (char c : S)
    T.push_back('0' + 1 - (c - '0'));
  return Trim(T); 
}

string Double(const string &S) {
  if (S == "0")
    return S;
  string T(S);
  T.push_back('0');
  return T;
}

LL dfs(const string &S, const string &E, set<string> &path, map<string, LL> &memo, int max_depth, int depth = 0) {
  if (S == E)
    return 0;
  if (memo.count(S))
    return memo[S];

  if (depth >= max_depth)
    return -1;

  path.insert(S);
  string S1 = Not(S);

  int ans1 = -1, ans2 = -1;
  if (!path.count(S1))
    ans1 = dfs(S1, E, path, memo, max_depth, depth + 1);

  if (S != "0") {
    string S2 = Double(S);
    ans2 = dfs(S2, E, path, memo, max_depth, depth + 1);
  }

  path.erase(S);

  if (ans1 == -1)
    memo[S] = ans2 == -1 ? -1 : ans2 + 1;
  else if (ans2 == -1)
    memo[S] = ans1 == -1 ? -1 : ans1 + 1;
  else
    memo[S] = min(ans1, ans2) + 1;

  return memo[S];
}

int main() {
  int T; cin >> T;

  // assert(Trim("0") == "0");
  // assert(Trim("0000") == "0");
  // assert(Trim("0001") == "1");
  // assert(Trim("000101") == "101");
  // assert(Trim("101") == "101");

  for (int t = 1; t <= T; t ++) {
    string S, E;
    cin >> S >> E;     

    set<string> path;
    map<string, LL> memo;
    LL ans = dfs(S, E, path, memo, max(S.length(), E.length()));

    cout << "Case #" << t << ": " << (ans == -1 ? "IMPOSSIBLE" : to_string(ans)) << endl;
  }

#if 1
  for (int i = 0; i < (1 << 8); i ++) {
    for (int j = 0; j < (1 << 8); j ++) {
      string S = bitset<8>(i).to_string();
      string E = bitset<8>(j).to_string();

      S = Trim(S);
      E = Trim(E);

      set<string> path;
      map<string, LL> memo;
      LL ans = dfs(S, E, path, memo, 16);
      cout << "S: " << S << " -> E: " << E << " = " << ans << endl;
    }
  }
  #endif
}
