// Date: Sun Oct  6 17:44:12 2024

#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <array>
#include <bitset>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
typedef vector<string> VS;
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
  if (!root)
    return;
  dbgi(root->val);
  PrePrintLCTree(root->left);
  PrePrintLCTree(root->right);
}

class LCCodec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root)
      return "";

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

    if (!n)
      return nullptr;

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
      while (i < m && !a[i])
        ++i;
      if (i >= n)
        break;

      if (j < m)
        a[i]->left = a[j++];
      if (j < m)
        a[i]->right = a[j++];
      ++i;
    }

    return a[0];
  }
};

#endif
// End of LeetCode

class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &a) {
    int n{SZ(a)};
    VI ans, ind(n);

    iota(all(ind), 0);
    sort(all(ind), [&](int x, int y) { return a[x][0] < a[y][0]; });

    pqg<PII> q;
    int cur{};

    For(i, 0, n) {
      int id = ind[i], l = a[id][0], len = a[id][1];
      while (i < n && cur >= a[ind[i]][0]) {
        id = ind[i];
        l = a[id][0], len = a[id][1];
        q.push({len, id});
        i++;
      }

      if (i == n)
        break;
      if (q.empty()) {
        cur = l;
        q.push({len, id});
      } else {
        auto [len, id] = q.top();
        q.pop();
        ans.pb(id);
        cur += len;
        i--;
      }
    }

    while (nemp(q)) {
      auto [len, id] = q.top();
      q.pop();
      ans.pb(id);
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

  vector<VI> ve{{1, 2}, {2, 4}, {3, 2}, {4, 1}};
  auto res = a.getOrder(ve);
  dbg(res);

  ve = {{19, 13}, {16, 9},  {21, 10}, {32, 25}, {37, 4},  {49, 24}, {2, 15},
        {38, 41}, {37, 34}, {33, 6},  {45, 4},  {18, 18}, {46, 39}, {12, 24}};
  res = a.getOrder(ve);
  dbg(res);

  ve = {{35, 36}, {11, 7}, {15, 47}, {34, 2},  {47, 19}, {16, 14},
        {19, 8},  {7, 34}, {38, 15}, {16, 18}, {27, 22}, {7, 15},
        {43, 2},  {10, 5}, {5, 4},   {3, 11}};
  res = a.getOrder(ve);
  dbg(res);

  ve = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}};
  res = a.getOrder(ve);
  dbg(res);

  return 0;
}

#endif
