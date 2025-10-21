// Date: Sat Jul  6 23:32:43 2024

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

const int N = 50100;

int n, idx, h[N];
int e[N], ne[N], sz[N], pos, a[N];

void Init() {
  memset(h, -1, sizeof h);
  memset(sz, 0, sizeof sz);
  idx = 0;
  pos = 0;
}

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

int dfs(int i) {
  a[++pos] = i;
  sz[i] = 1;

  for (int j = h[i]; j != -1; j = ne[j]) {
    int k = e[j];
    sz[i] += dfs(k);
  }

  return sz[i];
}

struct info {
  int sum, len;
  info() : sum(0), len(0) {}
  info(int _s, int _l) : sum(_s % MOD), len(_l) {}
};

struct tag {
  int d;
  tag() : d(0) {}
  tag(int _d) : d(_d) {}
};

tag operator+(const tag &l, const tag &r) { return tag(l.d + r.d); }

info operator+(const info &i, const tag &t) {
  return info(i.sum + ll(t.d) * i.len % MOD, i.len);
}

info operator+(const info &l, const info &r) {
  return info(l.sum + r.sum, l.len + r.len);
}

struct SegmentTree {
  struct node {
    info val;
    tag t;
  };

  int n;
  VI a;
  vector<node> seg;

  SegmentTree(int _n, VI &_a) : n(_n), a(_a) {
    a.insert(a.begin(), 0);
    seg = vector<node>(n * 4);
  }

  void set_tag(int id, tag t) {
    seg[id].val = seg[id].val + t;
    seg[id].t = seg[id].t + t;
  }

  void push_down(int id) {
    int left = id * 2, right = left + 1;
    tag &t1 = seg[id].t;

    if (t1.d) {
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
    int left = id * 2, right = left + 1, mid = (l + r) / 2;
    if (l == r) {
      seg[id].val = info(a[l], 1);
      return;
    }
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void change(int id, int l, int r, int pos, int d) {
    int left = id * 2, right = left + 1, mid = (l + r) / 2;
    if (l == r) {
      seg[id].val.sum += d;
      return;
    }
    push_down(id);
    if (pos <= mid)
      change(left, l, mid, pos, d);
    else
      change(right, mid + 1, r, pos, d);
    update(id);
  }

  void modify(int id, int l, int r, int ql, int qr, tag t) {
    int left = id * 2, right = left + 1, mid = (l + r) / 2;
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

  info query(int id, int l, int r, int ql, int qr) {
    int left = id * 2, right = left + 1, mid = (l + r) / 2;
    if (l == ql && r == qr) {
      return seg[id].val;
    }
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

class Solution {
public:
  vector<int> bonus(int _n, vector<vector<int>> &g, vector<vector<int>> &que) {
    Init();
    n = _n;
    for (auto &v : g) {
      int x = v[0], y = v[1];
      add(x, y);
    }
    dfs(1);

    VI b(n, 0);

    SegmentTree tr(n, b);
    tr.build(1, 1, n);

    map<int, int> m;
    VI ans;

    For1(i, 1, n) { m[a[i]] = i; }

    for (auto &v : que) {
      if (v[0] == 1) {
        tr.change(1, 1, n, m[v[1]], v[2]);
      } else if (v[0] == 2) {
        int s1 = m[v[1]], s2 = s1 + sz[v[1]] - 1;
        tr.modify(1, 1, n, s1, s2, v[2]);
      } else {
        int s1 = m[v[1]], s2 = s1 + sz[v[1]] - 1;
        info i1 = tr.query(1, 1, n, s1, s2);
        ans.pb(i1.sum);
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
  vector<VI> p1, p2;
  VI res;

  p1 = {{1, 2}, {1, 6}, {2, 3}, {2, 5}, {1, 4}};
  p2 = {{1, 1, 500}, {2, 2, 50}, {3, 1}, {2, 6, 15}, {3, 1}};
  res = a.bonus(6, p1, p2);
  dbg(res);

  return 0;
}

#endif
