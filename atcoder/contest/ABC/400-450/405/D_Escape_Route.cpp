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

void solve1() {
  int n, m;
  cin >> n >> m;

  vector<string> g(n + 1);
  For1(i, 1, n) {
    string s;
    cin >> s;
    g[i] = " " + s;
  }

  VVI d(n + 10, VI(m + 10, INF));
  VVB vis(n + 10, VB(m + 10));

  priority_queue<pair<int, PII>, vector<pair<int, PII>>,
                 greater<pair<int, PII>>>
      q;

  For1(i, 1, n) {
    For1(j, 1, m) {
      if (g[i][j] == 'E') {
        d[i][j] = 0;
        q.push({0, PII(i, j)});
      }
    }
  }

  auto check = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };

  while (nemp(q)) {
    auto [base, ver] = q.top();
    q.pop();
    auto [x, y] = ver;

    if (vis[x][y]) continue;
    vis[x][y] = true;

    For(i, 0, 4) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1) && g[x1][y1] == '.' && ckmin(d[x1][y1], base + 1)) {
        q.push({d[x1][y1], PII(x1, y1)});
      }
    }
  }

  string dirc = "><v^";

  For1(i, 1, n) {
    For1(j, 1, m) {
      if (g[i][j] == '.') {
        For(k, 0, 4) {
          int i1 = i + dir[k][0], j1 = j + dir[k][1];
          if (check(i1, j1) && g[i1][j1] != '#' && d[i1][j1] + 1 == d[i][j]) {
            cout << dirc[k];
            break;
          }
        }
      } else
        cout << g[i][j];
    }
    cout << '\n';
  }
}

void solve();

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

void solve() {
  int n, m;
  cin >> n >> m;

  queue<PII> q;
  vector<string> a(n + 1);

  For1(i, 1, n) {
    string s;
    cin >> s;
    a[i] = " " + s;

    For1(j, 1, m) {
      if (a[i][j] == 'E') {
        q.push(PII(i, j));
      }
    }
  }

  string dirc = "<>^v";

  while (nemp(q)) {
    auto [x, y] = q.front();
    q.pop();

    int x1, y1;
    For(i, 0, 4) {
      x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && a[x1][y1] == '.') {
        a[x1][y1] = dirc[i];
        q.push(PII(x1, y1));
      }
    }
  }

  For1(i, 1, n) { cout << a[i].substr(1) << '\n'; }
}
