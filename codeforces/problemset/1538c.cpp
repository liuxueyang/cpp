// Date: Sat Nov 25 19:10:08 2023

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
int t, n, l, r, a[N];

int find_left(int left, int right, int x) {
  if (left > right)
    return -1;
  int l = left, r = right, mid;

  while (l < r) {
    mid = (l + r) / 2;
    if (a[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }

  if (a[r] >= x)
    return r;
  return -1;
}

int find_right(int left, int right, int x) {
  if (left > right)
    return -1;
  int l = left, r = right, mid;

  while (l < r) {
    mid = (l + r + 1) / 2;
    if (a[mid] <= x)
      l = mid;
    else
      r = mid - 1;
  }

  if (a[l] <= x)
    return l;
  return -1;
}

int main(void) {
#ifdef _DEBUG
  freopen("1538c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n >> l >> r;

    For1(i, 1, n) { cin >> a[i]; }

    sort(a + 1, a + 1 + n);

    ll res = 0;
    For1(i, 1, n) {
      int left = find_left(i + 1, n, l - a[i]),
          right = find_right(i + 1, n, r - a[i]);
      if (left != -1 && right != -1) {
        res += right - left + 1;
      }
    }

    cout << res << '\n';
  }

  return 0;
}
