// Date: Sat Dec  2 18:01:42 2023

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

const int N = 200010;

int t, n, k, a[N];
VI b, c;

int solve(VI &b, ll &res) {
  int len = SZ(b), cnt = 0, maxb = 0;
  if (!len)
    return 0;

  maxb = b[0];
  int cur = b[0];
  cnt = 1;
  bool flag = true;

  if (cnt == k) {
    res += cur;
    flag = false;
    cnt = 0;
  }

  For(i, 1, len) {
    if (cnt == 0) {
      cur = b[i];
    }

    cnt++;

    if (cnt == k) {
      if (flag) {
        res += cur;
        flag = false;
      } else {
        res += cur * 2;
      }
      cnt = 0;
    }
  }

  if (cnt > 0 && cnt < k) {
    if (flag) {
      res += cur;
    } else {
      res += cur * 2;
    }
  }

  return maxb;
}

int main(void) {
#ifdef _DEBUG
  freopen("1585c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n >> k;
    b.clear();
    c.clear();

    For1(i, 1, n) {
      cin >> a[i];
      if (a[i] > 0)
        b.pb(a[i]);
      else if (a[i] < 0)
        c.pb(abs(a[i]));
    }

    sort(all(b), greater<int>());
    sort(all(c), greater<int>());

    ll res = 0;

    int lenb = SZ(b), maxb = 0;

    if (lenb) {
      maxb = solve(b, res);
    }

    int maxc = 0;
    int lenc = SZ(c);
    if (lenc) {
      maxc = solve(c, res);
    }

    if (lenb && lenc) {
      res += min(maxb, maxc);
    }

    cout << res << '\n';
  }

  return 0;
}
