// Date: Thu Aug  8 23:24:49 2024

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

const int N = 200100, M = 1400100;

int n, m, q, idx, h[N], d[N], col[N];
int e[M], ne[M];

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(d, 0, sizeof d);
}

void Add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void solve() {
  Init();
  cin >> n >> m >> q;

  For1(i, 1, m) {
    int u, v;
    cin >> u >> v;
    Add(u, v), Add(v, u);
    d[u]++, d[v]++;
  }

  int D = m / sqrt(q) + 1;

  vector<PII> que;
  map<PII, int> res;
  map<int, set<int>> big;
  VI ans(q, 0);

  For(i, 0, q) {
    int u, v;
    cin >> u >> v;
    que.pb({u, v});

    ans[i] = d[u];

    if (d[u] < d[v])
      swap(u, v);
    if (d[u] >= D)
      big[u].insert(v);
  }

  set<int> vis;

  for (auto &[u, ed] : big) {
    ForE(i, u) {
      int v = e[i];
      col[v] = u;
    }

    for (auto v : ed) {
      if (has(vis, v))
        continue;

      int cnt = 0;
      if (col[v] == u)
        cnt++;
      ForE(i, v) {
        int v1 = e[i];
        if (col[v1] == u)
          cnt++;
      }

      res[{u, v}] = cnt;
    }
    vis.insert(u);
  }

  for (auto &[u, v] : que) {
    if (has(res, PII(u, v)) || has(res, PII(v, u)))
      continue;

    ForE(i, u) {
      int v1 = e[i];
      col[v1] = u;
    }

    int cnt = 0;
    if (col[v] == u)
      cnt++;

    ForE(i, v) {
      int v1 = e[i];
      if (col[v1] == u)
        cnt++;
    }

    res[{u, v}] = cnt;
  }

  For(i, 0, q) {
    int u = que[i].f1, v = que[i].f2;
    if (has(res, PII(u, v))) {
      ans[i] -= res[{u, v}];
    } else {
      ans[i] -= res[{v, u}];
    }
    cout << ans[i] << '\n';
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("8250.in", "r", stdin);
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
