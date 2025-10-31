#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define REP(i, b, e) for (int i = (b); i < (int)(e); ++i)
int l, r;
int tot;
int son[6000005][2], cnt[6000005];
void Main() {
  cin >> l >> r;
  tot = 1;
  son[0][0] = son[0][1] = -1;
  REP(i, l, r + 1) {
    int x = 0;
    REP(j, 0, 30) {
      int &p = son[x][(i >> j) & 1];
      if (p == -1)
        p = tot++, cnt[p] = 0, son[p][0] = son[p][1] = -1;
      x = p;
      ++cnt[x];
    }
  }
  int ans = 0;
  vector<int> res;
  REP(i, l, r + 1) {
    int x = 0, t = 0;
    REP(j, 0, 30) {
      int o = !((i >> j) & 1);
      if (son[x][o] == -1 || !cnt[son[x][o]])
        o = !o;
      t |= o << j;
      x = son[x][o];
      --cnt[x];
    }
    res.pb(t);
    ans += i | t;
  }
  cout << ans << '\n';
  for (auto i : res)
    cout << i << ' ';
  cout << '\n';
}
void TC() {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    Main();
  }
}
signed main() {
  return cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), TC(), 0;
}
/*
1. CLEAR the arrays (ESPECIALLY multitests)
2. DELETE useless output
 */
