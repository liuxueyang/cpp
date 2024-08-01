// Date: Wed Jul 31 12:07:38 2024

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

// int128 input and output
#ifdef _DEBUG
using lll = __int128;

istream &operator>>(istream &is, lll &v) {
  string s;
  is >> s;
  v = 0;
  for (auto &it : s)
    if (isdigit(it))
      v = v * 10 + it - '0';
  if (s[0] == '-')
    v *= -1;
  return is;
}

ostream &operator<<(ostream &os, const lll &v) {
  if (v == 0)
    return (os << "0");
  lll num = v;
  if (v < 0)
    os << '-', num = -num;
  string s;
  for (; num > 0; num /= 10)
    s.pb((char)(num % 10) + '0');
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

const int N = 200100;
int n, q, a[N];

struct tag {
  ll val;
  tag() : val(0) {}
  tag(ll x) : val(x) {}
};

struct info {
  ll val;
  info() {}
  info(ll x) : val(x) {}
};

tag operator+(const tag &l, const tag &r) { return tag(l.val + r.val); }

info operator+(const info &l, const tag &t) { return info(l.val + t.val); }

info operator+(const info &l, const info &r) { return info(max(l.val, r.val)); }

struct SegmentTree {
  struct node {
    info val;
    tag t;
  };

  int n;
  vector<node> seg;
  vector<int> a;

  SegmentTree(int n_, vector<int> a_) : n(n_), a(a_) {
    seg = vector<node>(n * 4 + 10);
  }

  void set_tag(int id, tag t) {
    seg[id].val = seg[id].val + t;
    seg[id].t = seg[id].t + t;
  }

  void push_down(int id) {
    tag t = seg[id].t;
    if (t.val != 0) {
      seg[id].t = tag(0);

      int left = id * 2, right = left + 1;
      set_tag(left, t);
      set_tag(right, t);
    }
  }

  void update(int id) {
    int left = id * 2, right = left + 1;
    seg[id].val = seg[left].val + seg[right].val;
  }

  void build(int id, int l, int r) {
    if (l == r) {
      seg[id].val = info(a[l]);
      return;
    }

    int left = id * 2, right = left + 1, mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void change(int id, int l, int r, int pos, int x) {
    if (l == r) {
      seg[id].val = info(x);
      return;
    }

    int left = id * 2, right = left + 1, mid = (l + r) / 2;
    if (pos <= mid)
      change(left, l, mid, pos, x);
    else
      change(right, mid + 1, r, pos, x);

    update(id);
  }

  info query(int id, int l, int r, int ql, int qr) {
    if (ql == l && qr == r) {
      return seg[id].val;
    }

    push_down(id);

    int left = id * 2, right = left + 1, mid = (l + r) / 2;

    if (qr <= mid)
      return query(left, l, mid, ql, qr);
    if (ql >= mid + 1)
      return query(right, mid + 1, r, ql, qr);

    return query(left, l, mid, ql, mid) + query(right, mid + 1, r, mid + 1, qr);
  }

  void modify(int id, int l, int r, int ql, int qr, tag t) {
    if (ql == l && qr == r) {
      set_tag(id, t);
      return;
    }

    push_down(id);

    int left = id * 2, right = left + 1, mid = (l + r) / 2;
    if (qr <= mid)
      modify(left, l, mid, ql, qr, t);
    else if (ql >= mid + 1)
      modify(right, mid + 1, r, ql, qr, t);
    else {
      modify(left, l, mid, ql, mid, t);
      modify(right, mid + 1, r, mid + 1, qr, t);
    }

    update(id);
  }
};

void solve() {
  cin >> n >> q;
  Inputr(a + 1, a + 1 + n);

  vector<PII> que(q);
  map<int, VI> mque;
  map<PII, bool> res;
  int mxi = -1, mxk = -1;

  For(i, 0, q) {
    int i1, x;
    cin >> i1 >> x;
    ckmax(mxi, i1);
    ckmax(mxk, x);
    que[i] = {i1, x};
    mque[i1].pb(x);
  }

  mxk += 10;

  VI ak(mxk + 1, 0);
  SegmentTree tr(mxk, ak);
  tr.build(1, 1, mxk);

  For1(i, 1, mxi) {
    int lk = 1, rk = mxk, midk;
    while (lk < rk) {
      midk = (lk + rk) / 2;
      auto ti = tr.query(1, 1, mxk, midk, midk);
      int tmp = ti.val / midk + 1;
      if (tmp <= a[i]) {
        rk = midk;
      } else {
        lk = midk + 1;
      }
    }

    tr.modify(1, 1, mxk, rk, mxk, tag(1));

    for (auto k1 : mque[i]) {
      if (k1 >= rk) {
        res[{i, k1}] = true;
      } else {
        res[{i, k1}] = false;
      }
    }
  }

  for (auto &p : que) {
    cout << (res[p] ? "YES" : "NO") << '\n';
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("e.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 1;
  // cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}
