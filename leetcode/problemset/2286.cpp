// Date: Mon Jul  1 21:54:13 2024

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

struct info {
  int mx;
  ll sum;

  info() : mx(0), sum(0) {}
  info(int _mx, ll _sum) : mx(_mx), sum(_sum) {}
};

info operator+(const info &l, const info &r) {
  return info(max(l.mx, r.mx), l.sum + r.sum);
}

int m;

struct SegmentTree {
  struct node {
    info val;
  };

  vector<node> seg;
  int n;
  VI a;

  SegmentTree() {}
  SegmentTree(int n_, VI _a) : n(n_), a(_a) { seg = vector<node>(n * 4 + 10); }

  void update(int id) {
    int left = id << 1, right = left + 1;
    seg[id].val = seg[left].val + seg[right].val;
  }

  void build(int id, int l, int r) {
    if (l == r) {
      seg[id].val = info(a[l], a[l]);
      return;
    }
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void change(int id, int l, int r, int pos, int x) {
    if (l == r) {
      seg[id].val = info(x, x);
      return;
    }
    int mid = (l + r) / 2, left = id << 1, right = left + 1;
    if (pos <= mid)
      change(left, l, mid, pos, x);
    else
      change(right, mid + 1, r, pos, x);

    update(id);
  }

  info query(int id, int l, int r, int ql, int qr) {
    int left = id << 1, right = left + 1, mid = (l + r) / 2;

    if (l == r) {
      return seg[id].val;
    }

    if (qr <= mid)
      return query(left, l, mid, ql, qr);
    if (ql > mid)
      return query(right, mid + 1, r, ql, qr);

    return query(left, l, mid, ql, mid) + query(right, mid + 1, r, mid + 1, qr);
  }

  void fill_zero(int id, int l, int r, int pos) {
    int left = id << 1, right = left + 1, mid = (l + r) / 2;

    if (l == r) {
      seg[id].val = info();
      return;
    }

    if (pos <= mid && seg[left].val.mx > 0)
      fill_zero(left, l, mid, pos);

    if (pos > mid) {
      if (seg[left].val.mx > 0)
        fill_zero(left, l, mid, mid);
      if (seg[right].val.mx > 0)
        fill_zero(right, mid + 1, r, pos);
    }

    update(id);
  }

  int find_scatter(int id, int l, int r, int ql, int qr, int k) {
    int left = id << 1, right = left + 1, mid = (l + r) / 2;
    dbg(l, r, ql, qr);

    if (ql == l && qr == r) {
      dbg(id, seg[id].val.sum, l, r);
      if (seg[id].val.sum < k)
        return -1;

      if (l == r)
        return l;

      dbg(l, r, left, seg[left].val.sum, k);

      if (seg[left].val.sum >= k)
        return find_scatter(left, l, mid, ql, mid, k);
      return find_scatter(right, mid + 1, r, mid + 1, qr,
                          k - seg[left].val.sum);
    }

    if (qr <= mid)
      return find_scatter(left, l, mid, ql, qr, k);
    if (ql > mid)
      return find_scatter(right, mid + 1, r, ql, qr, k);

    int pos = find_scatter(left, l, mid, ql, mid, k);
    if (pos != -1)
      return pos;
    return find_scatter(right, mid + 1, r, mid + 1, qr, k);
  }

  int find_gather(int id, int l, int r, int ql, int qr, int k) {
    int left = id << 1, right = left + 1, mid = (l + r) / 2;

    if (ql == l && qr == r) {
      if (seg[id].val.mx < k)
        return -1;

      if (l == r)
        return l;

      if (seg[left].val.mx >= k)
        return find_gather(left, l, mid, ql, mid, k);
      return find_gather(right, mid + 1, r, mid + 1, qr, k);
    }

    if (qr <= mid)
      return find_gather(left, l, mid, ql, qr, k);
    if (ql > mid)
      return find_gather(right, mid + 1, r, ql, qr, k);

    int pos = find_gather(left, l, mid, ql, mid, k);
    if (pos != -1)
      return pos;
    return find_gather(right, mid + 1, r, mid + 1, qr, k);
  }

  void print() {
    For1(i, 1, n) {
      auto x = query(1, 1, n, i, i);
      dbg(i, x.sum);
    }
  }
};

class BookMyShow {
public:
  int n;
  SegmentTree tr;
  VI a;
  int last;

  BookMyShow(int _n, int _m) : n(_n) {
    m = _m;
    a = VI(n + 1, m);
    tr = SegmentTree(n, a);
    tr.build(1, 1, n);
    last = 0;
  }

  vector<int> gather(int k, int maxRow) {
    maxRow++;
    int pos = tr.find_gather(1, 1, n, 1, maxRow, k);
    if (pos == -1)
      return VI();

    VI ans(2);
    ans[0] = pos - 1;

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

    For(i, last + 1, pos) { tr.change(1, 1, n, i, 0); }
    ckmax(last, pos - 1);

    ll psum = 0;
    if (pos - 1 >= 1) {
      auto psum_i = tr.query(1, 1, n, 1, pos - 1);
      psum = psum_i.sum;
    }

    int rem = k - psum;
    auto cnti = tr.query(1, 1, n, pos, pos);
    tr.change(1, 1, n, pos, cnti.sum - rem);

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

  BookMyShow b(4, 5);
  auto r1 = b.scatter(6, 2);
  b.tr.print();
  dbg(r1);

  return 0;
}

#endif
