// Date: Fri Jul  5 20:38:34 2024

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
  bool b;
  tag() : b(false) {}
  tag(bool _b) : b(_b) {}
  bool empty() { return !b; }
};

struct info {
  int l, r;
  int x0, x1;
  info() {}
  info(int _l, int _r, int _x0, int _x1) : l(_l), r(_r), x0(_x0), x1(_x1) {}
};

info operator+(const info &l, const info &r) {
  info ans;
  ans.l = l.l;
  ans.r = r.r;
  ans.x0 = l.x0 + r.x0;
  ans.x1 = l.x1 + r.x1;

  return ans;
}

info operator+(const info &l, const tag &t) {
  info ans = l;
  if (t.b) {
    ans.x0 = 0, ans.x1 = ans.r - ans.l + 1;
  }
  return ans;
}

tag operator+(const tag &l, const tag &r) { return tag(l.b || r.b); }

struct SegmentTree {
  struct node {
    info val;
    tag t;
  };

  int n;
  VI a;
  vector<node> seg;

  SegmentTree(int _n, VI &_a) {
    n = _n;
    a = _a;
    a.insert(a.begin(), 0);
    seg = vector<node>(n * 4);
  }

  void update(int id) {
    int left = id * 2, right = left + 1;

    seg[id].val = seg[left].val + seg[right].val;
  }

  void set_tag(int id, tag t) {
    seg[id].val = seg[id].val + t;
    seg[id].t = seg[id].t + t;
  }

  void push_down(int id) {
    int left = id * 2, right = left + 1;
    tag t1 = seg[id].t;
    if (t1.b) {
      set_tag(left, t1);
      set_tag(right, t1);
      seg[id].t = tag();
    }
  }

  void build(int id, int l, int r) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (l == r) {
      seg[id].val = info(l, r, 1, 0);
      return;
    }
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void modify(int id, int l, int r, int ql, int qr, tag t) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (ql == l && qr == r) {
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

  int binary_search(int id, int l, int r, int ql, int qr, int &cnt) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    int pos = -1;

    if (l == ql && r == qr) {
      if (l == r || cnt == seg[id].val.x0) {
        cnt -= seg[id].val.x0;
        return l;
      }
      push_down(id);

      if (cnt <= seg[right].val.x0) {
        return binary_search(right, mid + 1, r, mid + 1, qr, cnt);
      }
      cnt -= seg[right].val.x0;
      pos = binary_search(left, l, mid, ql, mid, cnt);
      return pos;
    }

    push_down(id);

    if (qr <= mid)
      return binary_search(left, l, mid, ql, qr, cnt);
    else if (ql > mid)
      return binary_search(right, mid + 1, r, ql, qr, cnt);
    else {
      pos = binary_search(right, mid + 1, r, mid + 1, qr, cnt);
      if (cnt)
        pos = binary_search(left, l, mid, ql, mid, cnt);
      return pos;
    }
  }

  void binary_modify(int id, int l, int r, int ql, int qr, int &cnt) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (l == ql && r == qr) {
      if (l != r)
        push_down(id);

      if (cnt >= seg[id].val.x0) {
        cnt -= seg[id].val.x0;
        set_tag(id, tag(true));

        return;
      }

      binary_modify(right, mid + 1, r, mid + 1, qr, cnt);
      if (cnt)
        binary_modify(left, l, mid, ql, mid, cnt);

      if (l != r)
        update(id);
      return;
    }

    push_down(id);

    if (qr <= mid)
      binary_modify(left, l, mid, ql, qr, cnt);
    else if (ql > mid)
      binary_modify(right, mid + 1, r, ql, qr, cnt);
    else {
      binary_modify(right, mid + 1, r, mid + 1, qr, cnt);
      if (cnt) {
        binary_modify(left, l, mid, ql, mid, cnt);
      }
    }
    update(id);

    return;
  }

  info query(int id, int l, int r, int ql, int qr) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (ql == l && qr == r) {
      return seg[id].val;
    }
    push_down(id);

    info ans;
    if (qr <= mid)
      ans = query(left, l, mid, ql, qr);
    else if (ql > mid)
      ans = query(right, mid + 1, r, ql, qr);
    else {
      ans =
          query(left, l, mid, ql, mid) + query(right, mid + 1, r, mid + 1, qr);
    }
    update(id);

    return ans;
  }
};

class Solution {
public:
  int findMinimumTime(vector<vector<int>> &ta) {
    int n = 0;
    for (auto &v : ta) {
      ckmax(n, max(v[0], v[1]));
    }

    VI a(n, 0);
    SegmentTree tr(n, a);
    tr.build(1, 1, n);

    sort(all(ta), [](const VI &x, const VI &y) {
      if (x[1] != y[1])
        return x[1] < y[1];
      return x[0] < y[0];
    });

    int ans{};
    for (auto &v : ta) {
      info i1 = tr.query(1, 1, n, v[0], v[1]);

      int rem = v[2] - i1.x1;
      if (rem <= 0)
        continue;
      ans += rem;

      tr.binary_modify(1, 1, n, v[0], v[1], rem);
      // int pos = tr.binary_search(1, 1, n, v[0], v[1], rem);

      // tr.modify(1, 1, n, pos, v[1], tag(true));
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
  vector<VI> ta;
  int res;

  ta = {{2, 3, 1}, {4, 5, 1}, {1, 5, 2}};
  res = a.findMinimumTime(ta);
  dbg(res);

  ta = {{1, 3, 2}, {2, 5, 3}, {5, 6, 2}};
  res = a.findMinimumTime(ta);
  dbg(res);

  ta = {{2, 13, 2}, {6, 18, 5}, {2, 13, 3}};
  res = a.findMinimumTime(ta);
  dbg(res);

  return 0;
}

#endif
