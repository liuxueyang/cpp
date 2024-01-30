// Date: Wed Dec 13 21:40:02 2023

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
int t, n, a[N], b[N], c[N];
string s;

int main(void) {
#ifdef _DEBUG
  freopen("1607d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n;

    For(i, 0, n) { cin >> c[i]; }
    cin >> s;

    int len1 = 0, len2 = 0;
    For(i, 0, n) {
      if (s[i] == 'B')
        b[++len1] = c[i];
      else
        a[++len2] = c[i];
    }

    sort(b + 1, b + 1 + len1);
    sort(a + 1, a + 1 + len2);

    bool flag = true;
    For1(i, 1, len1) {
      if (b[i] < i) {
        flag = false;
        break;
      }
    }

    if (!flag) {
      cout << "NO\n";
      continue;
    }

    For1(i, 1, len2) {
      if (i + len1 < a[i]) {
        flag = false;
        break;
      }
    }

    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}
