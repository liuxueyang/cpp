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
ostream& operator<<(ostream& os, const vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
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

template <class T>
istream& operator>>(istream& is, vector<T>& a) {
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
    if (it != begin) cout << ' ';
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

// base function
void tprintf(const char* format) { cout << format; }

template <typename T, typename... Targs>
void tprintf(const char* format, T value,
             Targs... Fargs)  // recursive variadic function
{
  for (; *format != '\0'; format++) {
    if (*format == '%') {
      cout << value;
      tprintf(format + 1, Fargs...);  // recursive call
      return;
    }
    cout << *format;
  }
}

// int128 input and output
// #ifdef _DEBUG
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

#ifdef _DEBUG
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
#if defined(_DEBUG) && !defined(_CPH)
  freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

#ifdef _DEBUG
  auto _start_ts = std::chrono::high_resolution_clock::now();
#endif

  Init();
  solve();

#ifdef _DEBUG
  auto _end_ts = std::chrono::high_resolution_clock::now();
  std::cerr << "Execution time: "
            << std::chrono::duration<double>(_end_ts - _start_ts).count()
            << " seconds." << std::endl;
#endif

  return 0;
}

void Init() {}

const int N = 500010;

int n, q;
string s;

struct info {
  int prefix, postfix, mx, len;
  char chl, chr;

  info() : prefix(0), postfix(0), mx(0), len(0), chl(' '), chr(' ') {}
  info(int prefix_, int postfix_, int mx_, int len_, char chl_, char chr_)
      : prefix(prefix_),
        postfix(postfix_),
        mx(mx_),
        len(len_),
        chl(chl_),
        chr(chr_) {}

  info operator+(const info& rh) {
    info res;

    res.len = len + rh.len;
    res.chl = chl;
    res.chr = rh.chr;

    res.prefix = prefix;
    if (prefix == len && chr == rh.chl) {
      res.prefix = prefix + rh.prefix;
    }

    res.postfix = rh.postfix;
    if (rh.postfix == rh.len && chr == rh.chl) {
      res.postfix = rh.postfix + postfix;
    }

    res.mx = max({mx, rh.mx, res.prefix, res.postfix});
    if (chr == rh.chl) {
      res.mx = max(res.mx, postfix + rh.prefix);
    }

    return res;
  }
};

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
    seg[id].v = {1, 1, 1, 1, s[l], s[l]};
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
  int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
  if (qr <= mid)
    return query(id1, l, mid, ql, qr);
  else if (ql > mid)
    return query(id2, mid + 1, r, ql, qr);
  else {
    return query(id1, l, mid, ql, mid) + query(id2, mid + 1, r, mid + 1, qr);
  }
}

void change(int id, int l, int r, int p, char v) {
  if (l == r) {
    seg[id].v = {1, 1, 1, 1, v, v};
  } else {
    int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
    if (p <= mid)
      change(id1, l, mid, p, v);
    else
      change(id2, mid + 1, r, p, v);

    update(id);
  }
}

void solve() {
  while (cin >> n >> q >> s) {
    int op;
    s = " " + s;

    build(1, 1, n);

    while (q--) {
      cin >> op;
      if (op == 1) {
        int i;
        string s0;
        cin >> i >> s0;
        s[i] = s0[0];
        change(1, 1, n, i, s0[0]);
      } else {
        int l, r;
        cin >> l >> r;
        auto res = query(1, 1, n, l, r);
        cout << res.mx << '\n';
      }
    }
  }
}
