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

const int N = 100010;

int n, q, a[N];

struct info {
  int xl, xr;
  int preInc, sufInc, len;
  ll val;

  info() {
    xl = xr = 0;
    preInc = sufInc = len = 0;
    val = 0;
  }
  info(int ai) {
    xl = xr = ai;
    preInc = sufInc = len = 1;
    val = 1;
  }

  info operator+(const info& r) {
    info ans;
    ans.xl = xl;
    ans.xr = r.xr;

    ans.preInc = preInc;
    ans.sufInc = r.sufInc;
    if (len == preInc && xr <= r.xl) {
      ans.preInc += r.preInc;
    }
    if (r.len == r.sufInc && xr <= r.xl) {
      ans.sufInc += sufInc;
    }
    ans.val = val + r.val;
    if (xr <= r.xl) {
      ans.val += 1LL * sufInc * r.preInc;
    }
    ans.len = len + r.len;

    return ans;
  }
};

ostream& operator<<(ostream& os, info& a) {
  os << "xl=" << a.xl << ",xr=" << a.xr << ",preInc=" << a.preInc
     << ",sufInc=" << a.sufInc << ",len=" << a.len << ",val=" << a.val;
  return os;
}

struct Node {
  info v;
} seg[N * 4];

void update(int id) {
  int id1 = id * 2, id2 = id1 + 1;
  seg[id].v = seg[id1].v + seg[id2].v;
}

void build(int id, int l, int r) {
  if (l > r) return;
  if (l == r) {
    seg[id].v = info(a[l]);
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

class Solution {
 public:
  vector<long long> countStableSubarrays(vector<int>& nums,
                                         vector<vector<int>>& queries) {
    n = SZ(nums);
    For(i, 0, n) { a[i + 1] = nums[i]; }
    build(1, 1, n);
    q = SZ(queries);
    VL ans(q);
    For(i, 0, q) {
      int l = queries[i][0], r = queries[i][1];
      l++, r++;
      auto res = query(1, 1, n, l, r);
      // cerr << res << '\n';
      ans[i] = res.val;
    }
    return ans;
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
  int an;
  cin >> an;
  VI arr(an);
  cin >>= arr;
  int q1, q2;
  cin >> q1 >> q2;
  VVI que(q1, VI(q2));
  For(i, 0, q1) cin >>= que[i];
  auto res = a.countStableSubarrays(arr, que);
  for (auto i : res) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}

#endif