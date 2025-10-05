// Date: Sun Jul 28 10:37:13 2024

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

const int N = 100100;
ll a[N], idx;

int primes[N], cnt;
bool st[N];

void get_primes(int n) {
  cnt = 0;
  memset(st, false, sizeof st);

  st[0] = st[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) {
      primes[cnt++] = i;
      for (ll j = ll(i) * i; j <= n; j += i) {
        st[j] = true;
      }
    }
  }
}

int get1(ll x) {
  int l = 1, r = idx, mid;
  while (l < r) {
    mid = (l + r + 1) / 2;
    if (a[mid] <= x)
      l = mid;
    else
      r = mid - 1;
  }

  if (a[l] <= x)
    return l;
  return 0;
}

class Solution {
public:
  int nonSpecialCount(int l, int r) {
    get_primes(1e5);

    idx = 0;

    For1(i, 2, 1e5) {
      if (!st[i]) {
        a[++idx] = ll(i) * i;
      }
    }

    int cnt = r - l + 1;
    int cntr = get1(r), cntl = get1(l - 1), cnt1 = cntr - cntl;

    dbg(cntr, cntl, cnt1);

    return cnt - cnt1;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  int res = a.nonSpecialCount(5, 7);
  dbg(res);

  res = a.nonSpecialCount(4, 16);
  dbg(res);

  res = a.nonSpecialCount(2, 4);
  dbg(res);

  return 0;
}

#endif
