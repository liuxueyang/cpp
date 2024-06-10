// Date: Mon Jun 10 20:27:54 2024

#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
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
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998244353;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

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

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

#ifdef _DEBUG
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
#define dbg(x...)                                                              \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";    \
  _print(x);                                                                   \
  cerr << "\e[39m" << endl;
#else
#define debug1
#define debug2
#define debug3
#define dbg(x...)
#endif

const int N = 200100;

int a[N], n;

struct info {
  int minv;
  int cnt;
};

info operator+(const info &lhs, const info &rhs) {
  info res;
  res.minv = min(lhs.minv, rhs.minv);

  if (lhs.minv == rhs.minv)
    res.cnt = lhs.cnt + rhs.cnt;
  else if (lhs.minv < rhs.minv)
    res.cnt = lhs.cnt;
  else
    res.cnt = rhs.cnt;

  return res;
}

struct node {
  info val;
} seg[N * 4];

void update(int id) { seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val; }

void build(int id, int l, int r) {
  if (l == r) {
    seg[id] = {a[l], 1};
  } else {
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    update(id);
  }
}

// point change, id: [l, r], a[pos] = val
void change(int id, int l, int r, int pos, int val) {
  if (l == r) {
    seg[id] = {val, 1};
  } else {
    int mid = (l + r) / 2;
    if (pos <= mid)
      change(id * 2, l, mid, pos, val);
    else
      change(id * 2 + 1, mid + 1, r, pos, val);
    update(id);
  }
}

// [ql, qr] is the query
info query(int id, int l, int r, int ql, int qr) {
  if (l == ql && r == qr)
    return seg[id].val;

  int mid = (l + r) / 2;
  if (qr <= mid)
    return query(id * 2, l, mid, ql, qr);
  if (ql > mid)
    return query(id * 2 + 1, mid + 1, r, ql, qr);
  return query(id * 2, l, mid, ql, mid) +
         query(id * 2 + 1, mid + 1, r, mid + 1, qr);
}

void solve() {
  int q;
  cin >> n >> q;

  For1(i, 1, n) { cin >> a[i]; }

  build(1, 1, n);

  while (q--) {
    int op, x, y;
    cin >> op;

    if (op == 1) {
      cin >> x >> y;
      change(1, 1, n, x, y);
    } else {
      cin >> x >> y;
      info res = query(1, 1, n, x, y);
      cout << res.minv << ' ' << res.cnt << '\n';
    }
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("segment_tree.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 1;

  while (T--) {
    solve();
  }

  return 0;
}
