// Date: Fri Jun  6 14:05:51 2025

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

class Solution1 {
 public:
  int minMoves(vector<string> &a) {
    int n = int(a.size()), m = int(a[0].size());
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
        q;

    vector<array<int, 2>> lst[26];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
          lst[a[i][j] - 'A'].push_back({i, j});
        }
      }
    }

    q.push({0, 0, 0});
    vector<vector<int>> d(n + 1, vector<int>(m + 1, INF));
    vector<vector<bool>> st(n + 1, vector<bool>(m + 1));
    d[0][0] = 0;

    while (!q.empty()) {
      auto [cur, x, y] = q.top();
      q.pop();

      if (st[x][y]) continue;
      st[x][y] = true;

      if (a[x][y] >= 'A' && a[x][y] <= 'Z') {
        int id = a[x][y] - 'A';
        if (!lst[id].empty()) {
          for (auto [x1, y1] : lst[id]) {
            if (d[x1][y1] > cur) {
              d[x1][y1] = cur;
              q.push({cur, x1, y1});
            }
          }
          lst[id] = {};
        }
      }
      int x1, y1;
      for (int i = 0; i < 4; i++) {
        x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (!(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] != '#'))
          continue;
        if (d[x1][y1] > cur + 1) {
          d[x1][y1] = cur + 1;
          q.push({cur + 1, x1, y1});
        }
      }
    }
    return d[n - 1][m - 1] >= INF ? -1 : d[n - 1][m - 1];
  }
};

class Solution {
 public:
  int minMoves(vector<string> &a) {
    int n = int(a.size()), m = int(a[0].size());
    vector<vector<int>> d(n + 1, vector<int>(m + 1, INF));
    vector<array<int, 2>> lst[26];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char ch = a[i][j];
        if (ch >= 'A' && ch <= 'Z') {
          lst[ch - 'A'].push_back({i, j});
        }
      }
    }

    d[0][0] = 0;
    deque<array<int, 2>> q;
    q.push_back({0, 0});
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop_front();

      int x1, y1;
      int cur = d[x][y];
      if (vis[x][y]) continue;
      vis[x][y] = true;
      if (x == n - 1 && y == m - 1) return d[x][y];

      char ch = a[x][y];
      if (ch >= 'A' && ch <= 'Z') {
        int id = ch - 'A';
        if (!lst[id].empty()) {
          for (auto [x1, y1] : lst[id]) {
            if (x1 == x && y1 == y) continue;

            if (d[x1][y1] > cur && !vis[x1][y1]) {
              d[x1][y1] = cur;
              q.push_front({x1, y1});
            }
          }
          lst[id] = {};
        }
      }

      for (int i = 0; i < 4; i++) {
        x1 = x + dir[i][0];
        y1 = y + dir[i][1];
        if (!(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] != '#'))
          continue;
        if (d[x1][y1] > cur + 1 && !vis[x1][y1]) {
          d[x1][y1] = cur + 1;
          q.push_back({x1, y1});
        }
      }
    }

    if (d[n - 1][m - 1] >= INF) return -1;
    return d[n - 1][m - 1];
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

  Solution a;
  vector<string> arr;
  int res;

  // arr = {"A..", ".A.", "..."};
  // res = a.minMoves(arr);
  // dbg(res);

  // arr = {".#...", ".#.#.", ".#.#.", "...#."};
  // res = a.minMoves(arr);
  // dbg(res);

  arr = {"..C.", "C.A."};
  res = a.minMoves(arr);
  dbg(res);

  // arr = {"..G", "C.D", ".EE"};
  // res = a.minMoves(arr);
  // dbg(res);

  return 0;
}

#endif
