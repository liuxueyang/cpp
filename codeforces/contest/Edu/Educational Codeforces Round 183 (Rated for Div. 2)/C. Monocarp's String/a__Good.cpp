#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

#define forn(i, n) for (int i = 0; i < int(n); i++)

void solve() {
  int n;
  string s;
  cin >> n >> s;
  int cur = count(s.begin(), s.end(), 'a') - count(s.begin(), s.end(), 'b');
  map<int, int> lst;
  int pr = 0;
  lst[pr] = -1;
  int ans = n;
  forn(i, n) {
    pr += s[i] == 'a' ? 1 : -1;
    lst[pr] = i;
    if (lst.count(pr - cur)) {
      dbg(i, pr, cur);
      ans = min(ans, i - lst[pr - cur]);
    }
  }
  cout << (ans == n ? -1 : ans) << '\n';
}

int main() {
#if defined(_DEBUG) && !defined(_CPH) && !defined(_SUB)
  freopen("input.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  forn(i, t) solve();
}
