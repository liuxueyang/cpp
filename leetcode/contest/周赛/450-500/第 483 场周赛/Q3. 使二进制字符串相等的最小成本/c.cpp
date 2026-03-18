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
ostream& operator<<(ostream& os, const vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    is >> a[i];
  }
  return is;
}

template <class T>
ostream& operator<<=(ostream& os, const vector<T>& a) {
  int n = int(a.size());
  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i == n - 1];
  }
  return os;
}

template <class T>
istream& operator>>=(istream& is, vector<T>& a) {
  for (auto& x : a) is >> x;
  return is;
}

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

// For LeetCode
#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

class Solution {
 public:
  long long minimumCost(string s, string t, int flipCost, int swapCost,
                        int crossCost) {
    int cnt1 = 0, cnt2 = 0, n = SZ(s), k = 0;
    dbg(s, t);

    For(i, 0, n) {
      if (s[i] != t[i]) {
        k++;
        if (s[i] == '1')
          cnt1++;
        else
          cnt2++;
      }
    }

    auto get = [&](int len, int cnt1, int cnt2) -> ll {
      ll res = 0;
      if (len & 1) res += flipCost, len--;

      // all flip
      ll tmp1 = 1LL * len * flipCost;

      // cross + swap
      ll tmp2 =
          1LL * abs(cnt1 - cnt2) / 2 * crossCost + 1LL * swapCost * len / 2;

      res += min(tmp1, tmp2);
      return res;
    };

    ll ans = get(k, cnt1, cnt2);
    // swap + ...
    int cnt3 = min(cnt1, cnt2);
    cnt1 -= cnt3, cnt2 -= cnt3;
    ll tmp3 = 1LL * cnt3 * swapCost + get(k - cnt3 * 2, cnt1, cnt2);
    ckmin(ans, tmp3);

    return ans;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  string s, t;
  cin >> s >> t;
  int c1, c2, c3;
  cin >> c1 >> c2 >> c3;
  auto res = a.minimumCost(s, t, c1, c2, c3);
  cout << res << '\n';

  return 0;
}

#endif