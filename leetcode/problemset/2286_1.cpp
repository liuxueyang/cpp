// Date: Tue Jul  2 20:51:14 2024

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

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998'244'353;
const ll INFL = 0x3f3f3f3f'3f3f3f3f;
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

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

#ifdef _DEBUG
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
#define dbg(x...)                                                              \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";    \
  _print(x);                                                                   \
  cerr << "\e[39m" << endl;
#else
#define debug1
#define debug2
#define debug3
#define dbg(x...)
#endif

// For LeetCode
#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *

#ifdef _DEBUG
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#endif
// End of LeetCode

struct tag {
  int val;
  tag() : val(INF) {}
  tag(ll x) : val(x) {}
};

struct info {
  int mx;
  ll sum;
  info() {}
  info(int _mx, ll _sum) : mx(_mx), sum(_sum) {}
};

tag operator+(const tag &l, const tag &r) { return tag(min(l.val, r.val)); }

info operator+(const info &_, const tag &t) { return info(t.val, t.val); }

info operator+(const info &l, const info &r) {
  return info(max(l.mx, r.mx), l.sum + r.sum);
}

struct SegmentTree {
  struct node {
    info val;
    tag t;
  };

  int n;
  vector<node> seg;
  vector<int> a;

  SegmentTree() {}

  SegmentTree(int n_, vector<int> a_) : n(n_), a(a_) {
    seg = vector<node>(n * 4 + 10);
  }

  void set_tag(int id, tag t) {
    seg[id].val = seg[id].val + t;
    seg[id].t = t;
  }

  void push_down(int id) {
    tag t = seg[id].t;
    if (t.val != INF) {
      seg[id].t = tag(INF);

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

  void change(int id, int l, int r, int pos, int x) {
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

  int find_gather(int id, int l, int r, int ql, int qr, int k) {
    int left = id * 2, right = left + 1, mid = (l + r) / 2;

    if (l == ql && r == qr) {
      if (seg[id].val.mx < k)
        return -1;

      if (l == r)
        return l;

      if (seg[left].val.mx >= k)
        return find_gather(left, l, mid, ql, mid, k);
      return find_gather(right, mid + 1, r, mid + 1, qr, k);
    }

    push_down(id);

    if (qr <= mid)
      return find_gather(left, l, mid, ql, qr, k);
    if (ql > mid)
      return find_gather(right, mid + 1, r, ql, qr, k);

    int pos = find_gather(left, l, mid, ql, mid, k);
    if (pos != -1)
      return pos;
    return find_gather(right, mid + 1, r, mid + 1, qr, k);
  }

  int find_scatter(int id, int l, int r, int ql, int qr, int k) {
    int left = id * 2, right = left + 1, mid = (l + r) / 2;

    if (l == ql && r == qr) {
      if (seg[id].val.sum < k)
        return -1;

      if (l == r)
        return l;

      if (seg[left].val.sum >= k)
        return find_scatter(left, l, mid, ql, mid, k);
      return find_scatter(right, mid + 1, r, mid + 1, qr,
                          k - seg[left].val.sum);
    }

    push_down(id);

    if (qr <= mid)
      return find_scatter(left, l, mid, ql, qr, k);
    if (ql > mid)
      return find_scatter(right, mid + 1, r, ql, qr, k);

    int pos = find_scatter(left, l, mid, ql, mid, k);
    if (pos != -1)
      return pos;
    // BUG: k - seg[left].val.sum (k is presum, seg[left].val.sum is the left
    // part)
    return find_scatter(right, mid + 1, r, mid + 1, qr, k - seg[left].val.sum);
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

class BookMyShow {
public:
  int n, m;
  SegmentTree tr;
  VI a;

  BookMyShow(int _n, int _m) : n(_n), m(_m) {
    a = VI(n + 1, m);
    tr = SegmentTree(n, a);
    tr.build(1, 1, n);
  }

  vector<int> gather(int k, int maxRow) {
    maxRow++;
    int pos = tr.find_gather(1, 1, n, 1, maxRow, k);
    if (pos == -1)
      return VI();

    VI ans(2, pos - 1);

    auto cnti = tr.query(1, 1, n, pos, pos);
    int cnt = cnti.sum;
    ans[1] = m - cnt;

    tr.change(1, 1, n, pos, cnt - k);

    return ans;
  }

  bool scatter(int k, int maxRow) {
    maxRow++;
    int pos = tr.find_scatter(1, 1, n, 1, maxRow, k);
    if (pos == -1)
      return false;

    ll psum{};

    if (pos - 1 >= 1) {
      auto cnti = tr.query(1, 1, n, 1, pos - 1);
      psum = cnti.sum;

      tr.modify(1, 1, n, 1, pos - 1, tag(0));
    }

    auto cnti2 = tr.query(1, 1, n, pos, pos);
    tr.change(1, 1, n, pos, cnti2.sum - (k - psum));

    return true;
  }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  BookMyShow b(2, 5);
  auto res = b.gather(4, 0);
  dbg(res);

  return 0;
}

#endif
