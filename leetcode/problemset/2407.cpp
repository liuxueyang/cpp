// Date: Fri Jun 14 20:53:44 2024

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
  int val;
  info() {}
  info(int x) : val(x) {}
};

info operator+(const info &l, const info &r) { return info(max(l.val, r.val)); }

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

  int binary_search(int id, int l, int r, int ql, int qr, int d) {
    if (l == ql && r == qr) {
      if (seg[id].val.val < d)
        return -1;

      if (l == r)
        return l;

      int left = id * 2, right = left + 1, mid = (l + r) / 2;
      if (seg[left].val.val >= d)
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

class Solution {
public:
  int lengthOfLIS(vector<int> &a, int k) {
    int ans{}, m = 1e5;
    VI b(m + 1, 0);

    SegmentTree tr(m, b);
    tr.build(1, 1, m);

    for (auto x : a) {
      int left = max(1, x - k), right = max(1, x - 1);
      int tmp = 1;

      if (right != x) {
        auto res = tr.query(1, 1, m, left, right);
        tmp = res.val + 1;
      }

      ckmax(ans, tmp);

      tr.change(1, 1, m, x, tmp);
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
  VI p;
  int k, res;

  p = VI{4, 2, 1, 4, 3, 4, 5, 8, 15};
  k = 3;
  res = a.lengthOfLIS(p, k);
  dbg(res);

  p = VI{7, 4, 5, 1, 8, 12, 4, 7};
  k = 5;
  res = a.lengthOfLIS(p, k);
  dbg(res);

  p = VI{1, 5};
  k = 1;
  res = a.lengthOfLIS(p, k);
  dbg(res);

  p = VI{1, 1, 5};
  k = 3;
  res = a.lengthOfLIS(p, k);
  dbg(res);

  return 0;
}

#endif
