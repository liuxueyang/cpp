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
ostream& operator<<=(ostream& os, const vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
}

template <class T>
istream& operator>>=(istream& is, vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    is >> a[i];
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& a) {
  int n = int(a.size());
  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i == n - 1];
  }
  return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& a) {
  for (auto& x : a) is >> x;
  return is;
}

// For LeetCode
#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*
// End of LeetCode

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

const int N = 100010;
int encCost, flatCost;
string s;

struct tag {
  ll d;

  tag operator+(const tag& r) {
    tag ans;
    ans.d = d + r.d;
    return ans;
  }

  bool empty() { return d == 0; }
  void clear() { d = 0; }
};

struct info {
  int len, cnt;
  ll v;

  info operator+(const info& r) {
    info ans;
    ans.len = len + r.len;
    ans.cnt = cnt + r.cnt;
    ans.v = INFL;

    if (ans.len % 2 == 0) {
      ckmin(ans.v, v + r.v);
    }

    if (cnt == 0)
      ckmin(ans.v, 1LL * flatCost);
    else
      ckmin(ans.v, 1LL * len * cnt * encCost);
    return ans;
  }

  info operator+(const tag& r) {
    info ans;
    ans.v = v + r.d;
    return ans;
  }
};

template <class T>
struct segtree {
  struct Node {
    info v;
    tag t;
  } seg[N * 4];

  PII child(int id) { return {id * 2, id * 2 + 1}; }

  void update(int id) {
    auto ch = child(id);
    seg[id].v = seg[ch.f1].v + seg[ch.second].v;
  }

  void set_tag(int id, tag t) {
    seg[id].t = seg[id].t + t;
    seg[id].v = seg[id].v + t;
  }

  void push_down(int id) {
    if (!seg[id].t.empty()) {
      auto ch = child(id);
      auto t = seg[id].t;
      set_tag(ch.f1, t), set_tag(ch.f2, t);
      seg[id].t.clear();
    }
  }

  void build(int id, int l, int r) {
    if (l > r) return;
    if (l == r) {
      int len = 1, cnt = (s[l] == '1');
      ll val = 0;
      if (cnt == 0)
        val = flatCost;
      else
        val = encCost;

      seg[id].v = {len, cnt, val};
      seg[id].t = {0};
    } else {
      int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
      build(id1, l, mid);
      build(id2, mid + 1, r);

      update(id);
    }
  }

  info query(int id, int l, int r, int ql, int qr) {
    if (ql > qr) return {};

    if (l == ql && r == qr) {
      return seg[id].v;
    }

    push_down(id);

    int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
    if (qr <= mid)
      return query(id1, l, mid, ql, qr);
    else if (ql > mid)
      return query(id2, mid + 1, r, ql, qr);
    else {
      return query(id1, l, mid, ql, mid) + query(id2, mid + 1, r, mid + 1, qr);
    }
  }

  // modify segment
  void modify(int id, int l, int r, int ql, int qr, tag t) {
    if (ql > qr) return;

    if (l == ql && r == qr) {
      set_tag(id, t);
      return;
    }

    push_down(id);

    int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
    if (qr <= mid)
      modify(id1, l, mid, ql, qr, t);
    else if (ql > mid)
      modify(id2, mid + 1, r, ql, qr, t);
    else {
      modify(id1, l, mid, ql, mid, t);
      modify(id2, mid + 1, r, mid + 1, qr, t);
    }

    update(id);
  }

  // change a point p to value v
  void change(int id, int l, int r, int p, T v) {
    if (l == r) {
      seg[id].v = {v};
    } else {
      push_down(id);

      int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
      if (p <= mid)
        change(id1, l, mid, p, v);
      else
        change(id2, mid + 1, r, p, v);

      update(id);
    }
  }
};

segtree<ll> tree;

class Solution {
 public:
  long long minCost(string s_, int encCost_, int flatCost_) {
    int n = SZ(s_);
    s = " " + s_, encCost = encCost_, flatCost = flatCost_;
    tree.build(1, 1, n);

    return tree.query(1, 1, n, 1, n).v;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  string s;
  int enc, flat;
  cin >> s >> enc >> flat;
  auto res = a.minCost(s, enc, flat);
  cout << res << '\n';

  return 0;
}

#endif