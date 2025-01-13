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

struct node {
  int val, typ;
};

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  VVL a(n + 10, VL(m + 10));
  VVB vis(n + 10, VB(m + 10));
  VI col(m + 10), row(n + 10);

  For(i, 0, n) {
    For(j, 0, m) { cin >> a[i][j]; }
  }
  PII cur{0, 0};
  vis[0][0] = true;
  queue<PII> q;
  for (auto c : s) {
    if (c == 'D')
      cur.f1++;
    else
      cur.f2++;
    vis[cur.f1][cur.f2] = true;
  }

  For(i, 0, n) {
    int nj{-1};
    For(j, 0, m) {
      if (vis[i][j]) {
        row[i]++;
        nj = j;
      }
    }
    if (row[i] == 1) {
      q.push({i, nj});
    }
  }
  For(j, 0, m) {
    int ni{-1};
    For(i, 0, n) {
      if (vis[i][j]) {
        col[j]++;
        ni = i;
      }
    }
    if (col[j] == 1) q.push({ni, j});
  }

  while (nemp(q)) {
    auto [x, y] = q.front();
    q.pop();
    if (row[x] == 1) {
      ll sum{};
      For(j, 0, m) {
        if (j != y) sum += a[x][j];
      }
      a[x][y] = -sum;
      vis[x][y] = false;
      row[x]--;
      col[y]--;
    } else if (col[y] == 1) {
      ll sum{};
      For(i, 0, n) if (i != x) sum += a[i][y];
      a[x][y] = -sum;
      vis[x][y] = false;
      row[x]--, col[y]--;
    }
    if (row[x] == 1) {
      For(j, 0, m) if (vis[x][j]) {
        q.push({x, j});
        break;
      }
    }
    if (col[y] == 1) {
      For(i, 0, n) if (vis[i][y]) {
        q.push({i, y});
        break;
      }
    }
  }
  For(i, 0, n) {
    For(j, 0, m) { cout << a[i][j] << ' '; }
    cout << '\n';
  }
}

void solve1() {
  int n, m;
  string s;

  cin >> n >> m >> s;
  VVL a(n + 10, VL(m + 10));
  VVB vis(n + 10, VB(m + 10, true));

  For(i, 0, n) {
    For(j, 0, m) { cin >> a[i][j]; }
  }
  PII cur{0, 0};
  vis[0][0] = false;
  for (auto ch : s) {
    if (ch == 'D')
      cur.f1++;
    else
      cur.f2++;
    vis[cur.f1][cur.f2] = false;
  }
  queue<node> q;
  For(i, 0, n) {
    int cnt{};
    For(j, 0, m) if (!vis[i][j]) cnt++;
    if (cnt == 1) q.push({i, 1});
  }
  For(j, 0, m) {
    int cnt{};
    For(i, 0, n) if (!vis[i][j]) cnt++;
    if (cnt == 1) q.push({j, 2});
  }
  while (nemp(q)) {
    auto [val, typ] = q.front();
    q.pop();
    if (typ == 1) {
      int target{-1}, cnt{};
      ll sum{};
      For(j, 0, m) {
        if (!vis[val][j]) {
          target = j;
          cnt++;
        } else
          sum += a[val][j];
      }
      if (cnt == 1) {
        a[val][target] = -sum;
        vis[val][target] = true;
        cnt = 0;
        For(i, 0, n) {
          if (!vis[i][target]) cnt++;
        }
        if (cnt == 1) q.push({target, 2});
      }
    } else {
      int target{-1}, cnt{};
      ll sum{};
      For(i, 0, n) {
        if (!vis[i][val]) {
          target = i;
          cnt++;
        } else
          sum += a[i][val];
      }
      if (cnt == 1) {
        a[target][val] = -sum;
        vis[target][val] = true;
        cnt = 0;
        For(j, 0, m) {
          if (!vis[target][j]) cnt++;
        }
        if (cnt == 1) q.push({target, 1});
      }
    }
  }
  For(i, 0, n) {
    For(j, 0, m) { cout << a[i][j] << ' '; }
    cout << '\n';
  }
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
