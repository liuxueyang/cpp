// Date: Fri Jul 21 19:13:31 2023

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
#define RofE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(),(a).end()
#define SZ(a) int((a).size())

#ifdef _DEBUG
#define debug1(x) cout << #x" = " << x << "\n";
#define debug2(x,y) cout << #x" = " << x << " "#y" = " << y << "\n";
#define debug3(x,y,z) cout << #x" = " << x << " "#y" = " << y << " "#z" = " << z << "\n";
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


const int N = 10010;
int n, d[N][3];
VI son[N];

void dp(int u, int fa) {
  int len = SZ(son[u]);

  d[u][2] = 0;
  d[u][1] = 1;
  d[u][0] = n;                  // Initialization can not be INF

  For(i, 0, len) {
    int v = son[u][i];
    if (v == fa) continue;

    dp(v, u);

    d[u][2] += d[v][0];
    d[u][1] += min(d[v][2], d[v][1]);
  }

  For(i, 0, len) {
    int v = son[u][i];
    if (v == fa) continue;

    d[u][0] = min(d[u][0], d[u][2] - d[v][0] + d[v][1]);
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("1218.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (cin >> n) {
    For1(i, 1, n) son[i] = {};
    memset(d, 0, sizeof d);

    For(i, 0, n - 1) {
      int a, b;
      cin >> a >> b;
      son[a].pb(b);
      son[b].pb(a);
    }

    dp(1, 0);

    cout << min(d[1][1], d[1][0]) << "\n";

    int x;
    cin >> x;
    if (x == -1) break;
  }

  return 0;
}
