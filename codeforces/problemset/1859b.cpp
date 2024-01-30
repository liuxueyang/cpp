// Date: Sat Dec  9 21:17:37 2023

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

const int N = 50010;
int t, n;
PII a[N];

int main(void) {
#ifdef _DEBUG
  freopen("1859b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n;

    int cnt, mb = 1e9 + 10;

    For1(i, 1, n) {
      cin >> cnt;
      VI tmp(cnt, 0);
      For(j, 0, cnt) { cin >> tmp[j]; }

      sort(all(tmp));
      a[i].f1 = tmp[0];
      a[i].f2 = tmp[1];
      mb = min(mb, a[i].f1);
    }

    sort(a + 1, a + n + 1, [&](const PII &x, const PII &y) {
      if (x.f2 < y.f2)
        return true;
      else if (x.f2 > y.f2)
        return false;
      return x.f1 < y.f1;
    });

    ll res = mb;

    For1(i, 2, n) { res += a[i].f2; }

    cout << res << '\n';
  }

  return 0;
}
