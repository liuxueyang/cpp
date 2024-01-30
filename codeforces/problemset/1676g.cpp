// Date: Sat Dec 16 10:34:02 2023

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

const int N = 4010, M = 10010;
int h[N], w[N], b[N], t, n;
int e[M], ne[M], idx;
char color[N];

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(w, 0, sizeof w);
  memset(b, 0, sizeof b);
}

void Add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int x) {
  int w1 = 0, b1 = 0;

  for (int i = h[x]; i != -1; i = ne[i]) {
    int j = e[i];
    dfs(j);
    w1 += w[j];
    b1 += b[j];
  }

  if (color[x] == 'B')
    b1++;
  else
    w1++;

  w[x] = w1;
  b[x] = b1;
}

int main(void) {
#ifdef _DEBUG
  freopen("1676g.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n;

    Init();

    For1(i, 2, n) {
      int j;
      cin >> j;
      Add(j, i);
    }

    memset(color, 0, sizeof color);
    string s;
    cin >> s;
    For(i, 0, SZ(s)) { color[i + 1] = s[i]; }

    dfs(1);

    int res{};

    For1(i, 1, n) {
      if (w[i] == b[i])
        res++;
    }
    cout << res << '\n';
  }

  return 0;
}
