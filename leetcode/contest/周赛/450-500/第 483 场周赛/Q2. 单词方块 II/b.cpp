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

class Solution1 {
 public:
  vector<VS> solve(VS& a) {
    vector<VS> ans;
    sort(all(a));
    auto check = [&](const vector<string>& a) -> bool {
      auto top = a[0], left = a[1], right = a[2], down = a[3];
      return top[0] == left[0] && top[3] == right[0] && left[3] == down[0] &&
             right[3] == down[3];
    };
    do {
      if (check(a)) {
        ans.pb(a);
      }
    } while (next_permutation(all(a)));

    return ans;
  }

  vector<vector<string>> wordSquares(vector<string>& a) {
    int n = SZ(a);
    vector<VS> ans;

    For(i, 0, (1 << n)) {
      if (__builtin_popcount(i) == 4) {
        VS b = {};
        For(j, 0, n) {
          if ((i >> j) & 1) {
            b.pb(a[j]);
          }
        }
        auto tmp = solve(b);
        for (auto i : tmp) ans.pb(i);
      }
    }

    sort(all(ans));

    return ans;
  }
};

class Solution2 {
 public:
  vector<VS> solve(VS a) {
    vector<VS> ans;
    sort(all(a));
    auto check = [&](const vector<string>& a) -> bool {
      auto top = a[0], left = a[1], right = a[2], down = a[3];
      return top[0] == left[0] && top[3] == right[0] && left[3] == down[0] &&
             right[3] == down[3];
    };
    do {
      if (check(a)) {
        ans.pb(a);
      }
    } while (next_permutation(all(a)));

    return ans;
  }

  int n;
  VS b, arr;
  vector<VS> ans;

  void dfs(int idx, int pos) {
    if (pos == 4) {
      auto tmp = solve(b);
      for (auto i : tmp) ans.pb(i);
      return;
    } else if (idx == n)
      return;

    dfs(idx + 1, pos);
    b[pos] = arr[idx];
    dfs(idx + 1, pos + 1);
  }

  vector<vector<string>> wordSquares(vector<string>& a) {
    n = SZ(a);
    ans = {};
    arr = a;
    b = VS(4);
    dfs(0, 0);
    sort(all(ans));

    return ans;
  }
};

class Solution {
 public:
  VS a;
  int n;
  VI b;
  VB vis;
  vector<VS> ans;

  bool check() {
    auto top = a[b[0]], left = a[b[1]], right = a[b[2]], down = a[b[3]];
    return top[0] == left[0] && top[3] == right[0] && left[3] == down[0] &&
           right[3] == down[3];
  }

  void dfs(int idx) {
    if (idx == 4) {
      if (check()) {
        VS tmp;
        For(i, 0, 4) tmp.pb(a[b[i]]);
        ans.pb(tmp);
      }
      return;
    }

    For(i, 0, n) {
      if (!vis[i]) {
        vis[i] = true;
        b[idx] = i;
        dfs(idx + 1);
        vis[i] = false;
      }
    }
  }

  vector<vector<string>> wordSquares(vector<string>& a_) {
    a = a_;
    n = SZ(a);
    sort(all(a));
    b = VI(4);
    vis = VB(4);
    ans = {};
    dfs(0);

    return ans;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  VS arr;
  int n;
  cin >> n;
  For(i, 0, n) {
    string x;
    cin >> x;
    arr.pb(x);
  }
  auto res = a.wordSquares(arr);
  dbg(res);

  return 0;
}

#endif