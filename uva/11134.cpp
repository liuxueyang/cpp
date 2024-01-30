// Date: Wed Aug  2 23:09:17 2023

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


const int N = 5010;

int sk;

struct point {
  int x1, y1, x2, y2;
  bool vis;
  int x, y, idx;

  bool operator <(const point &r) const {
    if (sk == 1) {
      return x2 < r.x2 || (x2 == r.x2 && x1 < r.x1);
    } else if (sk == 2) {
      return y2 < r.y2 || (y2 == r.y2 && y1 < r.y1);
    } else {
      return idx < r.idx;
    }
  }

  void set(int v) {
    if (sk == 1) x = v;
    else y = v;
    vis = true;
  }

  bool contain(int v) {
    if (sk == 1) {
      return v >= x1 && v <= x2;
    } else return v >= y1 && v <= y2;
  }
};
int n;
point a[N];

bool solve() {
  For(i, 0, n) a[i].vis = false;
  For1(i, 1, n) {
    bool flag = false;
    For(j, 0, n) {
      if (!a[j].vis && a[j].contain(i)) {
        flag = true;
        a[j].set(i);
        break;
      }
    }
    if (!flag) return false;
  }

  return true;
}

int main(void)
{
#ifdef _DEBUG
  freopen("11134.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (cin >> n && n) {
    For(i, 0, n) {
      cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
      a[i].idx = i;
    }

    bool mark = true;
    sk = 1;
    sort(a, a + n);
    mark = mark && solve();

    sk = 2;
    sort(a, a + n);
    mark = mark && solve();

    if (mark) {
      sk = 0;
      sort(a, a + n);
      For(i, 0, n) {
        cout << a[i].x << ' ' << a[i].y << '\n';
      }
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }

  return 0;
}
