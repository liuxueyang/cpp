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
    {0, -1}, {-1, 0}, {0, 1}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
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
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    is >> a[i];
  }
  return is;
}

template <class T>
ostream& operator<<=(ostream& os, const vector<T>& a) {
  int n = int(a.size());
  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i == n - 1];
  }
  return os;
}

template <class T>
istream& operator>>=(istream& is, vector<T>& a) {
  for (auto& x : a) is >> x;
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
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

#ifdef _DEBUG
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode* next) : val(val), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
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
  string serialize(TreeNode* root) {
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
  TreeNode* deserialize(string data) {
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

const int N = 205, K = 1005;
int d[N][N][K];
int n, m, k;
int f[2][N][K];

class Solution {
 public:
  int maxPathScore(vector<vector<int>>& grid, int K) {
    n = SZ(grid), m = SZ(grid[0]);

    For(i, 0, n) {
      int cur = i & 1, nxt = cur ^ 1;
      For(j, 0, m) For1(k, 0, K) f[cur][j][k] = -INF;

      if (i == 0) {
        int cost00 = (grid[0][0] >= 1);
        f[cur][0][cost00] = grid[0][0];
      }

      For(j, 0, m) {
        if (i == 0 && j == 0) continue;

        int cost = (grid[i][j] >= 1);
        For1(k, cost, K) {
          if (i > 0) ckmax(f[cur][j][k], f[nxt][j][k - cost] + grid[i][j]);
          if (j > 0) ckmax(f[cur][j][k], f[cur][j - 1][k - cost] + grid[i][j]);
        }
      }
    }

    int ans = -INF, cur = (n - 1) & 1;
    For1(k, 0, K) ckmax(ans, f[cur][m - 1][k]);
    if (ans >= 0) return ans;
    return -1;
  }
};

class Solution1 {
 public:
  VVI a;
  bool check(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

  int dfs(int x, int y, int u) {
    if (x == 1 && y == 1 && u >= 0) return d[x][y][u];
    if (d[x][y][u] != -INF) return d[x][y][u];

    int& res = d[x][y][u];
    res = -INF;

    int u1 = u;
    if (a[x][y] >= 1) u1--;

    For(i, 0, 2) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1)) {
        if (u1 >= 0) {
          int tmp = dfs(x1, y1, u1);
          ckmax(res, tmp + a[x][y]);
        }
      }
    }
    return res;
  }

  int maxPathScore(vector<vector<int>>& grid, int k_) {
    n = SZ(grid), m = SZ(grid[0]);
    a = VVI(n + 1, VI(m + 1));
    k = k_;
    For(i, 0, n) For(j, 0, m) a[i + 1][j + 1] = grid[i][j];

    For1(i, 0, n) For1(j, 0, m) For1(k0, 0, k) d[i][j][k0] = -INF;

    int cost00 = (a[1][1] >= 1);
    if (k < cost00) return -1;
    For1(k0, 0, k - cost00) d[1][1][k0] = a[1][1];

    int res = dfs(n, m, k);
    if (res < 0) return -1;
    return res;
  }
};

#ifdef _DEBUG

int main(void) {
#if defined(_DEBUG) && !defined(_CPH) && !defined(_SUB)
  freopen("input.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  int n, m;
  cin >> n >> m;
  VVI arr(n, VI(m));
  For(i, 0, n) cin >>= arr[i];
  int k;
  cin >> k;
  auto res = a.maxPathScore(arr, k);
  cout << res << '\n';

  return 0;
}

#endif
