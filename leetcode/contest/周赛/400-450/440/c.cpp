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

const int N = 100100;
int a[N], b[N], n, len;

inline int get_segid(int i) { return (i - 1) / len + 1; }

int query(int l, int r, int x) {
  int lsid = get_segid(l), rsid = get_segid(r);

  int res = -1;
  if (lsid == rsid) {
    For1(i, l, r) {
      if (a[i] >= x) {
        return i;
      }
    }
    return -1;
  }

  for (int i = l; get_segid(i) == lsid; i++) {
    if (a[i] >= x) return i;
  }

  For1(i, lsid + 1, rsid - 1) {
    if (b[i] >= x) {
      For1(j, (i - 1) * len + 1, i * len) {
        if (a[j] >= x) {
          return j;
        }
      }
      return -1;
    }
  }

  for (int i = r; get_segid(i) == rsid; i--) {
    if (a[i] >= x) {
      res = i;
    }
  }

  return res;
}

void change(int pos, int x) {
  int sid = get_segid(pos);
  a[pos] = x;
  // 更新块的最大值，初始化成最小值
  b[sid] = -INF;
  For1(i, (sid - 1) * len + 1, min(sid * len, n)) { ckmax(b[sid], a[i]); }
}

class Solution {
 public:
  int numOfUnplacedFruits(vector<int> &fruits_, vector<int> &baskets_) {
    n = SZ(fruits_);
    len = sqrt(n);

    For(i, 0, n) { a[i + 1] = baskets_[i]; }

    For1(i, 1, n) { b[i] = -INF; }

    For1(i, 1, n) {
      int sid = get_segid(i);
      ckmax(b[sid], a[i]);
    }

    int ans{};

    For1(i, 1, n) {
      int pos = query(1, n, fruits_[i - 1]);
      if (pos == -1) {
        ans++;
      } else {
        change(pos, -INF);
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