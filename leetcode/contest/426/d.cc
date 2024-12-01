// Date: Sun Dec  1 11:25:09 2024

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
typedef vector<string> VS;
typedef vector<bool> VB;
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

template <typename t>
istream &operator>>(istream &in, vector<t> &vec) {
  for (t &x : vec) in >> x;
  return in;
}

template <typename t>
ostream &operator<<(ostream &out, vector<t> &vec) {
  int n = SZ(vec);
  For(i, 0, n) {
    out << vec[i];
    if (i < n - 1) out << ' ';
  }
  return out;
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
class Solution {
 public:
  int n, m;
  VVI g1, g2;
  VI d1, d2;

  void dfs(int u, int fa, int d, VVI &g, VI &dis) {
    if (d < 0) return;
    dis[u] = d;

    for (auto v : g[u]) {
      if (v == fa) continue;
      dfs(v, u, d + 1, g, dis);
    }
  }

  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2) {
    n = 1 + SZ(edges1), m = SZ(edges2) + 1;
    d1 = VI(n + 10), d2 = VI(m + 10);
    g1 = VVI(n + 10), g2 = VVI(m + 10);

    for (auto &v : edges1) {
      int x = v[0], y = v[1];
      g1[x].pb(y), g1[y].pb(x);
    }
    for (auto &v : edges2) {
      int x = v[0], y = v[1];
      g2[x].pb(y), g2[y].pb(x);
    }

    int P{};
    dfs(0, -1, 0, g2, d2);
    int cnt{};
    For(i, 0, m) {
      if (d2[i] % 2 == 0) cnt++;
    }
    P = m - cnt;
    if (m > 1) P = max(cnt, m - cnt);

    dbg(P);

    VI ans(n);
    dfs(0, -1, 0, g1, d1);
    cnt = 0;
    For(i, 0, n) {
      if (d1[i] % 2 == 0) cnt++;
    }
    dbg(cnt, n - cnt);

    For(i, 0, n) {
      if (d1[i] % 2 == 0) {
        ans[i] = cnt + P;
      } else {
        ans[i] = n - cnt + P;
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
  _m_gen64.seed(Pr);

  Solution a;
  VVI g1, g2;
  VI res;

  g1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
  g2 = {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};
  res = a.maxTargetNodes(g1, g2);
  dbg(res);

  g1 = {{0, 1}, {0, 2}, {0, 3}, {0, 4}}, g2 = {{0, 1}, {1, 2}, {2, 3}};
  res = a.maxTargetNodes(g1, g2);
  dbg(res);

  g1 = {{0, 1}}, g2 = {{0, 1}};
  res = a.maxTargetNodes(g1, g2);
  dbg(res);

  return 0;
}

#endif
