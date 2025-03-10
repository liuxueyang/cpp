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

struct info {
  int mx;
  info() : mx(0) {}
  info(int x_) : mx(x_) {}

  info operator+(const info &rh) const { return info(max(mx, rh.mx)); }
};

struct SegmentTree {
  int n;
  VI a;

  struct node {
    info val;
  };

  vector<node> seg;

  SegmentTree(int n_, VI &a_) : n(n_), a(a_) { seg = vector<node>(n * 4 + 10); }

  void update(int id) {
    int left = id * 2, right = left + 1;
    seg[id].val = seg[left].val + seg[right].val;
  }

  void build(int id, int l, int r) {
    if (l == r) {
      seg[id].val = info(a[l]);
      return;
    }

    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void change(int id, int l, int r, int pos, int d) {
    if (l == r) {
      seg[id].val = info(d);
      return;
    }

    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (pos <= mid)
      change(left, l, mid, pos, d);
    else
      change(right, mid + 1, r, pos, d);
    update(id);
  }

  int binary_search(int id, int l, int r, int ql, int qr, int d) {
    int mid = (l + r) / 2, left = id * 2, right = left + 1;

    if (l == r) {
      if (seg[id].val.mx >= d) return l;
      return -1;
    }

    if (l == ql && r == qr) {
      // 线段树二分的关键：如果整个区间在询问区间内，
      // 先查看整个区间的性质是否满足条件，然后再查看左右儿子。
      // 如果没有这个判断，那么就会退化成询问区间中的每个点。
      if (seg[id].val.mx < d) return -1;
      int res = binary_search(left, l, mid, ql, mid, d);
      if (res != -1) return res;
      return binary_search(right, mid + 1, r, mid + 1, qr, d);
    }

    if (qr <= mid)
      return binary_search(left, l, mid, ql, qr, d);
    else if (ql > mid)
      return binary_search(right, mid + 1, r, ql, qr, d);
    else {
      int res = binary_search(left, l, mid, ql, mid, d);
      if (res != -1) return res;
      return binary_search(right, mid + 1, r, mid + 1, qr, d);
    }
  }
};

class Solution {
 public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int n{SZ(fruits)};
    VI a(n + 1);
    For(i, 0, n) { a[i + 1] = baskets[i]; }

    SegmentTree tree(n, a);
    tree.build(1, 1, n);
    int res{};

    for (auto x : fruits) {
      int pos = tree.binary_search(1, 1, n, 1, n, x);
      if (pos == -1)
        res++;
      else
        tree.change(1, 1, n, pos, -1);
    }

    return res;
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
  int n;
  while (cin >> n) {
    VI ve1(n), ve2(n);
    for (auto &x : ve1) cin >> x;
    cin >> n;
    for (auto &x : ve2) cin >> x;

    int res = a.numOfUnplacedFruits(ve1, ve2);
    dbg(res);
  }

  return 0;
}

#endif