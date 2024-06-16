// Date: Sun Jun 16 11:48:53 2024

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
  int val, l, r;
  info() {}
  info(int x, int pos) : val(x), l(pos), r(pos) {}
};

info operator+(const info &l, const info &r) {
  return info(max(l.val, r.val), 0);
}

struct SegmentTree {
  struct node {
    info val;
  };

  vector<node> seg;
  int n;
  vector<int> a;

  info merge(const info &l, const info &r) {
    int l1 = l.l, r1 = l.r, l2 = r.l, r2 = r.r;
    int sz1 = r1 - l1 + 1, sz2 = r2 - l2 + 1;
    info res;
    res.val = l.val + r.val;
    res.l = l1;
    res.r = r2;

    if (sz1 > 1) {
      if (a[r1] > a[r1 - 1] && a[r1] > a[l2])
        res.val++;
    }

    if (sz2 > 1) {
      if (a[l2] > a[l2 + 1] && a[l2] > a[r1])
        res.val++;
    }
    return res;
  }

  SegmentTree(int n_, vector<int> a_) : n(n_), a(a_) {
    seg = vector<node>(n * 4 + 10);
  }

  void update(int id) {
    int left = id * 2, right = left + 1;
    seg[id].val = merge(seg[left].val, seg[right].val);
  }

  void build(int id, int l, int r) {
    if (l == r) {
      seg[id].val = info(0, l);
      return;
    }

    int left = id * 2, right = left + 1, mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void change(int id, int l, int r, int pos, int x) {
    if (l == r) {
      seg[id].val = info(0, pos);
      a[l] = x;
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

    return merge(query(left, l, mid, ql, mid),
                 query(right, mid + 1, r, mid + 1, qr));
  }

  // find the first index which >= d in the range [ql, qr], return -1 if not
  // found
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
  vector<int> countOfPeaks(vector<int> &a, vector<vector<int>> &que) {
    VI ans;
    int n = SZ(a);
    a.insert(a.begin(), 0);
    SegmentTree tr(n, a);

    tr.build(1, 1, n);

    for (auto v : que) {
      if (v[0] == 1) {
        auto tmp = tr.query(1, 1, n, v[1] + 1, v[2] + 1);
        ans.pb(tmp.val);
      } else {
        tr.change(1, 1, n, v[1] + 1, v[2]);
      }
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

  return 0;
}

#endif
