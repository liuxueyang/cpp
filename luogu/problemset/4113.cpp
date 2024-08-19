// Date: Mon Aug 19 22:05:45 2024

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

const int N = 2000100;
int n, a[N], q, m, p1[N], p2[N], ans[N];
struct node {
  int id, l, r;
};
node b[N];

template <class T> struct BIT {
  int n;
  vector<T> c;

  BIT(int n_) : n(n_) { c = vector<T>(n + 10, 0); }

  int lowbit(int x) { return x & -x; }

  void update(int i, T d) {
    assert(i != 0);
    for (; i <= n; i += lowbit(i)) {
      c[i] += d;
    }
  }

  T query(int i) {
    T ans{};
    assert(i <= n);
    for (; i; i -= lowbit(i)) {
      ans += c[i];
    }
    return ans;
  }

  int search(T s) {
    // find the largest pos which presum(a[pos]) >= s
    int pos{};

    // 2^18 >= n(2e5)
    for (int j = 18; j >= 0; --j) {
      int pos1 = pos + (1 << j);
      if (pos1 <= n && c[pos1] <= s) {
        s -= c[pos1];
        pos = pos1;
      }
    }
    return pos;
  }
};

void solve() {
  while (cin >> n >> m >> q) {
    Inputr(all1(a, n));
    BIT<int> tr(max(n, m));

    For1(i, 1, q) {
      cin >> b[i].l >> b[i].r;
      b[i].id = i;
    }
    sort(all1(b, q), [](const node &l, const node &r) {
      if (l.r != r.r)
        return l.r < r.r;
      return l.l < r.l;
    });

    For1(i, 1, m) { p1[i] = p2[i] = -1; }

    int j = 1;
    For1(i, 1, n) {
      int x = a[i], pos1 = p1[x], pos2 = p2[x];

      if (pos1 == -1) {
        p1[x] = i;
      } else if (pos2 == -1) {
        p2[x] = pos1;
        tr.update(p2[x], 1);
        p1[x] = i;
      } else {
        tr.update(p2[x], -1);
        p2[x] = p1[x];
        tr.update(p2[x], 1);
        p1[x] = i;
      }
      while (j <= q && i == b[j].r) {
        ans[b[j].id] = tr.query(b[j].r) - tr.query(b[j].l - 1);
        j++;
      }
    }

    For1(i, 1, q) { cout << ans[i] << '\n'; }
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("4113.in", "r", stdin);
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
