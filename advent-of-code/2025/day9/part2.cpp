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
  // freopen("input1.txt", "r", stdin);
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

void Init() {}

VVI g;
int n, m;

bool check(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

void dfs(int x, int y) {
  g[x][y] = 2;
  For(i, 0, 4) {
    int x1 = x + dir[i][0], y1 = y + dir[i][1];
    if (check(x1, y1) && !g[x1][y1]) {
      dfs(x1, y1);
    }
  }
}

void solve() {
  vector<PII> a;
  string s;

  while (cin >> s) {
    int x = 0, y = 0;
    bool flg = false;

    for (auto c : s) {
      if (c == ',') {
        flg = true;
      } else if (flg) {
        y = y * 10 + (c - '0');
      } else {
        x = x * 10 + (c - '0');
      }
    }
    x++, y++;
    swap(x, y);

    a.push_back({x, y});
  }

  VI idxes;
  for (auto [x, y] : a) {
    idxes.pb(x);
    idxes.pb(y);
  }
  sort(all(idxes));
  idxes.resize(distance(idxes.begin(), unique(all(idxes))));
  auto get_id = [&](int x) -> int {
    return distance(idxes.begin(), lower_bound(all(idxes), x)) + 1;
  };
  auto get_ori = [&](int id) -> int { return idxes[id - 1]; };

  vector<PII> b = a;
  a = {};
  n = 0, m = 0;

  for (auto [x, y] : b) {
    int x1 = get_id(x), y1 = get_id(y);
    a.pb({x1, y1});
    ckmax(n, x1);
    ckmax(m, y1);
  }

  g = VVI(n + 10, VI(m + 10));
  int len = SZ(a);
  For(i, 0, len) {
    int j = (i + 1) % len;
    auto p = a[i], q = a[j];
    if (p > q)
      swap(p, q);
    auto [x1, y1] = p;
    auto [x2, y2] = q;
    For1(r1, x1, x2) For1(c1, y1, y2) g[r1][c1] = 1;
  }
  For1(i, 1, n) {
    For1(j, 1, m) {
      if (i == 1 || i == n || j == 1 || j == m) {
        if (!g[i][j])
          dfs(i, j);
      }
    }
  }

  For1(i, 1, n) {
    For1(j, 1, m) {
      if (!g[i][j])
        g[i][j] = 1;
      else if (g[i][j] == 2)
        g[i][j] = 0;
    }
  }

  VVI p(n + 10, VI(m + 10));
  For1(i, 1, n) { For1(j, 1, m) p[i][j] = p[i][j - 1] + g[i][j]; }
  For1(j, 1, m) For1(i, 1, n) p[i][j] += p[i - 1][j];

  ll ans = 0;
  For(i, 0, len) {
    For(j, i + 1, len) {
      auto pt1 = a[i], pt2 = a[j];
      if (pt1 > pt2)
        swap(pt1, pt2);

      auto [x1, y1] = pt1;
      auto [x2, y2] = pt2;
      if (y1 > y2) {
        swap(y1, y2);
      }

      int tmp = p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1],
          area = (x2 - x1 + 1) * (y2 - y1 + 1);
      if (tmp == area) {
        x2 = get_ori(x2), x1 = get_ori(x1), y2 = get_ori(y2), y1 = get_ori(y1);
        int dx = abs(x2 - x1) + 1, dy = abs(y2 - y1) + 1;
        ckmax(ans, 1LL * dx * dy);
      }
    }
  }

  cout << ans << '\n';
}
