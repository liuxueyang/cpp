// Date: Sun Aug  4 10:31:23 2024

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

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998'244'353;
const ll INFL = 0x3f3f3f3f'3f3f3f3f;
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

class neighborSum {
public:
  vector<VI> a;
  int n;

  neighborSum(vector<vector<int>> &g) {
    n = SZ(g);
    a = vector<VI>(n + 1, VI(n + 1, 0));
    For(i, 0, n) For(j, 0, n) a[i + 1][j + 1] = g[i][j];
  }
  bool check(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= n; }

  int adjacentSum(int v) {
    For1(i, 1, n) {
      For1(j, 1, n) {
        if (a[i][j] == v) {
          int i1, j1;
          int ans{};
          For(k, 0, 4) {
            dbg(i, j, k);
            i1 = i + dir[k][0], j1 = j + dir[k][1];
            if (check(i1, j1)) {
              ans += a[i1][j1];
              dbg(i1, j1, k, a[i1][j1]);
            }
          }
          return ans;
        }
      }
    }
    return 0;
  }

  int diagonalSum(int v) {
    For1(i, 1, n) {
      For1(j, 1, n) {
        if (a[i][j] == v) {
          int i1, j1;
          int ans{};
          For(k, 4, 8) {
            i1 = i + dir[k][0], j1 = j + dir[k][1];
            if (check(i1, j1)) {
              ans += a[i1][j1];
            }
          }
          return ans;
        }
      }
    }
    return 0;
  }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<VI> g1;
  g1 = vector<VI>{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
  neighborSum a(g1);

  int res = a.adjacentSum(1);
  dbg(res);

  return 0;
}

#endif
