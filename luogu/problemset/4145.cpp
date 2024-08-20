// Date: Mon Aug 19 22:48:01 2024

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

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

const int N = 100100;
int n;
vector<ll> a;

struct tag {
  int val;
  tag() : val(0) {}
  tag(int x) : val(x) {}
};

struct info {
  ll sum;
  ll mx;
  info() {}
  info(ll x, ll _mx) : sum(x), mx(_mx) {}
};

tag operator+(const tag &l, const tag &r) { return tag(l.val + r.val); }

info operator+(const info &l, const tag &t) {
  info ans = l;
  if (ans.mx == 1) {
    return ans;
  } else if (ans.mx == ans.sum) {
    int cnt = t.val;
    ll y = ans.sum;
    while (y > 1 && cnt--) {
      y = sqrtl(y);
    }

    ans = info(y, y);
  }
  return ans;
}

info operator+(const info &l, const info &r) {
  return info(l.sum + r.sum, max(l.mx, r.mx));
}

struct SegmentTree {
  struct node {
    info val;
    tag t;
  };

  int n;
  vector<node> seg;
  vector<ll> a;

  SegmentTree(int n_, vector<ll> a_) : n(n_), a(a_) {
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
      seg[id].val = info(a[l], a[l]);
      return;
    }

    int left = id * 2, right = left + 1, mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void change(int id, int l, int r, int pos, ll x) {
    if (l == r) {
      seg[id].val = info(x, x);
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
    int left = id * 2, right = left + 1, mid = (l + r) / 2;

    if (ql == l && qr == r) {
      if (seg[id].t.val == 0 || l == r) {
        // dbg(ql, qr, seg[id].val.sum);
        return seg[id].val;
      }
    }

    push_down(id);
    info res;

    if (qr <= mid)
      res = query(left, l, mid, ql, qr);
    else if (ql >= mid + 1)
      res = query(right, mid + 1, r, ql, qr);
    else
      res =
          query(left, l, mid, ql, mid) + query(right, mid + 1, r, mid + 1, qr);

    update(id);

    return res;
  }

  void modify(int id, int l, int r, int ql, int qr, tag t) {
    // dbg(l, r, ql, qr);

    if (ql == l && qr == r) {
      if (seg[id].val.mx == 1)
        return;

      if (l == r) {
        set_tag(id, t);
        return;
      }
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
  cin >> n;
  vector<ll> a(n + 1);
  For1(i, 1, n) cin >> a[i];

  SegmentTree tr(n, a);
  tr.build(1, 1, n);

  int q;
  cin >> q;
  while (q--) {
    int op, l, r;
    cin >> op >> l >> r;
    if (l > r)
      swap(l, r);

    if (op == 0) {
      tr.modify(1, 1, n, l, r, tag(true));
    } else if (op == 1) {
      info ans = tr.query(1, 1, n, l, r);
      cout << ans.sum << '\n';
    }
  }

  // For1(i, 1, n) {
  //   auto ans = tr.query(1, 1, n, i, i);
  //   dbg(i, ans.sum);
  // }
}

int main(void) {
#ifdef _DEBUG
  freopen("4145.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

  int T = 1;

  while (T--) {
    solve();
  }

  return 0;
}
