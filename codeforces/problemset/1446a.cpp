// Date: Mon Dec 11 21:10:36 2023

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
int t, n;
pair<ll, int> a[N], b[N];
ll w;

int main(void) {
#ifdef _DEBUG
  freopen("1446a.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n >> w;

    For1(i, 1, n) {
      cin >> a[i].f1;
      a[i].f2 = i;
    }

    int len = 0;
    sort(a + 1, a + n + 1);

    ll top = (w + 1) / 2;
    VI res;

    For1(i, 1, n) {
      if (a[i].f1 > w)
        continue;
      if (a[i].f1 <= w && a[i].f1 >= top) {
        res.pb(a[i].f2);
        break;
      }
      b[++len] = a[i];
    }

    if (nonempty(res)) {
      cout << SZ(res) << '\n';
      for (auto x : res) {
        cout << x << ' ';
      }
      cout << '\n';
      continue;
    }

    bool flag = false;
    ll sum = 0, right = -1;
    For1(i, 1, len) {
      sum += b[i].f1;
      if (sum <= w && sum >= top) {
        flag = true;
        right = i;
        break;
      }
    }

    if (!flag)
      cout << "-1\n";
    else {
      cout << right << '\n';

      using PLI = pair<ll, int>;
      sort(b + 1, b + right + 1,
           [&](const PLI &x, const PLI &y) { return x.f2 < y.f2; });

      For1(i, 1, right) { cout << b[i].f2 << ' '; }
      cout << '\n';
    }
  }

  return 0;
}
