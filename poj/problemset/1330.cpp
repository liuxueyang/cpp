// Date: Mon Aug 12 23:47:37 2024

#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const ull Pr = 131;

#define For(i, a, b) for (int i = int(a); i < int(b); ++i)
#define Rof(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define For1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define Rof1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define ForE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define NL cout << '\n';

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

const int N = 10100, M = 100;
VI edge[N];
int f[N][M];
int dep[N], father[N];
int n;

namespace LCA {

void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  father[x] = fa;
  f[x][0] = fa;

  for (int j = 1; (1 << j) <= dep[x]; ++j) {
    f[x][j] = f[f[x][j - 1]][j - 1];
  }

  for (VI::iterator it = edge[x].begin(); it != edge[x].end(); it++) {
    if (*it != fa)
      dfs(*it, x);
  }
}

int lca(int x, int y) {
  if (dep[x] < dep[y])
    swap(x, y);

  int maxd = log2(n) + 1;

  Rof1(i, 0, maxd) {
    if (dep[f[x][i]] >= dep[y])
      x = f[x][i];
  }
  if (x == y)
    return x;

  Rof1(i, 0, maxd) {
    if (f[x][i] != f[y][i]) {
      x = f[x][i];
      y = f[y][i];
    }
  }
  return f[x][0];
}
} // namespace LCA

void solve() {
  cin >> n;
  For1(i, 1, n) { edge[i].clear(); }
  memset(dep, 0, sizeof dep);
  memset(f, 0, sizeof f);
  memset(father, 0, sizeof father);

  For1(i, 1, n - 1) {
    int u, v;
    cin >> u >> v;
    edge[u].pb(v);
    father[v] = u;
  }

  int s = 1;
  while (father[s] != 0) {
    s = father[s];
  }

  dep[s] = 1;
  LCA::dfs(s, 0);
  int u, v;
  cin >> u >> v;

  int ans = LCA::lca(u, v);
  cout << ans << '\n';
}

int main(void) {
#ifdef _DEBUG
  freopen("1330.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 1;
  cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}
