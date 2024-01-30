// Date: Fri Jul 21 10:17:02 2023

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


const int N = 210;
int d[N][2], n;
bool f[N][2];
VI son[N];

void dp(int x) {
  if (son[x].empty()) {
    d[x][0] = 0;
    d[x][1] = 1;
    f[x][0] = f[x][1] = true;

    return;
  }

  d[x][0] = 0;
  d[x][1] = 1;

  f[x][1] = f[x][0] = true;

  For(i, 0, SZ(son[x])) {
    int child = son[x][i];
    dp(child);

    d[x][0] += max(d[child][1], d[child][0]);
    d[x][1] += d[child][0];

    f[x][1] = f[x][1] && f[child][0];

    if (f[x][0]) {
      if (d[child][1] == d[child][0]) f[x][0] = false;
      else if (d[child][1] > d[child][0] && !f[child][1]) f[x][0] = false;
      else if (d[child][0] > d[child][1] && !f[child][0]) f[x][0] = false;
    }
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("1220.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (cin >> n && n) {
    For1(i, 1, n) son[i] = {};

    map<string, int> m = {};
    string boss;
    cin >> boss;
    m[boss] = 1;

    int cnt = 2;

    For(i, 0, n - 1) {
      string a, b;
      cin >> a >> b;

      if (!has(m, a)) m[a] = cnt++;
      if (!has(m, b)) m[b] = cnt++;

      son[m[b]].pb(m[a]);
    }

    memset(d, 0, sizeof d);
    memset(f, false, sizeof f);

    dp(1);
    int ans = d[1][0];

    if (ans > d[1][1]) {
      cout << ans << (f[1][0] ? " Yes\n" : " No\n");
    } else if (ans < d[1][1]) {
      ans = d[1][1];
      cout << ans << (f[1][1] ? " Yes\n" : " No\n");
    } else {
      cout << ans << " No\n";
    }
  }

  return 0;
}
