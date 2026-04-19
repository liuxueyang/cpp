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

ll qmod(ll a, ll b, ll c = MOD) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % c;
    a = a * a % c;
    b >>= 1;
  }
  return res;
}

class Solution {
 public:
  int maxValue(vector<int>& nums1, vector<int>& nums0) {
    int n{SZ(nums1)};
    vector<PII> a;
    ll cnt = 0;
    For(i, 0, n) {
      if (nums0[i] == 0) {
        cnt += nums1[i];
        continue;
      }
      a.pb({nums1[i], nums0[i]});
    }
    sort(all(a), [](const PII& lh, const PII& rh) {
      if (lh.f1 != rh.f1) return lh.f1 > rh.f1;
      return lh.f2 < rh.f2;
    });
    ll res = 0;
    auto calc = [&](PII p) {
      auto [k1, k2] = p;
      ll tmp1 = qmod(2, k1 + k2);
      res = res * tmp1 % MOD;

      ll tmp2 = (qmod(2, k1) + MOD - 1) % MOD;
      tmp2 = tmp2 * qmod(2, k2) % MOD;

      res = (res + tmp2) % MOD;
    };
    calc(PII(cnt, 0));

    for (auto& p : a) {
      calc(p);
    }
    return res % MOD;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  int n;
  cin >> n;
  VI arr(n);
  cin >> arr;
  int m;
  cin >> m;
  VI brr(m);
  cin >> brr;
  auto res = a.maxValue(arr, brr);
  cout << res << '\n';

  return 0;
}

#endif
