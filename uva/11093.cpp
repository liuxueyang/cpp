// Date: Tue Aug  8 20:10:07 2023

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


const int N = 100010;
int a[N], n, T, vis[N], p[N], q[N];

int main(void)
{
#ifdef _DEBUG
  freopen("11093.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> T;
  For1(tc, 1, T) {
    cin >> n;
    For1(i, 1, n) {
      cin >> p[i];
    }
    For1(i, 1, n) {
      cin >> q[i];
    }

    fill(vis, vis + N, 0);
    int cur = 0, ans = -1;

    For1(i, 1, n) {
      cur += p[i];

      if (cur >= q[i] && !vis[i]) {
        vis[i] = 1;
        int j = i + 1;
        if (j == n + 1) j = 1;

        cur -= q[i];
        while (j != i && cur + p[j] >= q[j]) {
          cur += p[j];
          cur -= q[j];
          ++j;
          if (j == n + 1) j = 1;
          vis[j] = 1;
        }

        if (j == i) {
          ans = j;
          break;
        }
        i = j - 1;
        cur = 0;
      } else {
        vis[i] = 1;
        cur = 0;
      }
    }

    cout << "Case " << tc << ": ";
    if (ans == -1) cout << "Not possible\n";
    else cout << "Possible from station " << ans << "\n";
  }

  return 0;
}
