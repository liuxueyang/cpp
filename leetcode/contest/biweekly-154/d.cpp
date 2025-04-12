#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
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
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<bool> VB;
typedef vector<vector<bool>> VVB;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998'244'353;
const ll INFL = 0x3f3f3f3f'3f3f3f3f;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};
mt19937_64 _m_gen64;

const ull Pr = 131, Pr1 = 13331;

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

template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
}

template <class T>
istream &operator>>(istream &is, vector<T> &a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    is >> a[i];
  }
  return is;
}

template <class T>
ostream &operator<<=(ostream &os, const vector<T> &a) {
  int n = int(a.size());
  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i == n - 1];
  }
  return os;
}

template <class T>
istream &operator>>=(istream &is, vector<T> &a) {
  for (auto &x : a) is >> x;
  return is;
}

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
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

void PrePrintLCTree(TNP root) {
  if (!root) return;
  dbgi(root->val);
  PrePrintLCTree(root->left);
  PrePrintLCTree(root->right);
}

class LCCodec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root) return "";

    vector<TNP> a;
    a.pb(root);
    string ans;

    while (nemp(a)) {
      vector<TNP> b;

      string tmp;
      for (auto x : a) {
        if (nemp(ans)) {
          ans += ',';
        }

        if (x)
          ans += to_string(x->val);
        else
          ans += "null";
      }

      bool ok{false};
      for (auto x : a) {
        if (x) {
          b.pb(x->left);
          b.pb(x->right);

          if (x->left || x->right) {
            ok = true;
          }
        }
      }

      if (ok)
        a = std::move(b);
      else
        a = {};
    }

    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    vector<TNP> a;
    int n = SZ(data);
    vector<string> b;

    if (!n) return nullptr;

    string t;
    for (auto x : data) {
      if (x == ',') {
        b.pb(t);
        t = "";
      } else
        t += x;
    }
    b.pb(t);

    for (auto x : b) {
      if (x == "null")
        a.pb(nullptr);
      else
        a.pb(new TN(stoi(x)));
    }

    int m = SZ(a);
    int i = 0, j = 1;

    while (i < m) {
      while (i < m && !a[i]) ++i;
      if (i >= n) break;

      if (j < m) a[i]->left = a[j++];
      if (j < m) a[i]->right = a[j++];
      ++i;
    }

    return a[0];
  }
};

LNP CreateList(VI &a) {
  LN *du{new LN(0)}, *cur{}, *pre{du};

  for (auto x : a) {
    cur = new LN(x);
    pre->next = cur;
    pre = cur;
  }

  auto res = du->next;
  delete du;
  return res;
}

void PrintList(LNP head) {
  while (head) {
    dbgi(head->val);
    head = head->next;
  }
  dbgln();
}

#endif
// End of LeetCode

const int N = 100100;
int a[N], dfn[N], dfo[N], b[N];
int e[N * 2], ne[N * 2], h[N];
int ts, idx;

struct tag {
  ll d;
  tag() : d(0) {}
  tag(ll d_) : d(d_) {}
  tag operator+(const tag &rh) const { return {d + rh.d}; }
};

struct Info {
  int len;
  ll sum;
  Info() : len(1), sum(0) {}
  Info(int len_, ll sum_) : len(len_), sum(sum_) {}

  Info operator+(const Info &rh) const { return {len + rh.len, sum + rh.sum}; }
  Info operator+(const tag &rh) const { return {len, sum + len * rh.d}; }
};

struct node {
  Info val;
  tag t;
};

node seg[N * 4];

struct SegmentTree {
  int n;

  SegmentTree() : n(0) {}
  SegmentTree(int n_) : n(n_) {}

  void set_tag(int id, tag t) {
    seg[id].val = seg[id].val + t;
    seg[id].t = seg[id].t + t;
  }

  void update(int id) {
    int left = id * 2, right = left + 1;
    seg[id].val = seg[left].val + seg[right].val;
  }

  void push_down(int id) {
    auto &t = seg[id].t;
    if (t.d != 0) {
      int left = id * 2, right = left + 1;
      set_tag(left, t);
      set_tag(right, t);
      t.d = 0;
    }
  }

  void build(int id, int l, int r) {
    if (l == r) {
      seg[id].val = {1, a[l]};
      return;
    }
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void modify(int id, int l, int r, int ql, int qr, tag t) {
    if (l >= ql && r <= qr) {
      set_tag(id, t);
      return;
    }
    push_down(id);

    int mid = (l + r) / 2, left = id * 2, right = left + 1;
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

  Info query(int id, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) {
      return seg[id].val;
    }

    int mid = (l + r) / 2, left = id * 2, right = left + 1;
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

void Init() {
  idx = ts = 0;
  memset(h, -1, sizeof h);
}

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int u, int fa) {
  dfn[u] = ++ts;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    if (v == fa || dfn[v]) continue;
    dfs(v, u);
  }
  dfo[u] = ts;
}

class Solution {
 public:
  vector<int> treeQueries(int n, vector<vector<int>> &edges,
                          vector<vector<int>> &queries) {
    Init();
    For1(i, 0, n) { a[i] = b[i] = dfn[i] = dfo[i] = 0; }
    For1(i, 0, 4 * n) seg[i] = node();

    map<PII, int> adj;

    for (auto &edg : edges) {
      int u = edg[0], v = edg[1];
      add(u, v), add(v, u);

      if (u > v) swap(u, v);
      adj[PII(u, v)] = edg[2];
    }
    dfs(1, -1);

    SegmentTree tree(n);
    tree.build(1, 1, n);

    for (auto &edg : edges) {
      int u = edg[0], v = edg[1], w = edg[2];
      int du = dfn[u], dv = dfn[v], l, r, pt;

      if (du < dv) {
        // u is parent
        pt = v;
      } else {
        pt = u;
      }
      l = dfn[pt], r = dfo[pt];

      tree.modify(1, 1, n, l, r, w);
    }

    VI ans;

    for (auto &que : queries) {
      if (que[0] == 1) {
        int u = que[1], v = que[2], w1 = que[3];
        if (u > v) swap(u, v);

        int delt = w1 - adj[PII(u, v)];
        adj[PII(u, v)] = w1;

        int du = dfn[u], dv = dfn[v], l, r, pt;

        if (du < dv) {
          // u is parent
          pt = v;
        } else {
          pt = u;
        }
        l = dfn[pt], r = dfo[pt];

        tree.modify(1, 1, n, l, r, delt);
      } else {
        int u = que[1], l = dfn[u];
        auto res = tree.query(1, 1, n, l, l);
        ans.pb(res.sum);
      }
    }
    return ans;
  }
};

#ifdef _DEBUG

int main(void) {
  freopen("input.txt", "r", stdin);
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

  Solution a;
  int n = 2;
  VVI edges = {{1, 2, 7}}, queries = {{2, 2}, {1, 1, 2, 4}, {2, 2}};
  auto res = a.treeQueries(n, edges, queries);
  dbg(res);

  n = 4;
  edges = {{1, 2, 2}, {2, 3, 1}, {3, 4, 5}},
  queries = {{2, 4}, {2, 3}, {1, 2, 3, 3}, {2, 2}, {2, 3}};
  res = a.treeQueries(n, edges, queries);
  dbg(res);

  return 0;
}

#endif