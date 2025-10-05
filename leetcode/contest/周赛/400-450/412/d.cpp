// Date: Sun Aug 25 10:34:16 2024

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

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998'244'353;
const ll INFL = 0x3f3f3f3f'3f3f3f3f;
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

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

// For LeetCode
#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *

#ifdef _DEBUG
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#endif
// End of LeetCode

class Solution {
public:
  bool check(string s, string t) {
    int n = SZ(s), m = SZ(t);
    if (n < m) {
      swap(n, m);
      swap(s, t);
    }
    if (n > m) {
      t = string(n - m, '0') + t;
    }

    VI dif;
    For(i, 0, n) {
      if (s[i] != t[i]) {
        dif.pb(i);
      }
    }

    if (dif.empty())
      return true;

    if (SZ(dif) <= 3) {
      string s1, t1;
      for (auto x : dif) {
        s1 += s[x];
        t1 += t[x];
      }
      sort(all(s1));
      sort(all(t1));
      return s1 == t1;
    } else if (SZ(dif) == 4) {
      string s1, t1;
      for (auto x : dif) {
        s1 += s[x];
        t1 += t[x];
      }
      int res{};
      For(i, 0, 4) {
        if (s1[i] != t1[i]) {
          bool ok = false;
          For(j, i + 1, 4) {
            if (s1[i] == t1[j]) {
              res++;
              swap(t1[i], t1[j]);
              ok = true;
              break;
            }
          }
          if (!ok)
            return false;
        }
      }
      return (res <= 2);
    }
    return false;
  }

  int countPairs(vector<int> &a) {
    int n = SZ(a);

    vector<string> a1;
    for (auto &x : a) {
      a1.pb(to_string(x));
    }

    int ans{};
    For(i, 0, n) {
      For(j, 0, i) {
        if (check(a1[i], a1[j])) {
          dbg(i, j, a1[i], a1[j]);
          ans++;
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
  _m_gen64.seed(Pr);

  Solution a;

  // VI v{8, 12, 5, 5, 14, 3, 12, 3, 3, 6, 8, 20, 14, 3, 8};
  // int ans = a.countPairs(v);
  // dbg(ans);

  VI v{1023, 2310, 2130, 213};
  int ans = a.countPairs(v);
  dbg(ans);

  v = VI{1, 10, 100};
  ans = a.countPairs(v);
  dbg(ans);

  // v = VI{226726, 387862, 880512, 611522, 343461, 420841, 334461, 10813,
  // 226726,
  //        334461, 80113,  314364, 10813,  163067, 134364, 332548, 413463,
  //        343416, 236429, 164332, 566432, 226726, 334164, 343461, 143463,
  //        163229, 667555, 667555, 343461, 657565, 343461, 770521, 285866,
  //        930657, 236429, 502387, 313446, 334461, 12219,  163760, 144363,
  //        227626};
  // ans = a.countPairs(v);
  // dbg(ans);

  return 0;
}

#endif
