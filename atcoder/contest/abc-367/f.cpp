// Date: Sun Aug 18 22:44:05 2024

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

const int N = 200100;
int n, q, a[N], b[N];
ull a1[N], b1[N], a2[N], b2[N], m[N], pa1[N], pa2[N], pb1[N], pb2[N];

void solve() {

  while (cin >> n >> q) {
    Inputr(all1(a, n));
    Inputr(all1(b, n));

    For1(i, 1, n) { m[i] = _m_gen64(); }

    pa1[0] = pb1[0] = pa2[0] = pb2[0] = 0;

    For1(i, 1, n) {
      a1[i] = m[a[i]];
      b1[i] = m[b[i]];

      a2[i] = a1[i] * a1[i];
      b2[i] = b1[i] * b1[i];
    }

    For1(i, 1, n) {
      pa1[i] = pa1[i - 1] + a1[i];
      pa2[i] = pa2[i - 1] + a2[i];

      pb1[i] = pb1[i - 1] + b1[i];
      pb2[i] = pb2[i - 1] + b2[i];
    }

    while (q--) {
      int l, r, L, R;
      cin >> l >> r >> L >> R;

      if (r - l == R - L && pa1[r] - pa1[l - 1] == pb1[R] - pb1[L - 1] &&
          pa2[r] - pa2[l - 1] == pb2[R] - pb2[L - 1]) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("f.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 1;
  _m_gen64.seed(Pr);

  while (T--) {
    solve();
  }

  return 0;
}
