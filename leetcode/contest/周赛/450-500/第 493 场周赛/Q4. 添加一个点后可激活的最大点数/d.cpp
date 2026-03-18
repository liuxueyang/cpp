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
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998'244'353;
const ll INFL = 0x3f3f3f3f'3f3f3f3f;
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
istream& operator>>=(istream& is, vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    is >> a[i];
  }
  return is;
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

// For LeetCode
#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*
// End of LeetCode

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

const int N = 200100;
int n, sz[N], fa[N];
int Find(int u) { return u == fa[u] ? u : (fa[u] = Find(fa[u])); }
void Union(int u, int v) {
  int ru = Find(u), rv = Find(v);
  if (ru == rv) return;
  if (sz[ru] < sz[rv]) swap(ru, rv);
  sz[ru] += sz[rv];
  fa[rv] = ru;
}

class Solution {
 public:
  VI b;

  int get(int x) { return lower_bound(all(b), x) - b.begin() + 1; }
  void Init() {
    For1(i, 1, n) {
      sz[i] = 1;
      fa[i] = i;
    }
  }

  int maxActivated(vector<vector<int>>& a) {
    b = {};
    for (auto& vec : a) {
      b.pb(vec[0]);
      b.pb(vec[1]);
    }
    sort(all(b));
    b.resize(distance(b.begin(), unique(all(b))));
    n = SZ(a);
    Init();

    map<int, int> mpx, mpy;

    For(i, 0, n) {
      auto& vec = a[i];
      int x = vec[0], y = vec[1], x1 = get(x), y1 = get(y);
      int idx = i + 1;
      if (has(mpx, x1)) {
        Union(idx, mpx[x1]);
      }
      if (has(mpy, y1)) {
        Union(idx, mpy[y1]);
      }

      mpx[x1] = idx;
      mpy[y1] = idx;
    }

    int ans = 1;
    For(i, 0, n) { Find(i + 1); }

    set<int> vis;
    For1(i, 1, n) {
      int u = Find(i);
      vis.insert(u);
    }
    VI arr;
    for (auto u : vis) {
      arr.pb(sz[u]);
    }
    sort(all(arr), greater<int>());
    ans += arr[0];
    if (SZ(arr) > 1) ans += arr[1];
    return ans;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  int n, m;
  cin >> n >> m;
  VVI arr(n, VI(m));
  For(i, 0, n) { cin >> arr[i]; }
  auto res = a.maxActivated(arr);
  cout << res << '\n';

  return 0;
}

#endif