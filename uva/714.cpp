// Date: Sun Aug  6 19:17:51 2023

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


const int N = 510;
int k, m;
ll a[N];
VI b;

bool check(ll ta) {
  ll cur = 0;
  b = {};
  int len = 1;

  Rof1(i, 1, m) {
    if (a[i] > ta) return false;

    if (cur + a[i] <= ta) {
      if (i > k - len) {
        cur += a[i];
        continue;
      }
    }

    b.pb(i + 1);
    cur = a[i];
    len++;

    if (len > k) return false;
  }

  if (cur > ta) return false;

  reverse(all(b));
  return true;
}

int main(void)
{
#ifdef _DEBUG
  freopen("714.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    cin >> m >> k;
    For1(i, 1, m) {
      cin >> a[i];
    }

    ll l = 1, r = N * 1e7, mid;
    while (l < r) {
      mid = (l + r) / 2;

      if (check(mid)) r = mid;
      else l = mid + 1;
    }

    check(r);

    int front = 0, rear = 0;
    front = 1;

    if (SZ(b)) {
      int len = SZ(b);

      For(i, 0, len) {
        rear = b[i] - 1;

        For1(j, front, rear) {
          cout << a[j];
          if (j == rear) ;
          else cout << ' ';
        }
        cout << " / ";

        front = b[i];
      }

      front = b[len - 1];

      For1(j, front, m) {
        cout << a[j];
        if (j != m) cout << ' ';
      }
      cout << "\n";
    } else {
      For1(i, 1, m) {
        cout << a[i];
        if (i == m) cout << '\n';
        else cout << ' ';
      }
    }
  }

  return 0;
}
