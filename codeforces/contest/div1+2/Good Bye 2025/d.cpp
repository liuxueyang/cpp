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

#define No() cout << "No\n"
#define Yes() cout << "Yes\n"
#define NO() cout << "NO\n"
#define YES() cout << "YES\n"

template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}

template <class T>
ostream& operator<<=(ostream& os, const vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& a) {
  int n = int(a.size());
  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i == n - 1];
  }
  return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& a) {
  for (auto& x : a) is >> x;
  return is;
}

template <class T>
istream& operator>>=(istream& is, vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    is >> a[i];
  }
  return is;
}

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

void Init();
void solve();

int main(void) {
#if defined(_DEBUG) && !defined(_CPH) && !defined(_SUB)
  freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

#if defined(_DEBUG) && !defined(_SUB)
  auto _start_ts = std::chrono::high_resolution_clock::now();
#endif

  int T;
  cin >> T;
  while (T--) {
    Init();
    solve();
  }

#if defined(_DEBUG) && !defined(_SUB)
  auto _end_ts = std::chrono::high_resolution_clock::now();
  std::cerr << "Execution time: "
            << std::chrono::duration<double>(_end_ts - _start_ts).count()
            << " seconds." << std::endl;
#endif

  return 0;
}

void Init() {}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<PII> a(n + 10);
  For1(i, 1, n) {
    cin >> a[i].f1;
    a[i].f2 = i;
  }
  sort(a.begin() + 1, a.begin() + 1 + n);

  vector<PII> ans;
  int idx = n - m + 1;
  if (idx - 1 < m) {
    cout << "-1\n";
    return;
  }
  VB used(n + 10);

  if (m == 0) {
    priority_queue<PII> q;
    For1(i, 1, n) q.push(a[i]);
    while (SZ(q) >= 2) {
      auto [w1, id1] = q.top();
      q.pop();
      auto [w2, id2] = q.top();
      q.pop();
      if (!used[id2]) {
        used[id2] = true;
        w1 -= w2;
        if (w1 > 0) q.push({w1, id1});
        ans.pb({id2, id1});
      } else {
        used[id1] = true;
        w1 -= w2;
        if (w1 > 0) q.push({w1, id1});
        ans.pb({id1, id2});
      }
    }
    if (SZ(q) == 1) {
      dbg(q.top());
      cout << "-1\n";
      return;
    }
    cout << SZ(ans) << '\n';
    for (auto [x, y] : ans) {
      cout << x << ' ' << y << '\n';
    }
    return;
  }
  int p1 = idx - 1, p2 = p1 - m + 1;
  For(i, 1, p2) { ans.pb({a[i].f2, a[i + 1].f2}); }
  For1(i, idx, n) { ans.pb({a[i].f2, a[i - m].f2}); }

  cout << SZ(ans) << '\n';
  for (auto [x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
}
