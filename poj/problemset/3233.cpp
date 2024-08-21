// Date: Wed Aug 21 22:08:51 2024

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
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

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
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define NL cout << '\n';

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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
    dbg(n, rh.n, m, rh.m);
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

    Matrix<int> E(n, n, mod), zero(n, n, mod);
    E.E(), zero.zero();

    For(i, 0, n) {
      For(j, 0, n) {
        if (i == j)
          ans.a[i][j] = E;
        else {
          ans.a[i][j] = zero;
        }
      }
    }
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

typedef Matrix<int> MI;

void solve() {
  int n, k, m;
  cin >> n >> k >> m;

  dbg(n, k, m);
  Matrix<int> mat(n, n, m);
  cin >> mat;
  cout << mat;

  MI E(n, n, m), zero(n, n, m);
  E.E(), zero.zero();

  Matrix<MI> base(2, 2, m);
  base.a[0][0] = E;
  base.a[0][1] = mat;
  base.a[1][0] = zero;
  base.a[1][1] = mat;

  cout << base;

  Matrix<MI> d(n, n, m);
  d = base ^ k;
  // Matrix<MI> start(2, 1, m);
  // start.a[0][0] = zero;
  // start.a[1][0] = E;

  // Matrix<MI> res = d * start;

  // MI ans = res.a[0][0];

  // cout << ans << '\n';
}

int main(void) {
#ifdef _DEBUG
  freopen("3233.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 1;

  while (T--) {
    solve();
  }

  return 0;
}
