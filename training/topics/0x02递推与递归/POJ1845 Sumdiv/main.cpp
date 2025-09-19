#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef vector<vector<string> > VVS;
typedef vector<bool> VB;
typedef vector<vector<bool> > VVB;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

template <class T>
struct pq {
  typedef priority_queue<T> type;
};
template <class T>
struct pqg {
  typedef priority_queue<T, vector<T>, greater<T> > type;
};

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
  int len = int(a.size());
  for (int i = 0; i < len; i++) {
    is >> a[i];
  }
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

#ifdef _DEBUG
#include "debug.h"
#else
#endif

void Init();
void solve();

int main(void) {
#if defined(_DEBUG) && !defined(_CPH)
  freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#ifdef _DEBUG
  clock_t _start_ts = clock();
#endif

  Init();
  solve();

#ifdef _DEBUG
  clock_t _end_ts = clock();
  std::cerr << "Execution time: "
            << double(_end_ts - _start_ts) / CLOCKS_PER_SEC << " seconds."
            << std::endl;
#endif

  return 0;
}

const int MOD2 = 9901;
map<int, ll> cache;

void Init() {}

ll qmod(ll a, ll b, ll c = MOD2) {
  ll res = 1 % c;
  while (b) {
    if (b & 1) res = res * a % c;
    a = a * a % c;
    b >>= 1;
  }
  return res;
}

ll solve2(int n, int p, int MOD = MOD2) {
  if (n == 0) return 1;
  if (cache.find(n) != cache.end()) {
    return cache[n];
  }

  if (n % 2 == 0) {
    ll res = solve2(n / 2 - 1, p) * (1 + qmod(p, n / 2)) % MOD;
    res = (res + qmod(p, n)) % MOD;
    return cache[n] = res;
  } else {
    ll res = solve2(n / 2, p) * (1 + qmod(p, (n + 1) / 2)) % MOD;
    return cache[n] = res;
  }
}

map<int, int> factor(int n) {
  map<int, int> mp;

  for (int i = 2; 1LL * i * i <= n; i++) {
    while (n % i == 0) {
      mp[i]++;
      n /= i;
    }
  }

  if (n > 1) mp[n]++;

  return mp;
}

void solve() {
  int a, b;

  while (cin >> a >> b) {
    if (a == 0) {
      cout << "0\n";
      continue;
    }
    map<int, int> mp = factor(a);
    ll ans = 1;

    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
      cache = map<int, ll>();
      int x = it->first, cnt = it->second;
      ans = (ans * solve2(cnt * b, x)) % MOD2;
    }
    cout << ans << '\n';
  }
}
