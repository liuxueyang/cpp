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
vector<vector<PII>> gque(N + 1);

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

  VI ans(q, 0);

  For(i, 0, q) {
    int u, v;
    cin >> u >> v;

    ans[i] = d[u];

    if (d[u] < d[v])
      swap(u, v);

    gque[u].pb({v, i});
  }

  map<PII, int> com;

  For1(u, 1, n) {
    auto &quei = gque[u];
    sort(all(quei));

    ForE(j, u) {
      int v = e[j];
      col[v] = u;
    }

    int len = SZ(quei), lst_cnt = 0;
    For(k, 0, len) {
      int u1 = quei[k].f1, id = quei[k].f2;

      if (k && u1 == quei[k - 1].f1) {
        ans[id] -= lst_cnt;
        continue;
      }
      if (has(com, PII(u, u1))) {
        ans[id] -= com[{u, u1}];
        lst_cnt = com[{u, u1}];
        continue;
      }

      int cnt = 0;
      if (col[u1] == u)
        cnt++;
      ForE(i1, u1) {
        int v1 = e[i1];
        if (col[v1] == u)
          cnt++;
      }

      lst_cnt = cnt;
      ans[id] -= cnt;
      com[{u, u1}] = com[{u1, u}] = cnt;
    }
  }

  For(i, 0, q) { cout << ans[i] << '\n'; }
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
