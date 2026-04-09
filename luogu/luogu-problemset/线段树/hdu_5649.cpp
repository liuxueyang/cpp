// Problem: DZY Loves Sorting
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=5649
// Memory Limit: 262 MB
// Time Limit: 12000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

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

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998244353;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

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
#define NL cout << '\n'

#define No() cout << "No\n"
#define Yes() cout << "Yes\n"
#define NO() cout << "NO\n"
#define YES() cout << "YES\n"

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

void read(int& x) {
  bool neg = false;
  x = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') neg = true;
    ch = getchar();
  }
  if (neg) {
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + ('0' - ch);
      ch = getchar();
    }
  } else {
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + (ch - '0');
      ch = getchar();
    }
  }
}

void write(int x) {
  bool neg = false;
  if (x < 0) {
    neg = true;
    putchar('-');
  }
  static int sta[40];
  int top = 0;
  do {
    sta[top++] = x % 10;
    x /= 10;
  } while (x);
  if (neg)
    while (top) putchar('0' - sta[--top]);
  else
    while (top) putchar('0' + sta[--top]);
}

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

void Init();
void solve();

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 1;
  cin >> T;
  while (T--) {
    Init();
    solve();
  }

  return 0;
}

void Init() {}

#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

struct Tag {
  int val;

  bool empty() const { return val == -1; }
  Tag operator+(const Tag& rh) const { return rh; }
  void clear() { val = -1; }
  Tag() : val(-1) {}
  Tag(int val_) : val(val_) {}
};

struct Info {
  int len;
  int val;

  Info operator+(const Info& rh) const {
    Info res{len + rh.len, val + rh.val};
    return res;
  }

  Info operator+(const Tag& t) const {
    Info res{len, len * t.val};
    return res;
  }
};

struct Node {
  Info info;
  Tag tag;

  Node() : info{}, tag{} {}
  Node(int val) : info{1, val}, tag{} {}
};

template <typename V>
struct SegmentTree {
  int n{0};
  vector<V> a{};

  vector<Node> seg{};

  explicit SegmentTree(vector<V>& a_) {
    n = int(a_.size());
    a = vector<V>(n + 1);
    copy(a_.begin(), a_.end(), a.begin() + 1);
    seg = vector<Node>(n * 4 + 10);
    build(1, 1, n);
  }

  void change(int pos, V val) {
    a[pos] = val;
    change(1, 1, n, pos, val);
  }
  void modify(int ql, int qr, Tag t) { modify(1, 1, n, ql, qr, t); }
  Info query(int ql, int qr) { return query(1, 1, n, ql, qr); }
  void add(int pos, V val) { modify(pos, pos, {val}); }

  static pair<int, int> child(int id) { return {id * 2, id * 2 + 1}; }

  void update(int id) {
    auto [lc, rc] = child(id);
    seg[id].info = seg[lc].info + seg[rc].info;
  }

  void build(int id, int l, int r) {
    if (l == r) {
      seg[id] = Node(a[l]);
      return;
    }

    int mid = (l + r) / 2;
    auto [lc, rc] = child(id);
    build(lc, l, mid);
    build(rc, mid + 1, r);
    update(id);
  }

  void push_down(int id) {
    Tag& t = seg[id].tag;
    if (t.empty()) return;

    auto [lc, rc] = child(id);
    set_tag(lc, t);
    set_tag(rc, t);
    t.clear();
  }

  void set_tag(int id, Tag t) {
    seg[id].info = seg[id].info + t;
    seg[id].tag = seg[id].tag + t;
  }

  void change(int id, int l, int r, int pos, V val) {
    if (l == r) {
      seg[id] = Node(val);
      return;
    }

    push_down(id);
    int mid = (l + r) / 2;
    auto [lc, rc] = child(id);
    if (pos <= mid)
      change(lc, l, mid, pos, val);
    else
      change(rc, mid + 1, r, pos, val);
    update(id);
  }

  void modify(int id, int l, int r, int ql, int qr, Tag t) {
    if (l >= ql && r <= qr) {
      set_tag(id, t);
      return;
    }
    int mid = (l + r) / 2;
    auto [lc, rc] = child(id);
    push_down(id);
    if (qr <= mid)
      modify(lc, l, mid, ql, qr, t);
    else if (ql > mid)
      modify(rc, mid + 1, r, ql, qr, t);
    else {
      modify(lc, l, mid, ql, mid, t);
      modify(rc, mid + 1, r, mid + 1, qr, t);
    }
    update(id);
  }

  Info query(int id, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) {
      return seg[id].info;
    }
    int mid = (l + r) / 2;
    auto [lc, rc] = child(id);
    push_down(id);
    if (qr <= mid)
      return query(lc, l, mid, ql, qr);
    else if (ql > mid)
      return query(rc, mid + 1, r, ql, qr);
    else
      return query(lc, l, mid, ql, mid) + query(rc, mid + 1, r, mid + 1, qr);
  }
};

#endif

void solve() {
  int n, q;
  cin >> n >> q;
  VI a(n);
  for (auto& x : a) cin >> x;

  struct Ops {
    int op, l, r;
  };
  vector<Ops> ops(q);
  For(i, 0, q) { cin >> ops[i].op >> ops[i].l >> ops[i].r; }
  int k;
  cin >> k;

  auto check = [&](int val) -> bool {
    VI a1(n);
    For(i, 0, n) { a1[i] = (a[i] >= val); }
    SegmentTree<int> tree(a1);
    for (auto [op, l, r] : ops) {
      int cnt = tree.query(l, r).val, len = r - l + 1;
      if (len == cnt || cnt == 0) continue;

      if (op == 0) {
        tree.modify(l, r - cnt, {0});
        tree.modify(r - cnt + 1, r, {1});
      } else {
        tree.modify(l, l + cnt - 1, {1});
        tree.modify(l + cnt, r, {0});
      }
    }
    return tree.query(k, k).val >= 1;
  };

  int l = 1, r = n, mid;
  while (l < r) {
    mid = (l + r + 1) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << '\n';
}
