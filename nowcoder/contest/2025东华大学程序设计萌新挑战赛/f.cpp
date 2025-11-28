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
  freopen("input.txt", "r", stdin);
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

string int2str(int n) {
  string res;
  while (n) {
    if (n & 1)
      res += '1';
    else
      res += '0';
    n >>= 1;
  }
  reverse(all(res));
  int len = SZ(res);
  if (len < 30) {
    res = string(30 - len, '0') + res;
  }
  return res;
}

int str2int(string s) {
  int res = 0;
  for (auto c : s) {
    if (c == '1')
      res = res * 2 + 1;
    else
      res = res * 2;
  }
  return res;
}

class Trie {
public:
  struct node {
    int cnt;
    vector<struct node *> son;

    node() {
      cnt = 0;
      son = vector<node *>(2);
    }
  };

  node *root;

  Trie() { root = new node(); }

  void insert(string s) {
    node *p = root;

    for (auto c : s) {
      int id = c - '0';
      if (!p->son[id])
        p->son[id] = new node();
      p = p->son[id];
    }
    p->cnt++;
  }

  string search(string s) {
    node *p = root;
    string res;

    for (auto c : s) {
      int id = c - '0';
      if (!p->son[id]) {
        id = 1 - id;
      }
      res += char('0' + id);
      p = p->son[id];
    }
    return res;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;

  VI d(n + 1);
  VI ori;
  For1(i, 1, n) {
    cin >> d[i];
    if (d[i] == 0) {
      ori.pb(i);
    }
  }

  vector<vector<PII>> g(n + 1);
  For(i, 0, m) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }

  for (auto i : ori) {
    g[0].pb({i, 0});
    g[i].pb({0, 0});
  }

  Trie tree;
  For1(i, 1, n) {
    if (d[i] == 0) {
      tree.insert(int2str(i));
    }
  }

  For1(i, 1, n) {
    if (d[i] == 0)
      continue;
    string tmp = tree.search(int2str(i));
    int j = str2int(tmp);
    int w = (j ^ i) + d[i];
    g[i].pb({j, w});
    g[j].pb({i, w});
  }

  VL dis(n + 1, INFL);
  dis[0] = 0;

  pqg<PII> q;
  VB vis(n + 1);
  q.push({0, 0});

  while (nemp(q)) {
    auto [base, u] = q.top();
    q.pop();

    if (base > dis[u])
      continue;

    if (vis[u])
      continue;

    vis[u] = true;
    for (auto [v, w] : g[u]) {
      ll tmp = base + w;
      if (ckmin(dis[v], tmp)) {
        if (!vis[v])
          q.push({tmp, v});
      }
    }
  }

  For1(i, 1, n) { cout << dis[i] << '\n'; }
}
