// Date: Tue Aug 20 11:12:41 2024

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

vector<vector<ll>> multi(vector<vector<ll>> &l, vector<vector<ll>> &r, ll mo) {
  int n = SZ(l), m = SZ(r[0]), k = SZ(l[0]);
  vector<vector<ll>> ans(n, vector<ll>(m));

  For(i, 0, n) {
    For(j, 0, m) {
      For(t, 0, k) { ans[i][j] = (ans[i][j] + l[i][t] * r[t][j]) % mo; }
    }
  }

  return ans;
}

ll qmi(ll a, ll b, ll c) {
  ll res = 1 % c;
  while (b) {
    if (b & 1)
      res = res * a % c;
    a = a * a % c;
    b >>= 1;
  }
  return res;
}

vector<vector<ll>> matrix_qmod(vector<vector<ll>> a, ll b, ll c) {
  int n = SZ(a);
  vector<vector<ll>> ans(n, vector<ll>(n));

  For(i, 0, n) { ans[i][i] = 1; }

  while (b) {
    if (b & 1)
      ans = multi(ans, a, c);
    a = multi(a, a, c);
    b >>= 1;
  }

  return ans;
}

void solve() {
  int n;
  ll k;
  cin >> n >> k;

  vector<vector<ll>> a(n, vector<ll>(n));
  For(i, 0, n) {
    For(j, 0, n) { cin >> a[i][j]; }
  }

  vector<vector<ll>> ans = matrix_qmod(a, k, MOD);
  For(i, 0, n) {
    For(j, 0, n) { cout << ans[i][j] << ' '; }
    cout << '\n';
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("3390.in", "r", stdin);
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
