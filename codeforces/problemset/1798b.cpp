// Date: Sun Sep  3 03:40:48 2023

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
                       {0, 1}, {0, -1},
                       {1, 0}, {-1, 0},
                       {1, 1}, {1, -1},
                       {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

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
#define all(a) (a).begin(),(a).end()
#define SZ(a) int((a).size())

#ifdef _DEBUG
#define debug1(x) cout << #x" = " << x << endl;
#define debug2(x,y) cout << #x" = " << x << " "#y" = " << y << endl;
#define debug3(x,y,z) cout << #x" = " << x << " "#y" = " << y << " "#z" = " << z << endl;
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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif


const int N = 50010;
int t, m, a[N];
VI b[N];

int main(void)
{
#ifdef _DEBUG
  freopen("1798b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> m;

    For1(i, 1, m) {
      cin >> a[i];

      b[i] = VI(a[i], 0);
      For(j, 0, a[i]) {
        cin >> b[i][j];
      }
    }

    set<int> vis;
    VI res;
    bool flag = true;

    Rof1(i, 1, m) {
      bool mark = false;

      for (auto x : b[i]) {
        if (!has(vis, x)) {
          mark = true;
          res.pb(x);
          break;
        }
      }

      if (!mark) {
        flag = false;
        break;
      }

      for (auto x : b[i]) vis.insert(x);
    }

    if (!flag) cout << -1 << '\n';
    else {
      reverse(all(res));
      for (auto x : res) cout << x << ' ';
      cout << '\n';
    }
  }

  return 0;
}
