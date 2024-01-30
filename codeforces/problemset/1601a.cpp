// Date: Wed Dec 13 22:45:15 2023

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
int t, n, a[N], b[35];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(void) {
#ifdef _DEBUG
  freopen("1601a.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n;

    memset(b, 0, sizeof b);
    For1(i, 1, n) {
      cin >> a[i];
      For(j, 0, 31) {
        if ((1 << j) & a[i])
          b[j]++;
      }
    }

    int sum = 0;
    For(j, 0, 31) { sum += b[j]; }

    if (!sum) {
      For1(i, 1, n) { cout << i << ' '; }
      cout << '\n';
      continue;
    }

    int g = -1;
    For(j, 0, 31) {
      if (!b[j])
        continue;
      if (g == -1) {
        g = b[j];
        continue;
      }
      g = gcd(g, b[j]);
    }

    if (g == 1) {
      cout << "1\n";
    } else {
      VI res;
      for (int i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
          int j = g / i;
          if (j != i) {
            res.pb(i);
            res.pb(j);
          } else {
            res.pb(i);
          }
        }
      }
      sort(all(res));
      for (auto x : res) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}
