// Date: Sat Dec 23 19:12:48 2023

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

const int N = 100010;
int a[N], n;

int primes[2 * N], cnt;
bool st[2 * N];

void get_primes(int n) {
  st[0] = st[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) {
      primes[cnt++] = i;
      for (ll j = ll(i) * i; j <= n; j += i) {
        st[j] = true;
      }
    }
  }
}

int check(int x) {
  int l = 0, r = cnt - 1, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (primes[mid] > x)
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int main(void) {
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  get_primes(2000'08);

  while (cin >> n) {
    map<int, int> m;
    For1(i, 1, n) {
      cin >> a[i];
      m[a[i]]++;
    }

    ll res = 0;

    for (auto [x, cnt] : m) {
      if (x == 0) {
        res += 2 * cnt;
      } else if (x == 1) {
        res += cnt;
      } else {
        if (!st[x])
          continue;

        int pos = check(x), v1 = primes[pos], v2 = primes[pos - 1];
        int gap = min(v1 - x, x - v2);
        res += gap * cnt;
      }
    }

    cout << res << '\n';
  }

  return 0;
}
