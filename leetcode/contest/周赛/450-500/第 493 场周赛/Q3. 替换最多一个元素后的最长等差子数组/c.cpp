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

class Solution {
 public:
  int longestArithmetic(vector<int>& a) {
    int n{SZ(a)};
    VI pre(n), suf(n);
    pre[0] = 1;
    pre[1] = 2;
    For(i, 2, n) {
      if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) {
        pre[i] = pre[i - 1] + 1;
      } else {
        pre[i] = 2;
      }
    }
    suf[n - 1] = 1;
    suf[n - 2] = 2;
    Rof(i, 0, n - 2) {
      if (a[i + 1] - a[i] == a[i + 2] - a[i + 1]) {
        suf[i] = suf[i + 1] + 1;
      } else {
        suf[i] = 2;
      }
    }

    int ans = 3;
    for (int i = 1; i + 1 < n; i++) {
      if (a[i] - a[i - 1] == a[i + 1] - a[i]) {
        ckmax(ans, pre[i] + suf[i] - 1);
      }
      ckmax(ans, suf[i] + 1);
      ckmax(ans, pre[i] + 1);
    }

    for (int i = 1; i + 1 < n; i++) {
      int d1 = INF, d2 = INF;
      if (i - 2 >= 0) d1 = a[i - 1] - a[i - 2];
      if (i + 2 < n) d2 = a[i + 2] - a[i + 1];
      int t2d = a[i + 1] - a[i - 1];
      if (d1 == d2) {
        if (t2d == d1 * 2) {
          ckmax(ans, pre[i - 1] + suf[i + 1] + 1);
        }
      } else {
        if (t2d == 2 * d2) {
          ckmax(ans, suf[i + 1] + 2);
        }
        if (t2d == 2 * d1) {
          ckmax(ans, pre[i - 1] + 2);
        }
      }
    }

    return ans;
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
  auto res = a.longestArithmetic(arr);
  cout << res << '\n';

  return 0;
}

#endif