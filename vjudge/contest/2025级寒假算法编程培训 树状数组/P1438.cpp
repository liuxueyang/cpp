// Problem: P1438 无聊的数列
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1438
// Memory Limit: 128 MB
// Time Limit: 1000 ms
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
#define NL cout << '\n';

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
  // cin >> T;
  while (T--) {
    Init();
    solve();
  }

  return 0;
}

const int N = 100100;
int n, m, a[N], b[N];

struct Tag {
  int val;

  bool empty() const { return val == 0; }

  void clear() { val = 0; }

  Tag operator+(const Tag& rh) const { return {val + rh.val}; }
};

struct Info {
  ll sum;
  int len;

  Info operator+(const Info& rh) const { return {sum + rh.sum, len + rh.len}; }
  Info operator+(const Tag& t) const { return {sum + 1LL * len * t.val, len}; }
};

PII child(int id) { return {id * 2, id * 2 + 1}; }

struct Node {
  Info info;
  Tag tag;
};

struct SegmentTree {
  Node seg[N * 4];

  SegmentTree() { For(i, 0, N * 4) seg[i] = {}; }

  void set_tag(int id, Tag t) {
    seg[id].info = seg[id].info + t;
    seg[id].tag = seg[id].tag + t;
  }

  void update(int id) {
    auto [lc, rc] = child(id);
    seg[id].info = seg[lc].info + seg[rc].info;
  }

  void push_down(int id) {
    Tag t = seg[id].tag;
    if (t.empty()) return;

    seg[id].tag.clear();
    auto [lc, rc] = child(id);
    set_tag(lc, t);
    set_tag(rc, t);
  }

  void build(int id, int l, int r, int* a) {
    if (l == r) {
      seg[id].info = {a[l], 1};
      return;
    }

    int mid = (l + r) / 2;
    auto [lc, rc] = child(id);
    build(lc, l, mid, a);
    build(rc, mid + 1, r, a);
    update(id);
  }

  void modify(int id, int l, int r, int ql, int qr, int val) {
    if (ql <= l && qr >= r) {
      set_tag(id, {val});
      return;
    }

    int mid = (l + r) / 2;
    auto [lc, rc] = child(id);
    push_down(id);
    if (qr <= mid)
      modify(lc, l, mid, ql, qr, val);
    else if (ql > mid)
      modify(rc, mid + 1, r, ql, qr, val);
    else {
      modify(lc, l, mid, ql, mid, val);
      modify(rc, mid + 1, r, mid + 1, qr, val);
    }
    update(id);
  }

  Info query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
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

void Init() {}

SegmentTree tree1, tree2;

void solve() {
  cin >> n >> m;
  For1(i, 1, n) { cin >> a[i]; }

  tree1.build(1, 1, n, a);
  tree2.build(1, 1, n, b);
  while (m--) {
    int op, l, r, K, D, p;
    cin >> op;
    if (op == 1) {
      cin >> l >> r >> K >> D;
      tree1.modify(1, 1, n, l, r, K);
      if (l < r) {
        tree2.modify(1, 1, n, l + 1, r, D);
        if (r + 1 <= n) tree2.modify(1, 1, n, r + 1, r + 1, 1LL * -(r - l) * D);
      }
    } else {
      cin >> p;
      ll x = tree1.query(1, 1, n, p, p).sum, y = tree2.query(1, 1, n, 1, p).sum;
      cout << x + y << '\n';
    }
  }
}
