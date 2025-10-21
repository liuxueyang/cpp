// Date: Sat Oct  5 10:46:00 2024

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
  struct node {
    int l, r, idx, val;
    node() {}

    node(int l_, int r_, int idx_) : l(l_), r(r_), idx(idx_) { val = -1; }
    bool operator<(const node &rh) const { return l < rh.l; }

  };

  struct manage {
    int low;
    set<int> s;

    manage() {
      low = 0;
      s = {};
    }

    void add(int v) { s.insert(v); }

    int remove() {
      if (s.empty())
        return low++;
      else {
        auto it = s.begin();
        int ans = *it;
        s.erase(it);
        return ans;
      }
    }
  };

  int smallestChair(vector<vector<int>> &a, int tgt) {
    int n{SZ(a)}, mx{};
    vector<node> b(n);
    map<int, int> ml;
    map<int, VI> mr;

    For(i, 0, n) {
      auto &v = a[i];
      b[i] = node(v[0], v[1], i);
      ckmax(mx, v[1]);
    }
    sort(all(b));

    For(i, 0, n) {
      ml[b[i].l] = i + 1;
      mr[b[i].r].pb(i + 1);
    }

    manage mg{};

    For1(i, 1, mx) {
      for (auto x : mr[i]) {
        mg.add(b[x - 1].val);
      }
      if (!has(ml, i))
        continue;

      int x = ml[i];
      x--;
      b[x].val = mg.remove();
      if (b[x].idx == tgt)
        return b[x].val;
    }

    return 0;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

  Solution a;
  vector<VI> ve{{33889, 98676}, {80071, 89737}, {44118, 52565}, {52992, 84310},
                {78492, 88209}, {21695, 67063}, {84622, 95452}, {98048, 98856},
                {98411, 99433}, {55333, 56548}, {65375, 88566}, {55011, 62821},
                {48548, 48656}, {87396, 94825}, {55273, 81868}, {75629, 91467}};
  int k = 6;

  auto res = a.smallestChair(ve, k);
  dbg(res);

  return 0;
}

#endif
