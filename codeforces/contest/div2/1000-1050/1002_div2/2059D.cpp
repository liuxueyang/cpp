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

template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}

template <typename t>
istream &operator>>(istream &in, vector<t> &vec) {
  for (t &x : vec) in >> x;
  return in;
}

template <typename t>
ostream &operator<<(ostream &out, vector<t> &vec) {
  int n = SZ(vec);
  For(i, 0, n) {
    out << vec[i];
    if (i < n - 1) out << ' ';
  }
  return out;
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

struct point {
  int x, y;
  ll d;

  bool operator>(const point &rh) const { return d > rh.d; }
  bool operator<(const point &rh) const {
    if (x != rh.x)
      return x < rh.x;
    else
      return y < rh.y;
  }
};

void solve() {
  int n, s1, s2;
  cin >> n >> s1 >> s2;

  int m1, m2;
  cin >> m1;
  VVI g1(n + 10), g2(n + 10);
  set<PII> edges1;
  For(i, 0, m1) {
    int u, v;
    cin >> u >> v;
    g1[u].pb(v), g1[v].pb(u);
    if (u > v)
      edges1.insert({v, u});
    else
      edges1.insert({u, v});
  }
  For1(i, 1, n) sort(all(g1[i]));

  cin >> m2;
  VB s(n + 10);
  For(i, 0, m2) {
    int u, v;
    cin >> u >> v;
    g2[u].pb(v), g2[v].pb(u);

    if (u > v) {
      if (has(edges1, PII(v, u))) s[v] = s[u] = true;
    } else {
      if (has(edges1, PII(u, v))) s[v] = s[u] = true;
    }
  }
  For1(i, 1, n) sort(all(g2[i]));

  pqg<point> q;
  q.push({s1, s2, 0LL});
  VVL dis(n + 10, VL(n + 10, INFL));
  dis[s1][s2] = 0;
  VVB st(n + 10, VB(n + 10));

  while (nemp(q)) {
    auto [x, y, d] = q.top();
    q.pop();

    if (st[x][y]) continue;
    st[x][y] = true;

    for (auto x1 : g1[x]) {
      for (auto y1 : g2[y]) {
        ll tmp = d + abs(x1 - y1);
        if (ckmin(dis[x1][y1], tmp)) {
          q.push({x1, y1, tmp});
        }
      }
    }
  }

  ll ans{INFL};
  For1(i, 1, n) {
    if (s[i]) {
      ckmin(ans, dis[i][i]);
    }
  }
  if (ans == INFL) ans = -1;
  cout << ans << '\n';
}

int main(void) {
#ifdef _DEBUG
#ifndef _CPH
  freopen("../input.txt", "r", stdin);
#endif
#endif

  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

  int T = 1;
  cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}
