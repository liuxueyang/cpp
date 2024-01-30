// Date: Tue Aug  1 19:39:09 2023

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


const int N = 4010, M = 16000003;
ll a[4][N], n, tc;
ll h[M], e[M], ne[M], val[M], idx;

void init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(ne, -1, sizeof ne);
}

void insert(ll x, ll y) {
  int k = (x % M + M) % M;
  e[idx] = x;
  ne[idx] = h[k];
  val[idx] = y;
  h[k] = idx++;
}

bool check(ll x) {
  int k = (x % M + M) % M;
  for (int i = h[k]; i != -1; i = ne[i]) {
    if (x == e[i]) {
      return true;
    }
  }
  return false;
}

void incr(ll x) {
  int k = (x % M + M) % M;
  for (int i = h[k]; i != -1; i = ne[i]) {
    if (x == e[i]) {
      val[i]++;
      break;
    }
  }
}

ll get(ll x) {
  int k = (x % M + M) % M;
  for (int i = h[k]; i != -1; i = ne[i]) {
    if (x == e[i]) {
      return val[i];
    }
  }

  return 0;
}

int main(void)
{
#ifdef _DEBUG
  freopen("1152.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> tc;
  while (tc--) {
    cin >> n;
    For(i, 0, n) {
      For(j, 0, 4) {
        cin >> a[j][i];
      }
    }

    init();

    For(i, 0, n) {
      For(j, 0, n) {
        ll sum = a[0][i] + a[1][j];
        auto t = check(sum);
        if (!t) insert(sum, 1);
        else incr(sum);
      }
    }

    ll res = 0;
    For(i, 0, n) {
      For(j, 0, n) {
        ll ta = a[2][i] + a[3][j];
        auto t = check(-ta);
        if (t) res += get(-ta);
      }
    }

    cout << res << '\n';
    if (tc) cout << '\n';
  }

  return 0;
}
