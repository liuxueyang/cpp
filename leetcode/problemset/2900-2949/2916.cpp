// Date: Sat Jul  6 21:59:43 2024

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
  int k;
  tag() : k(0) {}
  tag(int _k) : k(_k) {}
  bool empty() { return k == 0; }
};

struct info {
  ll sum1, sum2;
  int l, r;
  info() : sum1(0), sum2(0), l(0), r(0) {}
  info(ll _s1, ll _s2, int _l, int _r)
      : sum1(_s1 % MOD), sum2(_s2 % MOD), l(_l), r(_r) {}
};

tag operator+(const tag &l, const tag &r) { return tag(l.k + r.k); }

info operator+(const info &i, const tag &t) {
  info ans;
  ll len = i.r - i.l + 1, k = t.k;
  ans.sum1 = (i.sum1 + (2 * k * i.sum2) % MOD + len * k * k % MOD) % MOD;
  ans.sum2 = (i.sum2 + len * k % MOD) % MOD;
  ans.l = i.l;
  ans.r = i.r;
  return ans;
}

info operator+(const info &l, const info &r) {
  return info(l.sum1 + r.sum1, l.sum2 + r.sum2, l.l, r.r);
}

struct SegmentTree {
  struct node {
    info val;
    tag t;
  };

  int n;
  vector<int> a;
  vector<node> seg;

  SegmentTree(int _n, vector<int> _a) : n(_n), a(_a) {
    a.insert(a.begin(), 0);
    seg = vector<node>(n * 4);
  }

  void set_tag(int id, tag &t) {
    seg[id].val = seg[id].val + t;
    seg[id].t = seg[id].t + t;
  }

  void push_down(int id) {
    int left = id * 2, right = left + 1;
    tag &t1 = seg[id].t;
    if (!t1.empty()) {
      set_tag(left, t1);
      set_tag(right, t1);
      t1 = tag();
    }
  }

  void update(int id) {
    int left = id * 2, right = left + 1;
    seg[id].val = seg[left].val + seg[right].val;
  }

  void build(int id, int l, int r) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (l == r) {
      seg[id].val = info(a[l] * a[l], a[l], l, l);
      return;
    }
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void modify(int id, int l, int r, int ql, int qr, tag t) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (l == ql && r == qr) {
      set_tag(id, t);
      return;
    }
    push_down(id);

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

  info query(int id, int l, int r, int ql, int qr) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (ql == l && qr == r) {
      return seg[id].val;
    }

    push_down(id);
    if (qr <= mid)
      return query(left, l, mid, ql, qr);
    else if (ql > mid)
      return query(right, mid + 1, r, ql, qr);
    else {
      return query(left, l, mid, ql, mid) +
             query(right, mid + 1, r, mid + 1, qr);
    }
  }
};

class Solution {
public:
  int sumCounts(vector<int> &b) {
    int n = SZ(b), ans{};
    VI a(n, 0);
    SegmentTree tr(n, a);
    tr.build(1, 1, n);
    map<int, int> pos;
    b.insert(b.begin(), 0);

    For1(i, 1, n) {
      int x = b[i];
      if (has(pos, x)) {
        int pre = pos[x];
        tr.modify(1, 1, n, pre + 1, i, tag(1));
      } else {
        tr.modify(1, 1, n, 1, i, tag(1));
      }

      info in = tr.query(1, 1, n, 1, i);
      ans = (ans + in.sum1) % MOD;
      pos[x] = i;
    }

    return ans;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  int res;
  VI p;

  p = {1, 2, 1};
  res = a.sumCounts(p);
  dbg(res);

  p = {2, 2};
  res = a.sumCounts(p);
  dbg(res);

  return 0;
}

#endif
