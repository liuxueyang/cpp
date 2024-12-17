// Date: Thu Aug 22 12:34:07 2024

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

template <class T> struct Matrix {
  typedef vector<T> VT;
  typedef vector<VT> VTT;

  VTT a;
  int n, m;
  ll mod;

  Matrix() : n(0), m(0) {}
  Matrix(int n_, int m_, ll mod_) : n(n_), m(m_), mod(mod_) {
    a = VTT(n, VT(m));
  }
  Matrix(VTT &a_, ll mod_) : a(a_), n(SZ(a)), m(SZ(a[0])), mod(mod_) {}

  void E() {
    For(i, 0, n) {
      For(j, 0, m) { a[i][j] = (i == j); }
    }
  }

  void zero() { a = vector<VT>(n, VT(m, 0)); }

  Matrix<T> operator*(const Matrix<T> &rh) const {
    int n2 = rh.n, m2 = rh.m;
    assert(m == n2);

    Matrix<T> ans(n, m2, mod);

    For(i, 0, n) {
      For(j, 0, m2) {
        For(k, 0, m) {
          T x = (a[i][k] * rh.a[k][j]) % mod;
          ans.a[i][j] = (ans.a[i][j] + x) % mod;
        }
      }
    }

    return ans;
  }

  Matrix<T> operator%(const T x) const {
    Matrix<T> ans(n, m, x);

    For(i, 0, n) {
      For(j, 0, m) { ans.a[i][j] = (a[i][j] + x) % x; }
    }

    return ans;
  }

  Matrix<T> operator-(const Matrix<T> &rh) const {
    assert(n == rh.n && m == rh.m);

    Matrix<T> ans(n, m, mod);

    For(i, 0, n) {
      For(j, 0, m) { ans.a[i][j] = a[i][j] - rh.a[i][j]; }
    }

    return ans;
  }

  Matrix<T> operator+(const Matrix<T> &rh) const {
    assert(n == rh.n && m == rh.m);

    Matrix<T> ans(n, m, mod);

    For(i, 0, n) {
      For(j, 0, m) { ans.a[i][j] = a[i][j] + rh.a[i][j]; }
    }

    return ans;
  }

  Matrix<T> operator^(ll k) const {
    assert(n == m);
    Matrix<T> ans(n, n, mod);

    Matrix<T> a = *this;

    while (k) {
      if (k & 1)
        ans = ans * a;
      a = a * a;
      k >>= 1;
    }
    return ans;
  }
};

typedef Matrix<int> MI;
typedef vector<MI> VMI;

struct NestedMatrix {
  int n, m;
  ll mod;
  int n1, m1;
  vector<VMI> a;

  NestedMatrix(int n_, int m_, ll mod_, int n1_, int m1_)
      : n(n_), m(m_), mod(mod_), n1(n1_), m1(m1_),
        a(n, vector<MI>(m, Matrix<int>(n1_, m1_, mod_))) {}

  NestedMatrix operator*(NestedMatrix &rh) const {
    int n2 = rh.n, m2 = rh.m;
    assert(m == n2);

    NestedMatrix ans(n, m2, mod, n1, m1);
    For(i, 0, n) {
      For(j, 0, m2) {
        For(k, 0, m) {
          Matrix<int> x = (a[i][k] * rh.a[k][j]) % mod;
          ans.a[i][j] = (ans.a[i][j] + x) % mod;
        }
      }
    }

    return ans;
  }

  NestedMatrix operator^(ll k) const {
    assert(n == m);
    NestedMatrix ans(n, m, mod, n1, m1);

    Matrix<int> E(n, m, mod), zero(n, m, mod);
    E.E(), zero.zero();

    For(i, 0, n) For(j, 0, m) {
      if (i == j)
        ans.a[i][j] = E;
      else {
        ans.a[i][j] = zero;
      }
    }

    NestedMatrix x = *this;
    while (k) {
      if (k & 1)
        ans = ans * x;
      x = x * x;
      k >>= 1;
    }

    return ans;
  }
};

template <class T> ostream &operator<<(ostream &out, Matrix<T> &mat) {
  For(i, 0, mat.n) {
    For(j, 0, mat.m) { out << mat.a[i][j] << " \n"[j == mat.m]; }
    cout << '\n';
  }
  return out;
}

template <class T> istream &operator>>(istream &in, Matrix<T> &mat) {
  For(i, 0, mat.n) { For(j, 0, mat.m) in >> mat.a[i][j]; }
  return in;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  Matrix<ll> a(n, m, MOD), b(m, k, MOD);
  cin >> a >> b;
  auto c = a * b;
  cout << c;
}

int main(void) {
#ifdef _DEBUG
  freopen("2105.in", "r", stdin);
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
