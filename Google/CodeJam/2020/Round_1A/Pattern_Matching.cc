#include <bits/stdc++.h>

using namespace std;

string solve1(int N) {
  // Test set 1: only the first character is an asterisk.
  // from left to right try to match every pattern.
  string ans;

  vector<string> ptns(N);
  for (int i = 0; i < N; i++) {
    cin >> ptns[i];
    reverse(ptns[i].begin(), ptns[i].end());
  }

  sort(ptns.begin(), ptns.end());

  bool matched = true;
  for (int i = 0; i < ptns.back().length() - 1; i++) {

    for (int j = 0; j < N; j++) {
      if (i >= ptns[j].length() - 1)
        continue;

      if (ptns[j][i] != ptns.back()[i]) {
        matched = false;
        break;
      }
    }

    if (!matched)
      break;
  }

  if (matched) {
    ans = ptns.back().substr(0, ptns.back().length() - 1);
    reverse(ans.begin(), ans.end());
  } else {
    ans = "*";
  }

  return ans;
}

bool isMatched(vector<string> &ptns) {
  bool matched = true;
  if (ptns.empty())
    return true;

  for (int i = 0; i < ptns.back().length(); i++) {
    for (int j = 0; j < ptns.size(); j++) {
      if (i >= ptns[j].length())
        continue;

      if (ptns[j][i] != ptns.back()[i])
        return false;
    }
  }

  return true;
}

string solve2(int N) {
  vector<string> pres, sufs;

  for (int i = 0; i < N; i++) {
    string p;
    cin >> p;

    string pre = p.substr(0, p.find('*'));
    string suf = p.substr(p.find('*') + 1);
    reverse(suf.begin(), suf.end());

    if (!pre.empty())
      pres.push_back(pre);
    if (!suf.empty())
      sufs.push_back(suf);
  }

  sort(pres.begin(), pres.end());
  sort(sufs.begin(), sufs.end());

  if (!isMatched(pres) || !isMatched(sufs))
    return "*";

  string ans;
  if (!pres.empty())
    ans += pres.back();
  if (!sufs.empty()) {
    reverse(sufs.back().begin(), sufs.back().end());
    ans += sufs.back();
  }

  return ans;
}

string solve3(int N) {
  vector<string> pres, sufs, mids;

  for (int i = 0; i < N; i++) {
    string p;
    cin >> p;

    int pos1 = p.find('*'), pos2 = p.rfind('*');

    string pre = p.substr(0, pos1);
    string suf = p.substr(pos2 + 1);
    reverse(suf.begin(), suf.end());

    if (!pre.empty())
      pres.push_back(pre);
    if (!suf.empty())
      sufs.push_back(suf);

    string mid;
    for (int i = pos1 + 1; i < pos2; i++)
      if (p[i] != '*')
        mid.push_back(p[i]);
    mids.push_back(mid);
  }

  sort(pres.begin(), pres.end());
  sort(sufs.begin(), sufs.end());

  if (!isMatched(pres) || !isMatched(sufs))
    return "*";

  string ans;
  if (!pres.empty())
    ans += pres.back();
  for (string mid : mids)
    ans += mid;
  if (!sufs.empty()) {
    reverse(sufs.back().begin(), sufs.back().end());
    ans += sufs.back();
  }

  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    string ans = solve3(N);

    cout << "Case #" << (t + 1) << ": " << ans << endl;
  }
}
