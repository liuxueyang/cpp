// Date: Sat Jul 27 20:16:10 2024

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

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

const int N = 200100;
ll n, X, Y;
using pll = pair<ll, ll>;
pair<ll, ll> a[N];

void solve() {
  while (cin >> n >> X >> Y) {
    For1(i, 1, n) { cin >> a[i].f1; }
    For1(i, 1, n) { cin >> a[i].f2; }

    sort(a + 1, a + 1 + n, greater<pair<ll, ll>>());

    int ans = n;
    ll sum = 0;

    // For1(i, 1, n) {
    //   if (sum < X) {
    //     sum += a[i].f1;
    //   } else {
    //     break;
    //   }
    //   ans = i;
    // }

    int i = 1;
    while (sum <= X && i <= n) {
      sum += a[i].f1;
      ans = i;
      ++i;
    }
    dbg(ans, sum);

    sort(a + 1, a + 1 + n,
         [](const pll &x, const pll &y) { return x.f2 > y.f2; });

    i = 1;
    sum = 0;
    int ans2 = n;
    while (sum <= Y && i <= n) {
      sum += a[i].f2;
      ans2 = i;
      ++i;
    }
    dbg(ans2, sum);

    ckmin(ans, ans2);
    cout << ans << '\n';
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
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
