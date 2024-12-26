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

void solve() {
  int n;
  cin >> n;

  VI a(n + 10);
  int pos{-1};
  VI ans;

  For1(i, 1, n) {
    cin >> a[i];
    if (a[i] != 1 && a[i] != -1) pos = i;
  }

  auto get = [&](int l, int r) -> PII {
    VI p(n + 10);
    int mi{}, mx{}, ansl{}, ansr{};

    For1(i, l, r) { p[i] = p[i - 1] + a[i]; }
    For1(i, l, r) {
      ckmin(ansl, p[i] - mx);
      ckmax(ansr, p[i] - mi);

      ckmin(mi, p[i]);
      ckmax(mx, p[i]);
    }
    return {ansl, ansr};
  };

  if (pos == -1) {
    auto [l1, r1] = get(1, n);
    For1(i, l1, r1) ans.pb(i);
  } else {
    VI p1(n + 10), p2(n + 10);
    vector<PII> b(n + 10);

    For1(i, 1, pos - 1) p1[i] = p1[i - 1] + a[i];
    Rof1(i, pos + 1, n) p2[i] = p2[i + 1] + a[i];

    b[0] = {0, 0};
    int l = 0, r = 0;
    For1(i, 1, pos - 1) {
      b[i] = {min(p1[i] - r, 0), max(p1[i] - l, 0)};
      ckmin(l, p1[i]);
      ckmax(r, p1[i]);
    }

    l = r = 0;
    b[n + 1] = {0, 0};
    Rof1(i, pos + 1, n) {
      b[i] = {min(p2[i] - r, 0), max(p2[i] - l, 0)};
      ckmin(l, p2[i]);
      ckmax(r, p2[i]);
    }

    vector<PII> rngs;
    rngs.pb(get(1, pos - 1));
    rngs.pb(get(pos + 1, n));
    rngs.pb(PII{a[pos] + b[pos - 1].f1 + b[pos + 1].f1,
                a[pos] + b[pos - 1].f2 + b[pos + 1].f2});

    sort(all(rngs));
    PII cur = rngs[0];
    vector<PII> res;

    For(i, 1, 3) {
      if (cur.f2 < rngs[i].f1) {
        res.pb(cur);
        cur = rngs[i];
      } else {
        ckmax(cur.f2, rngs[i].f2);
      }
    }
    res.pb(cur);

    for (auto [x, y] : res) {
      For1(i, x, y) ans.pb(i);
    }
  }

  cout << SZ(ans) << '\n';
  Outputr(all(ans));
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
  cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}
