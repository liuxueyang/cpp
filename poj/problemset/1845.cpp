// Date: Fri Aug  9 12:54:10 2024

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
// template <class T> using pq = priority_queue<T>;
// template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

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

// template <typename t> istream &operator>>(istream &in, vector<t> &vec) {
//   for (t &x : vec)
//     in >> x;
//   return in;
// }

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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

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

map<ll, int> prime_facto(ll n) {
  map<ll, int> res;
  for (ll i = 2; i <= n / i; ++i) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n > 1)
    res[n]++;

  return res;
}

const int N = 100010;
int primes[N], cnt;
bool st[N];

void get_primes(int n) {
  st[0] = st[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) {
      primes[cnt++] = i;
      for (ll j = ll(i) * i; j <= n; j += i) {
        st[j] = true;
      }
    }
  }
}

void solve() {
  ll a, b;
  while (cin >> a >> b) {
    if (a == 0) {
      cout << "0\n";
      continue;
    } else if (b == 0 || a == 1) {
      cout << "1\n";
      continue;
    }

    map<ll, int> pf = prime_facto(a);

    const int p = 9901;

    VI prs;
    set<int> p2;

    for (map<ll, int>::iterator it = pf.begin(); it != pf.end(); it++) {
      int x = it->f1 - 1;
      if (it->f1 % p == 0) continue;

      if (gcd(x, p) == 1) {
        prs.pb(it->f1 - 1);
      } else {
        p2.insert(it->f1);
      }
    }

    map<int, int> rv;

    if (nemp(prs)) {
      RevMod rm = RevMod(prs, p);
      VI rms = rm.get();
      int len = SZ(prs);
      For(i, 0, len) { rv[prs[i]] = rms[i]; }
    }

    ll ans = 1;

    for (map<ll, int>::iterator it = pf.begin(); it != pf.end(); it++) {
      ll cnt = 1LL * it->f2 * b + 1;
      ll pi = it->f1;
      ll tmp = 1;

      if (pi % p == 0)
        continue;

      if (has(p2, pi)) {
        tmp = (it->f2 + 1) % p;
      } else {
        tmp = (qmod(pi, cnt, p) - 1 + p) % p;
        tmp = tmp * rv[pi - 1] % p;
      }
      ans = ans * tmp % p;
    }

    cout << ans << '\n';
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("1845.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 1;
  cnt = 0;
  get_primes(1e5);

  while (T--) {
    solve();
  }

  return 0;
}
