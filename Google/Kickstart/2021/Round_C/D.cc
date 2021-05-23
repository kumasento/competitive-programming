/**
 * Author: kumasento
 * Date:   2021-05-23T13:49:25.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// Types:
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLI = pair<LL, int>;
using PLL = pair<LL, LL>;

/// Constants:
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;


class BigInt {
public:
  string s;

  BigInt() : s("") {}
  BigInt(string x) { *this = x; }
  BigInt(int x) { *this = to_string(x); }
  void operator=(string s) { reverse(s.begin(), s.end()); this->s = s; }
  bool operator==(const BigInt& x) const { return s == x.s; }

  BigInt operator+(BigInt x) {
    BigInt curr = *this;
    BigInt res;
    for (int a = 0, carry = 0; a < s.size() || a < x.s.size() || carry; a++) {
      carry += (a < curr.s.size() ? curr.s[a] - '0' : 0) + (a < x.s.size() ? x.s[a] - '0' : 0);
      res.s += (carry % 10 + '0');
      carry /= 10;
    }
    return res;
  }
  BigInt operator*(BigInt x) {
    BigInt res("0");
    for (int a = 0, b = s[a] - '0'; a < s.size(); a++, b = s[a] - '0') {
      while (b--) res = (res + x);
      x.s.insert(x.s.begin(), '0');
    }
    return res;
  }

  string toString() const {
    string ret = s;
    reverse(ret.begin(), ret.end());
    return ret;
  }
};

/// Globals:

/// Solution:

struct Expr {
  char op;
  BigInt num;
  bool hasSharp = false;
  Expr *L = NULL, *R = NULL;

  Expr(BigInt num) : num(num), op('n'), L(NULL), R(NULL) {
  }
  Expr(char op, Expr *L, Expr *R): op(op), L(L), R(R) {}
  Expr(char op): op(op) {}
};
void print(Expr *e) {
  if (!e) return;
  cout << "(" << e->op << " " << e->num.toString() << " ";
  print(e->L);
  print(e->R);
  cout << ")";
}

void dfs(Expr *e) {
  if (!e) return;
  if (!e->L || !e->R) return;

  dfs(e->L);
  dfs(e->R);
  if (e->op == '#') { e->hasSharp = true; return; }

  if (e->L->op == 'n' && e->R->op == 'n') {
    if (e->op == '*') {
      e->num = e->L->num * e->R->num;
      e->op = 'n';
      e->L = e->R = NULL;
    } else if (e->op == '+') {
      e->num = e->L->num + e->R->num;
      e->op = 'n';
      e->L = e->R = NULL;
    }
    return ;
  }

  if (e->L->hasSharp || e->R->hasSharp) {
    e->hasSharp = true;
    if (e->R->hasSharp) {
      swap(e->L, e->R);
    }
  }

  if (e->op == '*') {
    if (e->R->num == BigInt(1)) {
      e->op = e->L->op;
      e->num = e->L->num;
      e->R = e->L->R;
      e->L = e->L->L;
    } else if (e->R->num == BigInt(0)) {
      e->op = 'n';
      e->num = BigInt(0);
      e->R = e->L = NULL;
    } else if (e->L->op == '*') {
      e->R->num = e->L->R->num * e->R->num;
      e->L = e->L->L;
    }

    return;
  }
  if (e->op == '+') {
    if (e->R->num == BigInt(0)) {
      e->op = e->L->op;
      e->num = e->L->num;
      e->R = e->L->R;
      e->L = e->L->L;
    } else if (e->L->op == '+') {
      e->R->num = e->L->R->num + e->R->num;
      e->L = e->L->L;
    }

    return;
  }
}

bool dfs2(Expr *e1, Expr *e2) {
  if (!e1 && e2) return false;
  if (e1 && !e2) return false;
  if (!e1 && !e2) return true;

  if (e1->op != e2->op)
    return false;
  if (e1->op == 'n') {
    return e1->num == e2->num;
  }
  return dfs2(e1->L, e2->L) && dfs2(e1->R, e2->R);
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef LOCAL_DEBUG
  ifstream in("D.in"); cin.rdbuf(in.rdbuf());
#endif

  int T; cin >> T;
  for (int t = 1; t <= T; t ++) {

    int N; cin >> N; vector<string> E(N); for (string &e : E) cin >> e;

    vector<Expr *> exprs;

    for (auto &s : E) {
      int n = s.length(); stack<Expr *> st; int i = 0;
      while (i < n) {
        char c = s[i];
        if (c == '(') {
          st.push(new Expr('('));
        } else if (c == ')') {
          Expr *R = st.top(); st.pop();
          Expr *e = st.top(); st.pop(); e->R = R;
          st.pop(); // (
          st.push(e);
        } else if (isdigit(c)) {
          int j = i + 1; while (j < n && isdigit(s[j])) j ++;
          st.push(new Expr(BigInt(s.substr(i, j - i)))); i = j - 1;
        } else { Expr *e = new Expr(c, st.top(), NULL); st.pop(); st.push(e); }
        i ++;
      }

      exprs.push_back(st.top()); st.pop();
      dfs(exprs.back());
    }

    vector<int> ans(N, -1);
    int cnt = 1;
    for (int i = 0; i < N; i ++) {
      if (ans[i] != -1) continue;
      ans[i] = cnt ++;
      for (int j = i + 1; j < N; j ++) {
        if (dfs2(exprs[i], exprs[j]))
          ans[j] = ans[i];
      }
    }

    cout << "Case #" << t << ": ";
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }


}
