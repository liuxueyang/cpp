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

int n, m;
vector<string> g;
PII s1, s2;

struct node {
  int x, y, d, di;
  bool operator<(const node &rh) const { return d < rh.d; }
  bool operator>(const node &rh) const { return d > rh.d; }
};

void solve() {
  int n, m;
  cin >> n >> m;

  VS a(n + 10);
  For(i, 0, n) cin >> a[i];

  PII src{}, dst{};
  For(i, 0, n) {
    For(j, 0, m) {
      if (a[i][j] == 'S') {
        src = {i, j};
      } else if (a[i][j] == 'G')
        dst = {i, j};
    }
  }

  vector<VVI> d(n + 10, VVI(m + 10, VI(2, INF)));
  queue<node> q;
  q.push({src.f1, src.f2, 0, 0});
  q.push({src.f1, src.f2, 0, 1});
  d[src.f1][src.f2][0] = d[src.f1][src.f2][1] = 0;

  auto check = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; };

  while (nemp(q)) {
    auto [x, y, dis, orid] = q.front();
    q.pop();

    int x1{}, y1{};
    if (orid == 0) {
      For(i, 2, 4) {
        x1 = x + dir[i][0];
        y1 = y + dir[i][1];
        if (check(x1, y1) && a[x1][y1] != '#') {
          if (ckmin(d[x1][y1][orid ^ 1], dis + 1))
            q.push({x1, y1, dis + 1, orid ^ 1});
        }
      }
    } else {
      For(i, 0, 2) {
        x1 = x + dir[i][0];
        y1 = y + dir[i][1];
        if (check(x1, y1) && a[x1][y1] != '#') {
          if (ckmin(d[x1][y1][orid ^ 1], dis + 1))
            q.push({x1, y1, dis + 1, orid ^ 1});
        }
      }
    }
  }

  int ans = min(d[dst.f1][dst.f2][0], d[dst.f1][dst.f2][1]);
  cout << (ans >= INF ? -1 : ans) << '\n';
}

void solve1() {
  cin >> n >> m;
  string tmp;
  g = VS(n + 10);

  For1(i, 1, n) {
    cin >> tmp;
    tmp = " " + tmp;
    g[i] = tmp;
    For1(j, 1, m) {
      if (g[i][j] == 'S') s1 = {i, j};
      if (g[i][j] == 'G') s2 = {i, j};
    }
  }
  auto check = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };

  VVI d1(n + 10, VI(m + 10, INF)), d2(d1);
  VVB vis1(n + 10, VB(m + 10)), vis2(vis1);
  auto [x1, y1] = s1;
  d1[x1][y1] = 0;
  d2[x1][y1] = 0;
  pqg<node> q;
  q.push({x1, y1, 0, 0});
  q.push({x1, y1, 0, 1});
  while (nemp(q)) {
    auto [x, y, base, di] = q.top();
    q.pop();
    if (di == 0) {
      if (vis1[x][y]) continue;
      vis1[x][y] = true;
      For(j, 2, 4) {
        int x2 = x + dir[j][0], y2 = y + dir[j][1];
        if (check(x2, y2) && (g[x2][y2] == '.' || g[x2][y2] == 'G')) {
          if (ckmin(d2[x2][y2], base + 1)) {
            q.push({x2, y2, d2[x2][y2], 1});
          }
        }
      }
    } else {
      if (vis2[x][y]) continue;
      vis2[x][y] = true;
      For(j, 0, 2) {
        int x2 = x + dir[j][0], y2 = y + dir[j][1];
        if (check(x2, y2) && (g[x2][y2] == '.' || g[x2][y2] == 'G')) {
          if (ckmin(d1[x2][y2], base + 1)) {
            q.push({x2, y2, d1[x2][y2], 0});
          }
        }
      }
    }
  }

  int ans = min(d1[s2.f1][s2.f2], d2[s2.f1][s2.f2]);
  if (ans != INF)
    cout << ans << '\n';
  else
    cout << "-1\n";
}

int main(void) {
#ifdef _DEBUG
  freopen("../input.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

  int T = 1;
  // cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}
