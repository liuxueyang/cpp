// Date: Sun Jul 28 21:30:26 2024

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

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr()
#endif

const int N = 5100, M = 200100;
int n, m;

namespace ufs {
const int N = ::N;
int fa[N], sz[N], n;

void Init() {
  for (int i = 1; i <= n; ++i)
    fa[i] = i, sz[i] = 1;
}

int Find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = Find(fa[x]);
}

void Union(int x, int y) {
  int rx = Find(x), ry = Find(y);
  if (rx == ry)
    return;
  fa[ry] = rx;
  sz[rx] += sz[ry];
}
} // namespace ufs

namespace kruskal {
const int M = ::M;
int n, m;

struct Edge {
  int a, b, w;
  bool operator<(const Edge &o) const { return w < o.w; }
};

Edge edges[M];

int kruskal() {
  sort(edges + 1, edges + 1 + m);

  int res{}, cnt{};
  ufs::Init();

  For1(i, 1, m) {
    auto &ed = edges[i];
    int a = ed.a, b = ed.b, w = ed.w;

    int ra = ufs::Find(a), rb = ufs::Find(b);
    if (ra != rb) {
      ufs::Union(ra, rb);
      res += w;
      cnt++;
    }
  }

  return (cnt < n - 1 ? -1 : res);
}
} // namespace kruskal

void solve() {
  cin >> n >> m;
  ufs::n = n;
  kruskal::n = n;
  kruskal::m = m;

  For1(i, 1, m) {
    int a, b, w;
    cin >> a >> b >> w;
    kruskal::edges[i] = {a, b, w};
  }

  int ans = kruskal::kruskal();
  if (ans == -1)
    cout << "orz\n";
  else
    cout << ans << '\n';
}

int main(void) {
#ifdef _DEBUG
  freopen("3366.in", "r", stdin);
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
