//  线段树2
//  Created on 2025/12/11.

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
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

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

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <class T> ostream &operator<<=(ostream &os, const vector<T> &a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &a) {
  int n = int(a.size());
  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i == n - 1];
  }
  return os;
}

template <class T> istream &operator>>(istream &is, vector<T> &a) {
  for (auto &x : a)
    is >> x;
  return is;
}

template <class T> istream &operator>>=(istream &is, vector<T> &a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    is >> a[i];
  }
  return is;
}

#ifdef MYDEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

void Init();
void solve();

int main(void) {
#ifdef USE_INPUT_FILE
  freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#if defined(MYDEBUG)
  auto _start_ts = std::chrono::high_resolution_clock::now();
#endif

  int T = 1;
  // cin >> T;
  while (T--) {
    Init();
    solve();
  }

#if defined(MYDEBUG)
  auto _end_ts = std::chrono::high_resolution_clock::now();
  std::cerr << "Execution time: "
            << std::chrono::duration<double>(_end_ts - _start_ts).count()
            << " seconds." << std::endl;
#endif

  return 0;
}

#pragma mark - SOLVE

const int N = 200100;

struct Info {
  ll sum, pre_sum, suf_sum, mss;
  
  Info operator+(const Info &rh) const {
    Info res;
    res.sum = sum + rh.sum;
    res.pre_sum = max(pre_sum, sum + rh.pre_sum);
    res.suf_sum = max(rh.suf_sum, rh.sum + suf_sum);
    res.mss = max({mss, rh.mss, suf_sum + rh.pre_sum});
    return res;
  }
};

struct Node {
  Info info;
};

int n, q, b[N];
Node a[N * 4];

void Init() {}

PII children(int id) {
  return {id * 2, id * 2 + 1};
}

void update(int id) {
  auto [lc, rc] = children(id);
  a[id].info = a[lc].info + a[rc].info;
}

void build(int id, int l, int r) {
  if (l == r) {
    a[id] = {b[l], b[l], b[l], b[l]};
    return;
  }
  int mid = (l + r) / 2;
  auto [lc, rc] = children(id);
  build(lc, l, mid);
  build(rc, mid + 1, r);
  update(id);
}

void change(int id, int l, int r, int pos, int val) {
  if (l == r) {
    a[id] = {val, val, val, val};
    return;
  }
  int mid = (l + r) / 2;
  auto [lc, rc] = children(id);
  if (pos <= mid) change(lc, l, mid, pos, val);
  else change(rc, mid + 1, r, pos, val);
  update(id);
}

Info query(int id, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) {
    return a[id].info;
  }
  int mid = (l + r) / 2;
  auto [lc, rc] = children(id);
  if (qr <= mid) return query(lc, l, mid, ql, qr);
  else if (ql > mid) return query(rc, mid + 1, r, ql, qr);
  else return query(lc, l, mid, ql, mid) + query(rc, mid + 1, r, mid + 1, qr);
}

void solve() {
  cin >> n >> q;
  For1(i, 1, n) cin >> b[i];
  
  build(1, 1, n);
  while (q--) {
    int op, x, d, l, r;
    cin >> op;
    if (op == 1) {
      cin >> x >> d;
      change(1, 1, n, x, d);
    } else {
      cin >> l >> r;
      auto res = query(1, 1, n, l, r);
      cout << res.mss << '\n';
    }
  }
}
