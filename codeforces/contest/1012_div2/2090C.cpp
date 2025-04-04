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
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
}

template <class T>
ostream &operator<<=(ostream &os, const vector<T> &a) {
  int n = int(a.size());
  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i == n - 1];
  }
  return os;
}

template <class T>
istream &operator>>=(istream &is, vector<T> &a) {
  for (auto &x : a) is >> x;
  return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &a) {
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

// int128 input and output
#ifdef _DEBUG
using lll = __int128;

istream &operator>>(istream &is, lll &v) {
  string s;
  is >> s;
  v = 0;
  for (auto &it : s)
    if (isdigit(it)) v = v * 10 + it - '0';
  if (s[0] == '-') v *= -1;
  return is;
}

ostream &operator<<(ostream &os, const lll &v) {
  if (v == 0) return (os << "0");
  lll num = v;
  if (v < 0) os << '-', num = -num;
  string s;
  for (; num > 0; num /= 10) s.pb((char)(num % 10) + '0');
  reverse(all(s));
  return (os << s);
}
#endif
// end of int128

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

struct node {
  int bx, by, x, y, d;

  node(int _bx, int _by)
      : bx(_bx), by(_by), x(3 * bx + 1), y(3 * by + 1), d(x + y) {}
  node(int _bx, int _by, int _x, int _y)
      : bx(_bx), by(_by), x(_x), y(_y), d(x + y) {}
  node(int _bx, int _by, int _x, int _y, int d_)
      : bx(_bx), by(_by), x(_x), y(_y), d(d_) {}

  bool operator>(const node &rh) const {
    if (d != rh.d) return d > rh.d;
    return PII(x, y) > PII(rh.x, rh.y);
  }
};

void solve() {
  int n;
  cin >> n;

  pqg<node> q1, q2;
  set<PII> vis;

  auto extend = [&](const node &nd) {
    int x = nd.x, y = nd.y;
    q2.push(node(nd.bx, nd.by, x + 1, y));
    q2.push(node(nd.bx, nd.by, x, y + 1));
    q2.push(node(nd.bx, nd.by, x + 1, y + 1, x + y + 4));
  };
  auto get_neighbor = [&](int bx, int by) {
    if (!has(vis, PII(bx, by))) {
      vis.insert(PII(bx, by));
      auto tmp = node(bx, by);
      q1.push(tmp);
      extend(tmp);
    }
  };

  auto tmp = node(0, 0);
  q1.push(tmp);
  extend(tmp);

  For(i, 0, n) {
    int t;
    cin >> t;

    if (t == 0) {
      auto nd = q1.top();
      cout << nd.x << ' ' << nd.y << '\n';
      q1.pop();
      int bx = nd.bx, by = nd.by;
      get_neighbor(bx + 1, by);
      get_neighbor(bx, by + 1);
    } else {
      if (q2.empty()) {
        auto nd = q1.top();
        cout << nd.x << ' ' << nd.y << '\n';
        q1.pop();
        int bx = nd.bx, by = nd.by;
        get_neighbor(bx + 1, by);
        get_neighbor(bx, by + 1);
      } else {
        auto nd1 = q1.top();
        auto nd2 = q2.top();
        if (nd1 > nd2) {
          auto nd = q2.top();
          cout << nd.x << ' ' << nd.y << '\n';
          q2.pop();
        } else {
          auto nd = q1.top();
          cout << nd.x << ' ' << nd.y << '\n';
          q1.pop();
          int bx = nd.bx, by = nd.by;
          get_neighbor(bx + 1, by);
          get_neighbor(bx, by + 1);
        }
      }
    }
  }
}

int main(void) {
#ifdef _DEBUG
#ifndef _CPH
  freopen("input.txt", "r", stdin);
#endif
#endif

  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

#ifdef _DEBUG
  auto _start_ts = std::chrono::high_resolution_clock::now();
#endif

  int T = 1;
  cin >> T;

  while (T--) {
    solve();
  }

#ifdef _DEBUG
  auto _end_ts = std::chrono::high_resolution_clock::now();
  std::cerr << "Execution time: "
            << std::chrono::duration<double>(_end_ts - _start_ts).count()
            << " seconds." << std::endl;
#endif

  return 0;
}
