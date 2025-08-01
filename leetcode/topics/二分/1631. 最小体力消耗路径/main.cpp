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
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
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

class Solution1 {
 public:
  vector<vector<int>> a;
  int n, m, h;
  vector<vector<bool>> vis;

  bool dfs(int x, int y) {
    vis[x][y] = true;
    if (x == n - 1 && y == m - 1) return true;
    int x1, y1;

    for (int i = 0; i < 4; i++) {
      x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) {
        if (abs(a[x1][y1] - a[x][y]) <= h && !vis[x1][y1]) {
          if (dfs(x1, y1)) return true;
        }
      }
    }

    return false;
  }

  bool check(int h) {
    vis = vector<vector<bool>>(n, vector<bool>(m));
    this->h = h;
    return dfs(0, 0);
  }

  int minimumEffortPath(vector<vector<int>> &heights) {
    a = heights;
    n = int(a.size()), m = int(a[0].size());

    int l = 0, r = 1e6, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }

    return r;
  }
};

class Solution2 {
 public:
  int n, m;
  struct node {
    int w, u, v;
    bool operator<(const node &rh) const { return w < rh.w; }
  };
  vector<node> adj;
  vector<int> fa;

  void Init() {
    for (int i = 0; i < n * m; i++) fa[i] = i;
  }

  int Find(int u) { return fa[u] == u ? u : fa[u] = Find(fa[u]); }
  void Union(int u, int v) {
    int ru = Find(u), rv = Find(v);
    fa[ru] = rv;
  }

  int minimumEffortPath(vector<vector<int>> &a) {
    n = int(a.size());
    m = int(a[0].size());
    adj = {};

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int id = i * m + j;

        for (int k = 0; k < 2; k++) {
          int i1 = i + dir[k][0], j1 = j + dir[k][1];
          if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m) {
            int id1 = i1 * m + j1;
            adj.push_back({abs(a[i][j] - a[i1][j1]), id, id1});
          }
        }
      }
    }

    int target = n * m - 1;
    sort(adj.begin(), adj.end());

    fa = vector<int>(n * m);
    Init();

    if (Find(0) == Find(target)) return 0;

    for (auto [w, u, v] : adj) {
      if (Find(u) != Find(v)) Union(u, v);
      if (Find(0) == Find(target)) return w;
    }

    return 0;
  }
};

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>> &a) {
    int n = int(a.size()), m = int(a[0].size());
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<int>> dis(n, vector<int>(m, INF));

    dis[0][0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, 0});

    while (!q.empty()) {
      auto [base, ver] = q.top();
      q.pop();

      int x = ver / m, y = ver % m;
      if (vis[x][y]) continue;

      vis[x][y] = true;
      if (x == n - 1 && y == m - 1) return base;

      for (int i = 0; i < 4; i++) {
        int x1 = x + dir[i][0], y1 = y + dir[i][1];
        
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) {
          int tmp = max(base, abs(a[x][y] - a[x1][y1]));
          if (tmp < dis[x1][y1]) {
            dis[x1][y1] = tmp;
            q.push({tmp, x1 * m + y1});
          }
        }
      }
    }

    return 0;
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
  int n, m;
  while (cin >> n >> m) {
    VVI arr(n, VI(m));
    For(i, 0, n) cin >>= arr[i];
    int res = a.minimumEffortPath(arr);
    dbg(res);
  }

  return 0;
}

#endif
