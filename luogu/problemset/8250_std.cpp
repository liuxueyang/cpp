#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l, _ = r; i <= _; ++i)
using namespace std;
typedef long long ll;
const int mN = 2e5 + 9, mM = 7e5 + 9;
int n, m, q, deg[mN];

vector<int> ver[mN];

int ans[mN];
vector<pair<int, int>> qn[mN];

int vis[mN];

int main() {

  scanf("%d%d%d", &n, &m, &q);
  rep(i, 1, m) {
    int x, y;
    scanf("%d%d", &x, &y);
    ++deg[x], ++deg[y];
    ver[x].push_back(y), ver[y].push_back(x);
  }
  rep(i, 1, q) {
    int x, y;
    scanf("%d%d", &x, &y);
    ans[i] = deg[x]; // ans 的剩余部分（deg[x]-g(x, y)）中，x y 地位相等
    if (deg[x] < deg[y])
      swap(x, y); // 保证 x 的 deg 更大
    qn[x].push_back({y, i});
  }

  rep(x, 1, n) {
    sort(qn[x].begin(), qn[x].end()); // 为了去重

    for (int y : ver[x]) {
      vis[y] = x;
    }
    int lst = 0, lstans = 0;
    // lst 记录上一个询问的 y, lstans 记录上一个询问的 deg[x]-g(x, y)
    for (auto ask : qn[x]) {
      const int y = ask.first, id = ask.second;
      if (y == lst) {
        ans[id] -= lstans;
        continue;
      }
      lstans = vis[y] == x;
      for (int z : ver[y]) {
        lstans += vis[z] == x;
      }
      ans[id] -= lstans;
      lst = y;
    }
  }
  rep(i, 1, q) printf("%d\n", ans[i]);
  return 0;
}
