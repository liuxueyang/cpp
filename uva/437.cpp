// Date: Sat Jul 15 18:22:20 2023

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

#define REP(i, a, b) for (int i = int(a); i < int(b); ++i)
#define PER(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define REP1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define PER1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define REPE(i, j) for (int i = h[j]; i != -1; i = ne[i])

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


const int N = 50;
struct point {
  int p[3];
};
int n, d[N][3];
point a[N];

bool check(int i, int k1, int j, int k2) {
  VI v1, v2;

  REP(k, 0, 3) {
    if (k1 != k) {
      v1.pb(a[i].p[k]);
    }
    if (k2 != k) {
      v2.pb(a[j].p[k]);
    }
  }

  return (v1[0] > v2[0] && v1[1] > v2[1]) || (v1[0] > v2[1] && v1[1] > v2[0]);
}

int dp(int i, int idx) {
  int &ans = d[i][idx];
  if (ans > 0) return ans;

  ans = a[i].p[idx];
  REP1(j, 1, n) {
    REP(k, 0, 3) {
      if (check(i, idx, j, k)) {
        ans = max(ans, dp(j, k) + a[i].p[idx]);
      }
    }
  }

  return ans;
}

int main(void)
{
#ifdef _DEBUG
  freopen("437.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int tc = 0;
  while (~scanf("%d", &n) && n) {
    tc++;
    REP1(i, 1, n) {
      scanf("%d%d%d", &a[i].p[0], &a[i].p[1], &a[i].p[2]);
    }

    memset(d, 0, sizeof d);

    int ans = 0;
    REP1(i, 1, n) {
      REP(j, 0, 3) {
        int tmp = dp(i, j);
        ans = max(ans, tmp);
      }
    }

    printf("Case %d: maximum height = %d\n", tc, ans);
  }

  return 0;
}
