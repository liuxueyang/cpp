// Date: Mon Aug 12 21:33:20 2024

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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998244353;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

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
#define nemp(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define all1(a, len) (a + 1), (a + 1 + len)
#define SZ(a) int((a).size())
#define NL cout << '\n';

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <typename t> istream &operator>>(istream &in, vector<t> &vec) {
  for (t &x : vec)
    in >> x;
  return in;
}

template <typename t> ostream &operator<<(ostream &out, vector<t> &vec) {
  int n = SZ(vec);
  For(i, 0, n) {
    out << vec[i];
    if (i < n - 1)
      out << ' ';
  }
  return out;
}

template <typename ForwardIterator>
void Inputr(ForwardIterator begin, ForwardIterator end) {
  ForwardIterator it = begin;
  while (it != end) {
    cin >> *it;
    it++;
  }
}

template <typename ForwardIterator>
void Outputr(ForwardIterator begin, ForwardIterator end) {
  ForwardIterator it = begin;
  while (it != end) {
    if (it != begin)
      cout << ' ';
    cout << *it;
    it++;
  }
  NL;
}

template <typename T, typename ForwardIterator>
void Outputr1(ForwardIterator begin, ForwardIterator end) {
  copy(begin, end, ostream_iterator<T>(cout, " "));
  NL;
}

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

const int N = 500100;
int n, m, s;

namespace LCA {
vector<VI> edge;
vector<VI> f;
VI dep, father;
int n;

void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  father[x] = fa;
  f[x][0] = fa;

  for (int j = 1; (1 << j) <= dep[x]; ++j) {
    f[x][j] = f[f[x][j - 1]][j - 1];
  }

  for (auto y : edge[x]) {
    if (y != fa)
      dfs(y, x);
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
  cin >> n >> m >> s;

  LCA::n = n;
  LCA::edge = vector<VI>(N + 10);
  LCA::dep = VI(N + 10, 0);

  LCA::f = vector<VI>(N + 10, VI(100, 0));
  LCA::father = VI(N + 10, 0);

  For(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    LCA::edge[u].pb(v);
    LCA::edge[v].pb(u);
  }

  LCA::dep[s] = 1;
  LCA::dfs(s, 0);
  For(i, 0, m) {
    int u, v;
    cin >> u >> v;
    cout << LCA::lca(u, v) << '\n';
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("3379.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 1;

  while (T--) {
    solve();
  }

  return 0;
}
