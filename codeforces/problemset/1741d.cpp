// Date: Fri Dec 22 22:12:35 2023

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

template <typename t> istream &operator>>(istream &in, vector<t> &vec) {
  for (t &x : vec)
    in >> x;
  return in;
}

template <typename t> ostream &operator<<(ostream &out, vector<t> &vec) {
  int n = SZ(vec);
  For(i, 0, n) {
    out << vec[i];
    if (i < n - 1)
      out << ' ';
  }
  return out;
}

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

const int N = 300010;
int t, n, a[N];
ll res;

void dfs(int l, int r, int vl, int vr) {
  if (l >= r)
    return;

  if (res == -1)
    return;

  if (l + 1 == r) {
    if (a[l] > a[r]) {
      res++;
      swap(a[l], a[r]);
    }
    if (PII{vl, vr} != PII{a[l], a[r]}) {
      res = -1;
    }
    return;
  }

  int mid = (l + r) / 2, vmid = (vl + vr) / 2;

  if (a[l] >= vl && a[l] <= vmid) {
    dfs(l, mid, vl, vmid);
    dfs(mid + 1, r, vmid + 1, vr);
  } else {
    res++;
    dfs(l, mid, vmid + 1, vr);
    dfs(mid + 1, r, vl, vmid);
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("1741d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n;

    For1(i, 1, n) cin >> a[i];
    res = 0;
    dfs(1, n, 1, n);
    cout << res << '\n';
  }

  return 0;
}
