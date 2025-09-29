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

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const string& optstr = "") {
  cout << optstr;
  copy(coll.begin(), coll.end(),
       ostream_iterator<typename T::value_type>(cout, " "));
  cout << '\n';
}

template <typename T>
inline void INPUT_ELEMENTS(T& coll, const int n, const int start = 0) {
  if (start) coll.push_back(typename T::value_type{});
  copy_n(istream_iterator<typename T::value_type>(cin), n, back_inserter(coll));
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
#if defined(_DEBUG) && !defined(_CPH) && !defined(_SUB)
  freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

#if defined(_DEBUG) && !defined(_SUB)
  auto _start_ts = std::chrono::high_resolution_clock::now();
#endif

  Init();
  solve();

#if defined(_DEBUG) && !defined(_SUB)
  auto _end_ts = std::chrono::high_resolution_clock::now();
  std::cerr << "Execution time: "
            << std::chrono::duration<double>(_end_ts - _start_ts).count()
            << " seconds." << std::endl;
#endif

  return 0;
}

void Init() {}

struct BigNum {
  string s;
  VI a;
  int len, sign;

  BigNum() : s("0"), a{0} { sign = 1; }
  BigNum(string& s_) : s(s_) {
    len = SZ(s);
    a = VI(len);
    sign = 1;
    Rof(i, 0, len) a[len - 1 - i] = s[i] - '0';
  }
  BigNum(VI& a_) {
    a = a_;
    len = SZ(a);
    sign = 1;
  }

  bool operator<(BigNum& rh) const {
    if (len != rh.len) return len < rh.len;

    Rof(i, 0, len) {
      if (a[i] != rh.a[i]) return a[i] < rh.a[i];
    }
    return false;
  }

  BigNum operator+(BigNum& rh) {
    if (*this < rh) return rh + *this;
    VI res;
    int t = 0, len1 = rh.len;

    For(i, 0, len) {
      t += a[i];
      if (i < len1) t += rh.a[i];
      res.pb(t % 10);
      t /= 10;
    }

    if (t) res.pb(t);
    return BigNum(res);
  }

  BigNum operator-(BigNum& rh) {
    if (*this < rh) {
      auto ans = rh - *this;
      ans.sign = -1;
      return ans;
    }

    int len1 = rh.len, t = 0;
    auto& b = rh.a;
    VI res;

    For(i, 0, len) {
      t = a[i] - t;
      if (i < len1) t -= b[i];
      res.pb((t + 10) % 10);
      t = (t < 0);
    }
    while (SZ(res) > 1 && res.back() == 0) res.pop_back();

    return BigNum(res);
  }

  BigNum operator*(BigNum& rh) {
    if (*this < rh) {
      return rh * *this;
    }

    int len1 = rh.len, t = 0;
    auto& b = rh.a;
    VI res(len + len1 + 1);

    For(j, 0, len1) {
      For(i, 0, len) {
        t += res[i + j] + a[i] * b[j];
        res[i + j] = t % 10;
        t /= 10;
      }
      if (t) {
        res[j + len] = t;
        t = 0;
      }
    }

    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return BigNum(res);
  }
};

ostream& operator<<(ostream& os, BigNum& num) {
  if (num.sign < 0) os << '-';
  Rof(i, 0, num.len) { os << num.a[i]; }
  return os;
}
istream& operator>>(istream& is, BigNum& num) {
  string s;
  is >> s;
  num = BigNum(s);
  return is;
}

void solve() {
  BigNum s, t;
  cin >> s >> t;

  auto res = s * t;
  cout << res << '\n';
}
