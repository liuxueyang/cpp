// Date: Wed Jul  3 19:36:22 2024

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
  int pre, post, sum, left, right;
  char prec, postc, sumc;
  info()
      : pre(0), post(0), sum(0), left(0), right(0), prec(' '), postc(' '),
        sumc(' ') {}
  info(char c, int pos)
      : pre(1), post(1), sum(1), left(pos), right(pos), prec(c), postc(c),
        sumc(c) {}
};

info operator+(const info &l, const info &r) {
  info ans;
  ans.left = l.left;
  ans.right = r.right;

  int len_l = l.right - l.left + 1, len_r = r.right - r.left + 1;

  if (l.sum > r.sum) {
    ans.sum = l.sum;
    ans.sumc = l.sumc;
  } else {
    ans.sum = r.sum;
    ans.sumc = r.sumc;
  }

  if (l.postc == r.prec && l.post && r.pre) {
    if (ckmax(ans.sum, l.post + r.pre)) {
      ans.sumc = l.postc;
    }
  }

  ans.pre = l.pre;
  ans.prec = l.prec;
  if (l.pre == len_l && l.prec == r.prec) {
    ans.pre = l.sum + r.pre;
  }

  ans.post = r.post;
  ans.postc = r.postc;
  if (r.post == len_r && r.postc == l.postc) {
    ans.post = r.sum + l.post;
  }

  if (ckmax(ans.sum, ans.pre))
    ans.sumc = ans.prec;
  if (ckmax(ans.sum, ans.post))
    ans.sumc = ans.postc;

  return ans;
}

struct SegmentTree {
  struct node {
    info val;
  };

  int n;
  string a;
  vector<node> seg;

  SegmentTree() {}
  SegmentTree(int _n, string _a) : n(_n) {
    a = " " + _a;
    seg = vector<node>(n * 4);
  }

  void update(int id) {
    int left = id * 2, right = left + 1;
    seg[id].val = seg[left].val + seg[right].val;
  }

  void build(int id, int l, int r) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (l == r) {
      seg[id].val = info(a[l], l);
      return;
    }
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void change(int id, int l, int r, int pos, char x) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (l == r) {
      seg[id].val = info(x, l);
      return;
    }

    if (pos <= mid)
      change(left, l, mid, pos, x);
    else
      change(right, mid + 1, r, pos, x);

    update(id);
  }

  info query(int id, int l, int r, int ql, int qr) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (ql == l && qr == r) {
      return seg[id].val;
    }

    if (qr <= mid)
      return query(left, l, mid, ql, qr);
    if (ql > mid)
      return query(right, mid + 1, r, ql, qr);
    return query(left, l, mid, ql, mid) + query(right, mid + 1, r, mid + 1, qr);
  }
};

class Solution {
public:
  vector<int> longestRepeating(string s, string b, vector<int> &que) {
    int n = SZ(s), m = SZ(que);
    VI ans;
    SegmentTree tr(n, s);
    tr.build(1, 1, n);

    For(i, 0, m) {
      int pos = que[i] + 1;
      tr.change(1, 1, n, pos, b[i]);
      info res = tr.query(1, 1, n, 1, n);
      ans.pb(res.sum);
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
  string s, b;
  VI q, res;

  s = "babacc", b = "bcb";
  q = {1, 3, 3};
  res = a.longestRepeating(s, b, q);
  dbg(res);

  s = "abyzz", b = "aa";
  q = {2, 1};
  res = a.longestRepeating(s, b, q);
  dbg(res);

  return 0;
}

#endif
