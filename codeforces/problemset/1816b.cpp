// Date: Wed Aug 23 21:27:56 2023

#include <bits/stdc++.h>

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

const int N = 100010;
int a[5][N], n, t;

int main(void) {
#ifdef _DEBUG
  freopen("1816b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> n;

    int r = n, cur = n * 2, x1, y1, x2, y2;
    For1(j, 1, n / 2) {
      if (j & 1)
        x1 = 1;
      else
        x1 = 2;
      y1 = j;

      if (r % 2 == 0)
        x2 = 2;
      else
        x2 = 1;
      y2 = r;

      a[x1][y1] = cur--;
      a[x2][y2] = cur--;

      r--;
    }

    r = n;
    For1(j, 1, n / 2) {
      if (j & 1)
        x1 = 2;
      else
        x1 = 1;
      y1 = j;
      if (r % 2 == 0)
        x2 = 1;
      else
        x2 = 2;
      y2 = r;
      a[x1][y1] = cur--;
      a[x2][y2] = cur--;
      r--;
    }

    For1(i, 1, 2) {
      For1(j, 1, n) { cout << a[i][j] << ' '; }
      cout << '\n';
    }
  }

  return 0;
}
