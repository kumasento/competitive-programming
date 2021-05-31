/**
 * Author: kumasento
 * Date:   2021-05-31T15:17:20
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
constexpr int INF = 1e9;
constexpr LL LINF = 1e16;
constexpr LL MOD = 1e9 + 7;

/// --------------------- Helpers:
// *** Credit to Neal Wu
// overload operator<<() for pairs.
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// overload container output. Won't affect strings.
template <typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream &operator<<(ostream &os, const C &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// variadic debugger.
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/// --------------------- Globals:

/// --------------------- Solution:

bool delim(char c) { return c == ' '; }
bool is_op(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }
bool is_unary(char c) { return c == '+' || c == '-'; }
int priority(char op) {
  if (op < 0) return 3;
  if (op == '*' || op == '/') return 2;
  if (op == '+' || op == '-') return 1;
  return -1;
}

void process_op(stack<int> &st, char op) {
  if (op < 0) {
    int l = st.top(); st.pop();
    switch (-op) {
      case '+': st.push(l); break;
      case '-': st.push(-l); break;
    }
  } else {
    int r = st.top(); st.pop();
    int l = st.top(); st.pop();
    switch (op) {
      case '+': st.push(l + r); break;
      case '-': st.push(l - r); break;
      case '*': st.push(l * r); break;
      case '/': st.push(l / r); break;
    }
  }
}

int evaluate(const string &s) {
  stack<int> st; stack<char> op;
  bool may_be_unary = true;
  for (int i = 0; i < (int)s.length(); i ++) {
    if (delim(s[i])) continue;
    if (s[i] == '(') {
      op.push('(');
      may_be_unary = true; // op followed a ( can be an unary
    } else if (s[i] == ')') {
      while (op.top() != '(') {
        process_op(st, op.top());
        op.pop();
      }
      op.pop();
      may_be_unary = false;
    } else if (is_op(s[i])) {
      char cur_op = s[i];
      if (may_be_unary && is_unary(cur_op)) // turn cur_op to an unary.
        cur_op = - cur_op;
      while (!op.empty() && (
          /* left assoc: higher/equiv priority eval first */
          (cur_op >= 0 && priority(cur_op) <= priority(op.top())) ||
          /* right assoc: higher priority eval first */
          (cur_op < 0 && priority(cur_op) < priority(op.top())))) {
        process_op(st, op.top());
        op.pop();
      }
      op.push(cur_op);
      may_be_unary = true;
    } else {
      int num = 0;
      while (i < (int)s.length() && isalnum(s[i]))
        num = num * 10 + s[i++] - '0';
      --i;
      st.push(num);
      may_be_unary = false;
    }
  }

  while (!op.empty()) {
    process_op(st, op.top());
    op.pop();
  }
  return st.top();
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #ifdef LOCAL_DEBUG
  ifstream in("main.in"); if (in) cin.rdbuf(in.rdbuf());
  #endif


  dbg(evaluate("1 + 2 * (4 - 6 / 3)"));
  dbg(evaluate("1 + 2 * (4 - -6 / 3)"));

}
