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

VI a;

struct info {
  int mie, cnt;
  info() : mie(0), cnt(0) {}
  info(int x) : mie(x), cnt(1) {}
  info(int x, int cnt_) : mie(x), cnt(cnt_) {}
  info operator+(const info &rh) const {
    info res(min(mie, rh.mie));
    if (mie == rh.mie)
      res.cnt = cnt + rh.cnt;
    else if (mie < rh.mie)
      res.cnt = cnt;
    else
      res.cnt = rh.cnt;

    return res;
  }
};

struct SegmentTree {
  struct node {
    info val;
  };
  int n;
  VI a;
  vector<node> seg;

  SegmentTree() {}
  SegmentTree(int n_, VI &a_) : n(n_), a(a_), seg(vector<node>(4 * n + 10)) {}
  void update(int id) {
    int left = id * 2, right = left + 1;
    seg[id].val = seg[left].val + seg[right].val;
  }

  void build(int id, int l, int r) {
    if (l == r) {
      seg[id] = {a[l]};
      return;
    }
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void change(int id, int l, int r, int pos, int x) {
    if (l == r) {
      seg[id].val = {x};
      return;
    }
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (pos <= mid)
      change(left, l, mid, pos, x);
    else
      change(right, mid + 1, r, pos, x);
    update(id);
  }

  info query(int id, int l, int r, int ql, int qr) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (l >= ql && r <= qr) {
      return seg[id].val;
    }
    if (qr <= mid)
      return query(left, l, mid, ql, qr);
    else if (ql > mid)
      return query(right, mid + 1, r, ql, qr);
    else
      return query(left, l, mid, ql, mid) +
             query(right, mid + 1, r, mid + 1, qr);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  a = VI(n + 10);
  For1(i, 1, n) cin >> a[i];
  SegmentTree tree = SegmentTree(n, a);
  tree.build(1, 1, n);

  while (q--) {
    int op, x, d, l, r;
    cin >> op;
    if (op == 1) {
      cin >> x >> d;
      tree.change(1, 1, n, x, d);
    } else {
      cin >> l >> r;
      auto [mie, cnt] = tree.query(1, 1, n, l, r);
      cout << mie << ' ' << cnt << '\n';
    }
  }
}

int main(void) {
#ifdef _DEBUG
  // freopen("../input.txt", "r", stdin);
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
