// Date: Tue Aug 29 20:22:44 2023

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

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *

#define For(i, a, b) for (int i = int(a); i < int(b); ++i)
#define Rof(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define For1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define Rof1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define ForE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())

#ifdef _DEBUG
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif

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

int n, t;

int main(void) {
#ifdef _DEBUG
  freopen("1788b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> n;

    VI a;
    while (n) {
      a.pb(n % 10);
      n /= 10;
    }

    reverse(all(a));
    int len = SZ(a);
    VI b(len), c(len);
    int mark = 1;

    For(i, 0, len) {
      if (a[i] % 2 == 0) {
        b[i] = c[i] = a[i] / 2;
      } else {
        if (mark ^= 1) {
          b[i] = (a[i] + 1) / 2;
          c[i] = (a[i] - 1) / 2;
        } else {
          c[i] = (a[i] + 1) / 2;
          b[i] = (a[i] - 1) / 2;
        }
      }
    }

    bool flag = true;
    For(i, 0, len) {
      if (flag && b[i] == 0)
        continue;
      flag = false;
      cout << b[i];
    }
    if (flag)
      cout << 0;
    cout << ' ';

    flag = true;
    For(i, 0, len) {
      if (flag && !c[i])
        continue;
      flag = false;
      cout << c[i];
    }

    if (flag)
      cout << 0;
    cout << '\n';
  }

  return 0;
}
