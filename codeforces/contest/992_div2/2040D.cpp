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

VVI g;
VI a, ans;

void dfs(int u, int fa) {
  for (auto v : g[u]) {
    if (v == fa) continue;
    a[v] = 1 ^ a[u];
    dfs(v, u);
  }
}

void solve() {
  int n;
  cin >> n;

  g = VVI(n + 10);
  a = ans = VI(n + 10);
  For(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }

  a[1] = 0;
  dfs(1, -1);
  set<int> s0, s1;

  For1(i, 1, n) {
    if (a[i] == 0)
      s0.insert(i);
    else
      s1.insert(i);
  }

  For1(i, 1, n) {
    if (SZ(g[i]) == n - 1) {
      ans[i] = 2;
      int k = 3;
      bool ok = true;

      For1(j, 1, n) {
        if (j == i) continue;
        if (ok) {
          ok = false;
          ans[j] = 1;
        } else
          ans[j] = 2 * k++;
      }

      Outputr(ans.begin() + 1, ans.begin() + 1 + n);
      return;
    }
  }

  int u0{-1}, u1{-1};
  For1(u, 1, n) {
    for (auto v : g[u]) {
      if (SZ(g[u]) >= 2 && SZ(g[v]) >= 2) {
        u0 = (g[u][0] == v ? g[u][1] : g[u][0]);
        u1 = (g[v][0] == u ? g[v][1] : g[v][0]);
        if (a[u0] == 1) swap(u0, u1);

        int j = 1;
        for (auto x : s0) {
          if (x == u0) continue;
          ans[x] = 2 * j++;
        }
        ans[u0] = 2 * j++;
        ans[u1] = 2 * j++;
        for (auto x : s1) {
          if (x == u1) continue;
          ans[x] = 2 * j++;
        }

        Outputr(ans.begin() + 1, ans.begin() + 1 + n);
        return;
      }
    }
  }
}

void solve1() {
  int n;
  cin >> n;

  g = VVI(n + 10);
  a = ans = VI(n + 10);
  For(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }

  a[1] = 0;
  dfs(1, -1);
  set<int> s0, s1;

  For1(i, 1, n) {
    if (a[i] == 0)
      s0.insert(i);
    else
      s1.insert(i);
  }

  For1(i, 1, n) {
    if (SZ(g[i]) == n - 1) {
      ans[i] = 2;
      int k = 3;
      bool ok = true;

      For1(j, 1, n) {
        if (j == i) continue;
        if (ok) {
          ok = false;
          ans[j] = 1;
        } else
          ans[j] = 2 * k++;
      }

      Outputr(ans.begin() + 1, ans.begin() + 1 + n);
      return;
    }
  }

  int u0{-1}, u1{-1};
  bool ok = false;
  for (auto u : s0) {
    sort(all(g[u]));

    for (auto v : s1) {
      auto it = lower_bound(all(g[u]), v);
      if (it == g[u].end() || *it != v) {
        ok = true;
        u0 = u, u1 = v;
        break;
      }
    }
    if (ok) break;
  }

  int j = 1;
  for (auto x : s0) {
    if (x == u0) continue;
    ans[x] = 2 * j++;
  }
  ans[u0] = 2 * j++;
  ans[u1] = 2 * j++;
  for (auto x : s1) {
    if (x == u1) continue;
    ans[x] = 2 * j++;
  }

  Outputr(ans.begin() + 1, ans.begin() + 1 + n);
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
