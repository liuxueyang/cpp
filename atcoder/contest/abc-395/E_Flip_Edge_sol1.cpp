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
  ll d;
  int ver, odd;
  bool operator>(const node &rh) const {
    if (d != rh.d)
      return d > rh.d;
    else if (odd != rh.odd)
      return odd > rh.odd;
    return ver > rh.ver;
  }
};

void solve() {
  int n, m, X;
  cin >> n >> m >> X;

  vector<vector<PII>> g(n + 1);
  For(i, 0, m) {
    int u, v;
    cin >> u >> v;
    g[u].pb({v, 1});
    g[v].pb({u, -1});
  }

  VVL dis(n + 1, VL(2, INFL));
  set<PII> st;

  dis[1][0] = 0;
  dis[1][1] = X;
  priority_queue<node, vector<node>, greater<node>> q;
  q.push({0, 1, 0});
  q.push({X, 1, 1});

  while (nemp(q)) {
    auto [base, ver, odd] = q.top();
    q.pop();

    if (has(st, PII(ver, odd))) continue;
    st.insert(PII{ver, odd});

    for (auto &[v, w] : g[ver]) {
      if (w == -1) {
        if (odd & 1) {
          if (ckmin(dis[v][odd], (ll)base + 1)) {
            q.push(node{dis[v][odd], v, odd});
          }
        } else {
          if (ckmin(dis[v][odd ^ 1], (ll)base + X + 1)) {
            q.push(node{dis[v][odd ^ 1], v, 1 ^ odd});
          }
        }
      } else {
        if (odd & 1) {
          if (ckmin(dis[v][odd ^ 1], (ll)base + X + 1)) {
            q.push(node{dis[v][odd ^ 1], v, 1 ^ odd});
          }
        } else {
          if (ckmin(dis[v][odd], (ll)base + 1)) {
            q.push(node{dis[v][odd], v, odd});
          }
        }
      }
    }
  }

  cout << min(dis[n][0], dis[n][1]) << '\n';
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
  // cin >> T;

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
