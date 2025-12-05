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
#if defined(MYINPUT)
  freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#if defined(MYDEBUG)
  auto _start_ts = std::chrono::high_resolution_clock::now();
#endif

  int T;
  cin >> T;
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

vector<PII> reset(string s) {
  int n = SZ(s), l = -1, r = -1;
  vector<PII> ans;
  s = " " + s;

  For(i, 1, n) {
    if (i + 1 <= n && s[i] == s[i + 1]) {
      l = i;
      r = i + 1;
      break;
    }
  }

  auto flip_range = [&](int l, int r) {
    For1(i, l, r) {
      if (s[i] == '1')
        s[i] = '0';
      else
        s[i] = '1';
    }
  };

  if (l == -1) {
    ans.push_back({2, 4});
    flip_range(2, 4);
    l = 1, r = 2;
  }
  while (r + 1 <= n && s[r] == s[r + 1])
    r++;

  // extend right
  while (r < n) {
    ans.push_back({l, r});
    flip_range(l, r);
    while (r + 1 <= n && s[r] == s[r + 1])
      r++;
  }
  // extend left
  while (l > 1) {
    ans.push_back({l, r});
    flip_range(l, r);
    while (l - 1 >= 1 && s[l - 1] == s[l])
      l--;
  }

  if (s[l] == '1') {
    ans.push_back({l, r});
    flip_range(l, r);
  }

  return ans;
}

void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  if (s == t) {
    cout << "0\n";
    return;
  }

  auto path_s = reset(s), path_t = reset(t);
  reverse(all(path_t));

  int len = SZ(path_s) + SZ(path_t);
  cout << len << '\n';
  for (auto [i, j] : path_s)
    cout << i << ' ' << j << '\n';
  for (auto [i, j] : path_t)
    cout << i << ' ' << j << '\n';
}
