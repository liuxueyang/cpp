// Date: Thu Jun  5 17:01:01 2025

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

const int N = 20, M = 51, L = 10;

int d[N][N][M][1 << L];
int b[N][N], cnt, ans, mx_eng;

class Solution {
 public:
  int n, m;
  vector<string> a;

  int minMoves(vector<string> &classroom, int energy) {
    n = int(classroom.size());
    m = int(classroom[0].size());
    a = classroom;
    mx_eng = energy;
    ans = INF;

    memset(b, -1, sizeof b);

    cnt = 0;
    pair<int, int> start{-1, -1};

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'L') {
          b[i][j] = cnt++;
        } else if (a[i][j] == 'S') {
          start = {i, j};
        }
      }
    }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        for (int k = 0; k <= energy; k++)
          for (int S = 0; S < (1 << cnt); S++) d[i][j][k][S] = INF;

    queue<array<int, 4>> q;
    q.push({start.first, start.second, energy, 0});
    d[start.first][start.second][energy][0] = 0;

    while (!q.empty()) {
      auto [x, y, k, S] = q.front();
      q.pop();

      if (S == (1 << cnt) - 1) return d[x][y][k][S];

      int cur = d[x][y][k][S];
      int x1, y1;

      if (k == 0) continue;

      for (int i = 0; i < 4; i++) {
        x1 = x + dir[i][0];
        y1 = y + dir[i][1];

        if (!(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] != 'X'))
          continue;

        int k1 = k - 1;
        if (a[x1][y1] == 'R') k1 = mx_eng;

        if (a[x1][y1] == '.' || a[x1][y1] == 'R' || a[x1][y1] == 'S') {
          int &tmp = d[x1][y1][k1][S];
          if (tmp < INF) continue;

          if (ckmin(tmp, cur + 1)) {
            q.push({x1, y1, k1, S});
          }
        } else if (a[x1][y1] == 'L') {
          int &tmp = d[x1][y1][k1][S | (1 << b[x1][y1])];
          if (tmp < INF) continue;

          if (ckmin(tmp, cur + 1)) {
            q.push({x1, y1, k1, S | (1 << b[x1][y1])});
          }
        }
      }
    }

    return -1;
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
  int energy, res;

  arr = {"S.", "XL"};
  energy = 2;
  res = a.minMoves(arr, energy);
  dbg(res);

  arr = {"LS", "RL"};
  energy = 3;
  res = a.minMoves(arr, energy);
  dbg(res);

  arr = {"S", "R", "L", "X"};
  energy = 2;
  res = a.minMoves(arr, energy);
  dbg(res);

  arr = {"L.RX", ".R.S"};
  energy = 5;
  res = a.minMoves(arr, energy);
  dbg(res);

  arr = {"XL..", "SR.R", "LXL.", "RXLX"};
  energy = 12;
  res = a.minMoves(arr, energy);
  dbg(res);

  return 0;
}

#endif
