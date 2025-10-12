// Date: Sun Aug  4 20:08:04 2024

#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
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

const ull Pr = 131;

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

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <typename t> istream &operator>>(istream &in, vector<t> &vec) {
  for (t &x : vec)
    in >> x;
  return in;
}

template <typename t> ostream &operator<<(ostream &out, vector<t> &vec) {
  int n = SZ(vec);
  For(i, 0, n) {
    out << vec[i];
    if (i < n - 1)
      out << ' ';
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

// int128 input and output
#ifdef _DEBUG
using lll = __int128;

istream &operator>>(istream &is, lll &v) {
  string s;
  is >> s;
  v = 0;
  for (auto &it : s)
    if (isdigit(it))
      v = v * 10 + it - '0';
  if (s[0] == '-')
    v *= -1;
  return is;
}

ostream &operator<<(ostream &os, const lll &v) {
  if (v == 0)
    return (os << "0");
  lll num = v;
  if (v < 0)
    os << '-', num = -num;
  string s;
  for (; num > 0; num /= 10)
    s.pb((char)(num % 10) + '0');
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

void solve() {
  int n, k;
  cin >> n >> k;

  VI a(n + 1, 0);
  vector<ll> p0(n + 2, 0), p1(n + 2, 0), po0(n + 2, 0), po1(n + 2, 0);

  For1(i, 1, n) { cin >> a[i]; }

  map<int, VI> m;

  For1(i, 1, n) {
    int r = a[i] % k;
    m[r].pb(a[i]);
  }

  int cnt{};
  for (auto &[x, y] : m) {
    if (SZ(y) & 1) {
      cnt++;
      if (cnt > 1)
        break;
    }
  }
  if (cnt > 1) {
    cout << "-1\n";
    return;
  }

  ll ans{};

  for (auto &[x, y] : m) {
    sort(all(y));
    int len = SZ(y);

    if (len & 1) {
      VI y1(len + 1, 0);
      For(i, 0, len) y1[i + 1] = y[i];

      p0 = vector<ll>(len + 2, 0);
      p1 = vector<ll>(len + 2, 0);
      po0 = vector<ll>(len + 2, 0);
      po1 = vector<ll>(len + 2, 0);

      For1(i, 1, len) {
        if (i & 1) {
          p1[i] = p1[i - 1] + y1[i];
          p0[i] = p0[i - 1];
        } else {
          p0[i] = p0[i - 1] + y1[i];
          p1[i] = p1[i - 1];
        }
      }

      Rof1(i, 1, len) {
        if (i & 1) {
          po1[i] = po1[i + 1] + y1[i];
          po0[i] = po0[i + 1];
        } else {
          po0[i] = po0[i + 1] + y1[i];
          po1[i] = po1[i + 1];
        }
      }

      ll cur = INFL;
      for (int i = 1; i <= len; i += 2) {
        ll tmp = p0[i - 1] - p1[i - 1] + po1[i + 1] - po0[i + 1];
        ckmin(cur, tmp);
      }

      ans += cur;
    } else {
      for (int i = 1; i < len; i += 2) {
        ans += y[i] - y[i - 1];
      }
    }
  }

  cout << ans / k << '\n';
}

int main(void) {
#ifdef _DEBUG
  freopen("e.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 1;
  cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}
