// Date: Sat Oct  7 12:52:28 2023

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

const int N{2000'10};
int t, n;
ll a[N];
bool vis[N];

bool check(int x) {
  return x >= 1 && x <= n;
}

int main(void) {
#ifdef _DEBUG
  freopen("1851d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> n;

    For1(i, 1, n - 1) { cin >> a[i]; }

    ll prev = 0, out = 0;
    bool flag {false}, res {true};
    memset(vis, false, sizeof vis);

    For1(i, 1, n - 1) {
      ll tmp = a[i] - prev;

      if (!check(tmp)) {
        if (flag) {
          res = false;
          break;
        } else {
          flag = true;
          out = tmp;
        }
      } else {
        if (vis[tmp]) {
          if (flag) {
            res = false;
            break;
          } else {
            flag = true;
            out = tmp;
          }
        } else {
          vis[tmp] = true;
        }
      }

      prev = a[i];
    }

    if (!res) cout << "NO\n";
    else {
      VI miss;

      For1(i, 1, n) {
        if (!vis[i]) miss.pb(i);
      }

      if (!flag || miss[0] + miss[1] == out) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}
