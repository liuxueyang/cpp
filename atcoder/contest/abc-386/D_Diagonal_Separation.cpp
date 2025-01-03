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

const int N = 200110;

template <class T>
struct BIT {
  T c[N];
  int n;

  void resize(int _n) {
    n = _n;
    For1(i, 0, n) c[i] = 0;
  }

  int lowbit(int x) { return x & (-x); }

  T query(int x) {
    T s = 0;
    assert(x <= n);
    while (x) {
      s += c[x];
      x -= lowbit(x);
    }
    return s;
  }

  void modify(int x, T d) {
    assert(x != 0);
    while (x <= n) {
      c[x] += d;
      x += lowbit(x);
    }
  }
};

struct node {
  int x, y;
  string ch;

  bool operator<(const node &rh) const {
    if (y != rh.y) return y < rh.y;
    return x < rh.x;
  }
};

void solve1() {
  int n, m;
  while (cin >> n >> m) {
    int x, y;
    string ch;
    vector<node> a;
    VI b;

    For(i, 0, m) {
      cin >> x >> y >> ch;
      a.pb({x, y, ch});
      b.pb(x);
    }

    sort(all(a));

    sort(all(b));
    b.resize(distance(b.begin(), unique(all(b))));
    int m{SZ(b)};

    auto get = [&](int x) {
      return distance(b.begin(), lower_bound(all(b), x)) + 1;
    };

    BIT<int> tr;
    tr.resize(m + 10);

    bool ok{true};

    for (auto t : a) {
      auto [x, y, ch] = t;
      int id = get(x);

      if (ch == "W") {
        tr.modify(id, 1);
      } else {
        int tmp = tr.query(id);
        if (tmp > 0) {
          ok = false;
          break;
        }
      }
    }

    cout << (ok ? "Yes\n" : "No\n");
  }
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<node> a;

  while (m--) {
    int x, y;
    string ch;
    cin >> x >> y >> ch;
    a.pb(node{x, y, ch});
  }
  sort(all(a));

  int curx{INF};
  bool ok{true};
  for (auto [x, y, ch] : a) {
    if (ch == "W")
      ckmin(curx, x);
    else {
      if (x >= curx) {
        ok = false;
        break;
      }
    }
  }
  cout << (ok ? "Yes" : "No") << '\n';
}

int main(void) {
#ifdef _DEBUG
  // freopen("../input.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

  int T = 1;
  // cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}