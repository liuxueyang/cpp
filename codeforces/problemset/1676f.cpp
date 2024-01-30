// Date: Sun Dec 10 11:26:31 2023

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
int a[N], t, n, k;

int main(void) {
#ifdef _DEBUG
  freopen("1676f.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n >> k;

    map<int, int> m;

    For1(i, 1, n) {
      cin >> a[i];
      m[a[i]]++;
    }

    VI b;
    for (auto &[x, y] : m) {
      if (y >= k)
        b.pb(x);
    }
    sort(all(b));
    int len = SZ(b);
    if (!len) {
      cout << "-1\n";
      continue;
    }

    int res = 1, cur = 0, l = 0, r = -1;
    int resl = b[0], resr = b[0];

    For(i, 1, len) {
      if (b[i] == b[i - 1] + 1) {
        r = i;
        cur = r - l + 1;
        if (cur > res) {
          res = cur;
          resl = b[l];
          resr = b[r];
        }
      } else {
        l = i;
      }
    }

    if (res != 0) {
      cout << resl << ' ' << resr << '\n';
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
