// Date: Wed Aug 21 00:01:45 2024

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
mt19937_64 _m_gen64;

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

struct info {
  int mx, mi;
  info() {}
  info(int x) : mx(x), mi(x) {}
  info(int x, int y) : mx(x), mi(y) {}
};

info operator+(const info &l, const info &r) {
  return info(max(l.mx, r.mx), min(l.mi, r.mi));
}

struct SegmentTree {
  struct node {
    info val;
  };

  vector<node> seg;
  int n;
  vector<int> a;

  SegmentTree(int n_, vector<int> a_) : n(n_), a(a_) {
    seg = vector<node>(n * 4 + 10);
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

    int left = id * 2, right = left + 1, mid = (l + r) / 2;

    if (qr <= mid)
      return query(left, l, mid, ql, qr);
    if (ql >= mid + 1)
      return query(right, mid + 1, r, ql, qr);

    return query(left, l, mid, ql, mid) + query(right, mid + 1, r, mid + 1, qr);
  }

  // find the first index which >= d in the range [ql, qr], return -1 if not
  // found
  int binary_search(int id, int l, int r, int ql, int qr, int d) {
    if (l == ql && r == qr) {
      if (seg[id].val.mx < d)
        return -1;

      if (l == r)
        return l;

      int left = id * 2, right = left + 1, mid = (l + r) / 2;
      if (seg[left].val.mx >= d)
        return binary_search(left, l, mid, ql, mid, d);
      return binary_search(right, mid + 1, r, mid + 1, r, d);
    }

    int left = id * 2, right = left + 1, mid = (l + r) / 2;
    if (qr <= mid)
      return binary_search(left, l, mid, ql, qr, d);
    if (ql >= mid + 1)
      return binary_search(right, mid + 1, r, ql, qr, d);

    int pos = binary_search(left, l, mid, ql, mid, d);
    if (pos != -1)
      return pos;
    return binary_search(right, mid + 1, r, mid + 1, qr, d);
  }
};

void solve() {
  int n;
  cin >> n;

  set<int> s;
  map<int, int> m;
  map<int, int> m1;
  map<int, VI> poses;

  VI a(n + 10, INF);
  For1(i, 1, n) {
    cin >> a[i];
    s.insert(a[i]);

    ckmax(m[a[i]], i);
    poses[a[i]].pb(i);
  }

  for (auto &[x, v] : poses) {
    sort(all(v));
  }

  SegmentTree tr(n, a);

  set<int> s1;
  Rof1(i, 1, n) {
    s1.insert(a[i]);
    int len = SZ(s1);
    ckmax(m1[len], i);
  }

  int len = SZ(s);
  cout << len << '\n';
  tr.build(1, 1, n);

  stack<int> stk1, stk2;
  VI ans(n + 1);
  set<int> used;
  int pre = 1;

  For1(j, 1, len) {
    int rem = len - j;
    int pos = m1[rem];

    if (j & 1) {
      auto in = tr.query(1, 1, n, pre, pos - 1);
      int val = in.mx;
      ans[j] = val;
      auto &ve = poses[val];
      int po = *lower_bound(all(ve), val);
      pre = po + 1;
    } else {
      auto in = tr.query(1, 1, n, pre, pos - 1);
      int val = in.mi;
      ans[j] = val;
      auto &ve = poses[val];
      int po = *lower_bound(all(ve), val);
      pre = po + 1;
    }
  }

  cout << ans << '\n';
}

int main(void) {
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

  int T = 1;
  cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}
