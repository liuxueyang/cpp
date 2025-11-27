#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
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

template <class T> ostream &operator<<(ostream &os, const vector<T> &a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
}

template <class T> ostream &operator<<=(ostream &os, const vector<T> &a) {
  int n = int(a.size());
  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i == n - 1];
  }
  return os;
}

template <class T> istream &operator>>=(istream &is, vector<T> &a) {
  for (auto &x : a)
    is >> x;
  return is;
}

template <class T> istream &operator>>(istream &is, vector<T> &a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    is >> a[i];
  }
  return is;
}

template <typename ForwardIterator>
void Inputr(ForwardIterator begin, ForwardIterator end) {
  ForwardIterator it = begin;
  while (it != end) {
    cin >> *it;
    it++;
  }
}

template <typename ForwardIterator>
void Outputr(ForwardIterator begin, ForwardIterator end) {
  ForwardIterator it = begin;
  while (it != end) {
    if (it != begin)
      cout << ' ';
    cout << *it;
    it++;
  }
  NL;
}

template <typename T, typename ForwardIterator>
void Outputr1(ForwardIterator begin, ForwardIterator end) {
  copy(begin, end, ostream_iterator<T>(cout, " "));
  NL;
}

template <typename T>
inline void PRINT_ELEMENTS(const T &coll, const string &optstr = "") {
  cout << optstr;
  copy(coll.begin(), coll.end(),
       ostream_iterator<typename T::value_type>(cout, " "));
  cout << '\n';
}

template <typename T>
inline void INPUT_ELEMENTS(T &coll, const int n, const int start = 0) {
  if (start)
    coll.push_back(typename T::value_type{});
  copy_n(istream_iterator<typename T::value_type>(cin), n, back_inserter(coll));
}

// base function
void tprintf(const char *format) { cout << format; }

template <typename T, typename... Targs>
void tprintf(const char *format, T value,
             Targs... Fargs) // recursive variadic function
{
  for (; *format != '\0'; format++) {
    if (*format == '%') {
      cout << value;
      tprintf(format + 1, Fargs...); // recursive call
      return;
    }
    cout << *format;
  }
}

// int128 input and output
// #ifdef MYDEBUG
// using lll = __int128;
//
// istream& operator>>(istream& is, lll& v) {
//  string s;
//  is >> s;
//  v = 0;
//  for (auto& it : s)
//    if (isdigit(it)) v = v * 10 + it - '0';
//  if (s[0] == '-') v *= -1;
//  return is;
//}
//
// ostream& operator<<(ostream& os, const lll& v) {
//  if (v == 0) return (os << "0");
//  lll num = v;
//  if (v < 0) os << '-', num = -num;
//  string s;
//  for (; num > 0; num /= 10) s.pb((char)(num % 10) + '0');
//  reverse(all(s));
//  return (os << s);
//}
// #endif
// end of int128

#ifdef MYDEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

void Init();
void solve();

int main(void) {
#if defined(MY_INPUT)
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

struct tag {
  ll a, b;

  tag() : a(1), b(0) {}
  tag(ll a_, ll b_) : a(a_), b(b_) {}

  tag operator+(const tag &rh) const {
    return tag(a * rh.a, (rh.a * b) + rh.b);
  }
};

struct info {
  ll sum;
  int len;

  info() : sum(0), len(0) {}
  info(ll sum_, int len_) : sum(sum_), len(len_) {}
  info operator+(const info &rh) const {
    return info(sum + rh.sum, len + rh.len);
  }
  info operator+(const tag &t) const {
    return info(t.a * sum + t.b * len, len);
  }
};

struct SegmentTree {
  struct Node {
    info val;
    tag t;
  };

  int n;
  VL a;
  vector<Node> seg;

  SegmentTree(int n_, VI &a_)
      : n(n_), a(all(a_)), seg(vector<Node>(n * 4 + 10)) {}

  void update(int id) {
    int left = id * 2, right = left + 1;
    seg[id].val = seg[left].val + seg[right].val;
  }

  void set_tag(int id, tag t) {
    seg[id].t = seg[id].t + t;
    seg[id].val = seg[id].val + t;
  }

  void push_down(int id) {
    int left = id * 2, right = left + 1;
    tag &t = seg[id].t;
    if (t.a != 1 || t.b != 0) {
      set_tag(left, t), set_tag(right, t);
      t.a = 1, t.b = 0;
    }
  }

  void build(int id, int l, int r) {
    if (l == r) {
      seg[id].val = {a[l], 1};
      seg[id].t = {1, 0};
      return;
    }

    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    build(left, l, mid);
    build(right, mid + 1, r);
    update(id);
  }

  void modify(int id, int l, int r, int ql, int qr, tag t) {
    if (l == ql && r == qr) {
      set_tag(id, t);
      return;
    }

    push_down(id);
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (qr <= mid)
      modify(left, l, mid, ql, qr, t);
    else if (ql > mid)
      modify(right, mid + 1, r, ql, qr, t);
    else {
      modify(left, l, mid, ql, mid, t);
      modify(right, mid + 1, r, mid + 1, qr, t);
    }
    update(id);
  }

  info query(int id, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) {
      return seg[id].val;
    }

    push_down(id);
    int mid = (l + r) / 2, left = id * 2, right = left + 1;
    if (qr <= mid)
      return query(left, l, mid, ql, qr);
    else if (ql > mid)
      return query(right, mid + 1, r, ql, qr);
    else
      return query(left, l, mid, ql, mid) +
             query(right, mid + 1, r, mid + 1, qr);
  }
};

void Init() {}

void solve() {
  int n, q;
  cin >> n >> q;

  VI a(n + 10, 1);
  SegmentTree tree(n, a);
  tree.build(1, 1, n);

  while (q--) {
    string op;
    cin >> op;
    int l, r;
    if (op == "SET_READ") {
      cin >> l >> r;
      tree.modify(1, 1, n, l, r, tag(0, 0));
    } else if (op == "SET_UNREAD") {
      cin >> l >> r;
      tree.modify(1, 1, n, l, r, tag(0, 1));
    } else if (op == "FIRST_UNREAD_SINCE") {
      int x;
      cin >> x;
      int l = x, r = n, mid, sum = tree.query(1, 1, n, x, n).sum;

      if (sum == 0) {
        cout << "None\n";
        continue;
      }

      auto check = [&](int left) {
        auto in = tree.query(1, 1, n, left, n);
        return in.sum >= sum;
      };

      while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid))
          l = mid;
        else
          r = mid - 1;
      }

      cout << l << '\n';
    }
  }
}
