// Date: Sat Jul  6 16:55:35 2024

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
  ll a, b;
  tag() : a(1), b(0) {}
  tag(ll _a, ll _b) : a(_a), b(_b) {}
  bool empty() { return a == 1 && b == 0; }
};

struct info {
  ll sum;
  info() : sum(0) {}
  info(ll _sum) : sum(_sum % MOD) {}
};

tag operator+(const tag &l, const tag &r) {
  tag ans;
  ans.a = (l.a * r.a) % MOD;
  ans.b = (l.b * r.a + r.b) % MOD;
  return ans;
}

info operator+(const info &l, const tag &t) {
  info ans;
  ans.sum = ((l.sum * t.a % MOD) + t.b) % MOD;
  return ans;
}

info operator+(const info &l, const info &r) { return info(l.sum + r.sum); }

struct SegmentTree {
  struct node {
    info val;
    tag t;
  };
  int n;
  vector<int> a;
  vector<node> seg;

  SegmentTree() {}
  SegmentTree(int _n, vector<int> _a) : n(_n), a(_a) {
    a.insert(a.begin(), 0);
    seg = vector<node>(n * 4);
  }

  void set_tag(int id, tag &t) {
    seg[id].val = seg[id].val + t;
    seg[id].t = seg[id].t + t;
  }

  void push_down(int id) {
    tag &t1 = seg[id].t;
    int left = id * 2, right = left + 1;

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
      seg[id].val = info(a[l]);
      seg[id].t = tag();
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
    if (ql == l && qr == r)
      return seg[id].val;
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

class Fancy {
public:
  int n, m;
  SegmentTree tr;

  Fancy() : n(0), m(1e5) {
    vector<int> a(m, 0);
    tr = SegmentTree(m, a);
    tr.build(1, 1, m);
  }

  void append(int val) {
    ++n;
    tr.modify(1, 1, m, n, n, tag(1, val));
  }

  void addAll(int inc) {
    if (n >= 1)
      tr.modify(1, 1, m, 1, n, tag(1, inc));
  }

  void multAll(int val) {
    if (n >= 1)
      tr.modify(1, 1, m, 1, n, tag(val, 0));
  }

  int getIndex(int idx) {
    idx++;
    if (idx > n)
      return -1;

    info i = tr.query(1, 1, m, idx, idx);
    return i.sum % MOD;
  }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // Solution a;

  Fancy fancy = Fancy();
  fancy.append(2);        // 奇妙序列：[2]
  fancy.addAll(3);        // 奇妙序列：[2+3] -> [5]
  fancy.append(7);        // 奇妙序列：[5, 7]
  fancy.multAll(2);       // 奇妙序列：[5*2, 7*2] -> [10, 14]
  dbg(fancy.getIndex(0)); // 返回 10
  fancy.addAll(3);        // 奇妙序列：[10+3, 14+3] -> [13, 17]
  fancy.append(10);       // 奇妙序列：[13, 17, 10]
  fancy.multAll(2);       // 奇妙序列：[13*2, 17*2, 10*2] -> [26, 34, 20]
  fancy.getIndex(0);      // 返回 26
  fancy.getIndex(1);      // 返回 34
  fancy.getIndex(2);      // 返回 20
  return 0;
}

#endif
