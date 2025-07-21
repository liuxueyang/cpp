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
#include <unordered_map>
#include <unordered_set>
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

LNP CreateList(VI a) {
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

int mypopcount(ll x) {
  ll ans{};
  while (x) {
    if (x & 1) ans++;
    x >>= 1;
  }
  return ans;
}

int popcount_depth(ll x) {
  int res{};

  while (x > 1) {
#ifdef _DEBUG
    x = mypopcount(x);
#else
    x = __builtin_popcountll(x);
#endif

    res++;
  }
  return res;
}

struct info {
  int val;

  info() { val = 0; }

  info operator+(const info &r) {
    info ans;
    ans.val = val + r.val;
    return ans;
  }
};

struct Node {
  info v;
};

struct SegmentTree {
  int n;
  VI a;
  vector<Node> seg;

  SegmentTree(): n(0), a{}, seg {} {}

  SegmentTree(int n) {
    this->n = n;
    a = VI(n + 1);
    seg = vector<Node>(4 * n);
  }

  void update(int id) {
    int id1 = id * 2, id2 = id1 + 1;
    seg[id].v = seg[id1].v + seg[id2].v;
  }

  void build(int id, int l, int r) {
    if (l > r) return;
    if (l == r) {
      info val;
      val.val = a[l];
      seg[id].v = val;
    } else {
      int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
      build(id1, l, mid);
      build(id2, mid + 1, r);

      update(id);
    }
  }

  info query(int id, int l, int r, int ql, int qr) {
    if (ql > qr) return info();

    if (l == ql && r == qr) {
      return seg[id].v;
    }
    int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
    if (qr <= mid)
      return query(id1, l, mid, ql, qr);
    else if (ql > mid)
      return query(id2, mid + 1, r, ql, qr);
    else {
      return query(id1, l, mid, ql, mid) + query(id2, mid + 1, r, mid + 1, qr);
    }
  }

  void change(int id, int l, int r, int p, ll v) {
    if (l == r) {
      info val;
      val.val = v;
      seg[id].v = val;
    } else {
      int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
      if (p <= mid)
        change(id1, l, mid, p, v);
      else
        change(id2, mid + 1, r, p, v);

      update(id);
    }
  }
};

class Solution {
 public:
  vector<int> popcountDepth(vector<long long> &nums,
                            vector<vector<long long>> &queries) {
    int n = int(nums.size());
    vector<SegmentTree> tree(6);

    For(i, 0, 6) tree[i] = SegmentTree(n);

    For(i, 0, n) {
      ll x = nums[i], depth = popcount_depth(x);
      tree[depth].a[i + 1]++;
    }

    For(i, 0, 6) tree[i].build(1, 1, n);

    VI ans;

    for (auto &vec : queries) {
      int op = vec[0];
      if (op == 1) {
        ll l = vec[1], r = vec[2], k = vec[3];
        l++, r++;

        auto res = tree[k].query(1, 1, n, l, r);
        ans.pb(res.val);
      } else {
        ll idx = vec[1], val = vec[2];

        ll x = nums[idx], depth = popcount_depth(x);
        tree[depth].change(1, 1, n, idx + 1, 0);

        nums[idx] = val;
        depth = popcount_depth(val);
        tree[depth].change(1, 1, n, idx + 1, 1);
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

  VL arr{2, 4};
  VVL queries{{1, 0, 1, 1}, {2, 1, 1}, {1, 0, 1, 0}};
  auto res = a.popcountDepth(arr, queries);
  dbg(res);

  return 0;
}

#endif
