// Date: Thu Aug 22 12:43:26 2024

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
mt19937_64 _m_gen64;

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

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

ll qmod(ll x, ll y, ll m) {
  ll ans = 1 % m;

  while (y) {
    if (y & 1)
      ans = ans * x % m;
    y >>= 1;
    x = x * x % m;
  }
  return ans;
}

ll rev_mod(ll x, ll m) { return qmod(x, m - 2, m); }

struct RevMod {
  VI a, d;
  int n, p;

  RevMod(VI &a_, int p_) : a(a_), n(SZ(a)), p(p_) {
    d = VI(n, 0);

    d[0] = a[0] % p;
    For(i, 1, n) { d[i] = (1LL * a[i] * d[i - 1]) % p; }
  }

  VI get() {
    VI ans(n, 0);
    int cur = rev_mod(d[n - 1], p);

    Rof(i, 0, n) {
      if (i)
        ans[i] = (1LL * cur * d[i - 1]) % p;
      else
        ans[i] = cur % p;

      cur = 1LL * cur * a[i] % p;
    }
    return ans;
  }
};

struct Combination {
  int n, p;
  VI a, b;

  Combination(int n_, int p_) : n(n_), p(p_) {
    a = VI(n + 1);

    a[0] = 1;
    For1(i, 1, n) { a[i] = (1LL * a[i - 1] * i) % p; }

    RevMod rv(a, p);
    b = rv.get();
  }

  int C(int n1, int m1) {
    if (m1 > n1)
      return 0;
    if (m1 == 0 || m1 == n1)
      return 1 % p;

    int ans = a[n1] % p;
    ans = 1LL * ans * ((1LL * b[m1] * b[n1 - m1]) % p) % p;
    return ans;
  }
};

void solve() {
  ll n;
  while (cin >> n) {
    ll x = n % MOD;
    x = x * ((n + 1) % MOD) % MOD;
    x = x * ((n * 2 + 1) % MOD) % MOD;
    ll y = rev_mod(6, MOD) % MOD;
    x = x * y % MOD;
    cout << x << '\n';
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("15950.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

  int T = 1;

  while (T--) {
    solve();
  }

  return 0;
}