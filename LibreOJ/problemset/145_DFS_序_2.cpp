#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
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
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<bool> VB;
typedef vector<vector<bool>> VVB;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998244353;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};
mt19937_64 _m_gen64;

const ull Pr = 131, Pr1 = 13331;

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

template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}

template <typename t>
istream &operator>>(istream &in, vector<t> &vec) {
  for (t &x : vec) in >> x;
  return in;
}

template <typename t>
ostream &operator<<(ostream &out, vector<t> &vec) {
  int n = SZ(vec);
  For(i, 0, n) {
    out << vec[i];
    if (i < n - 1) out << ' ';
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
    if (it != begin) cout << ' ';
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

// int128 input and output
#ifdef _DEBUG
using lll = __int128;

istream &operator>>(istream &is, lll &v) {
  string s;
  is >> s;
  v = 0;
  for (auto &it : s)
    if (isdigit(it)) v = v * 10 + it - '0';
  if (s[0] == '-') v *= -1;
  return is;
}

ostream &operator<<(ostream &os, const lll &v) {
  if (v == 0) return (os << "0");
  lll num = v;
  if (v < 0) os << '-', num = -num;
  string s;
  for (; num > 0; num /= 10) s.pb((char)(num % 10) + '0');
  reverse(all(s));
  return (os << s);
}
#endif
// end of int128

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

const int N = 1000010;
int a[N], dfn[N], dfo[N], b[N];
int e[N * 2], ne[N * 2], h[N];
int ts, idx;

struct tag {
  ll d;
  tag() : d(0) {}
  tag(ll d_) : d(d_) {}
  tag operator+(const tag &rh) const { return {d + rh.d}; }
};

struct Info {
  int len;
  ll sum;
  Info() : len(1), sum(0) {}
  Info(int len_, ll sum_) : len(len_), sum(sum_) {}

  Info operator+(const Info &rh) const { return {len + rh.len, sum + rh.sum}; }
  Info operator+(const tag &rh) const { return {len, sum + len * rh.d}; }
};

struct node {
  Info val;
  tag t;
};

node seg[N * 4];

struct SegmentTree {
  int n;

  SegmentTree() : n(0) {}
  SegmentTree(int n_) : n(n_) {}

  void set_tag(int id, tag t) {
    seg[id].val = seg[id].val + t;
    seg[id].t = seg[id].t + t;
  }

  void update(int id) {
    int left = id * 2, right = left + 1;
    seg[id].val = seg[left].val + seg[right].val;
  }

  void push_down(int id) {
    auto &t = seg[id].t;
    if (t.d != 0) {
      int left = id * 2, right = left + 1;
      set_tag(left, t);
      set_tag(right, t);
      t.d = 0;
    }
  }

  void build(int id, int l, int r) {
    if (l == r) {
      seg[id].val = {1, a[l]};
      return;
    }
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void modify(int id, int l, int r, int ql, int qr, tag t) {
    if (l >= ql && r <= qr) {
      set_tag(id, t);
      return;
    }
    push_down(id);

    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (qr <= mid)
      modify(left, l, mid, ql, qr, t);
    else if (ql > mid)
      modify(right, mid + 1, r, ql, qr, t);
    else {
      modify(left, l, mid, ql, mid, t);
      modify(right, mid + 1, r, mid + 1, qr, t);
    }
    update(id);
  }

  Info query(int id, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) {
      return seg[id].val;
    }

    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    push_down(id);
    if (qr <= mid)
      return query(left, l, mid, ql, qr);
    else if (ql > mid)
      return query(right, mid + 1, r, ql, qr);
    else
      return query(left, l, mid, ql, mid) +
             query(right, mid + 1, r, mid + 1, qr);
  }
};

void Init() {
  idx = ts = 0;
  memset(h, -1, sizeof h);
}

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int u, int fa) {
  dfn[u] = ++ts;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    if (v == fa || dfn[v]) continue;
    dfs(v, u);
  }
  dfo[u] = ts;
}

void solve() {
  int n, m, r;
  cin >> n >> m >> r;
  Init();

  For1(i, 1, n) cin >> a[i];

  For(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    add(u, v), add(v, u);
  }

  dfs(r, -1);
  For1(i, 1, n) {
    int pos = dfn[i];
    b[pos] = a[i];
  }
  For1(i, 1, n) a[i] = b[i];

  SegmentTree tree(n);
  tree.build(1, 1, n);

  while (m--) {
    int op, pos, x;
    cin >> op;
    if (op == 1) {
      cin >> pos >> x;
      int l = dfn[pos], r = dfo[pos];
      tree.modify(1, 1, n, l, r, x);
    } else {
      cin >> pos;
      int l = dfn[pos], r = dfo[pos];
      ll res = tree.query(1, 1, n, l, r).sum;
      cout << res << '\n';
    }
  }
}

int main(void) {
#ifdef _DEBUG
#ifndef _CPH
  freopen("../input.txt", "r", stdin);
#endif
#endif

  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

  int T = 1;
  // cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}
