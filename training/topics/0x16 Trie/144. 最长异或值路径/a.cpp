#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
typedef pair<ll, ll> PLL;

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
#define NL cout << '\n';

template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}

void read(int& x) {
  bool neg = false;
  x = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') neg = true;
    ch = getchar();
  }
  if (neg) {
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + ('0' - ch);
      ch = getchar();
    }
  } else {
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + (ch - '0');
      ch = getchar();
    }
  }
}

void write(int x) {
  bool neg = false;
  if (x < 0) {
    neg = true;
    putchar('-');
  }
  static int sta[40];
  int top = 0;
  do {
    sta[top++] = x % 10;
    x /= 10;
  } while (x);
  if (neg)
    while (top) putchar('0' - sta[--top]);
  else
    while (top) putchar('0' + sta[--top]);
}

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x)
#define dbgi(x)
#define dbgln()
#endif

void Init();
void solve();

int main(void) {
#if defined(_DEBUG) && !defined(_CPH) && !defined(_SUB)
  freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}

const int N = 100100, M = 200100;
int n, d[N], idx, h[N], e[M], ne[M], w[M];
ll ans;

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

const int TN = N * 32;

struct Trie {
  int children[TN][2], tot;

  void init() {
    tot = 0;
    children[0][0] = children[0][1] = 0;
  }

  void insert(int n) {
    int cur = 0;
    Rof1(i, 0, 31) {
      int id = (n >> i) & 1;
      if (children[cur][id] == 0) {
        children[cur][id] = ++tot;
        // init node when created
        children[tot][0] = children[tot][1] = 0;
      }
      cur = children[cur][id];
    }
  }

  int query(int n) {
    int cur = 0, res = 0;

    Rof1(i, 0, 31) {
      int id = (n >> i) & 1;
      if (children[cur][1 - id]) {
        cur = children[cur][1 - id];
        res = res * 2 + (1 - id);
      } else {
        cur = children[cur][id];
        res = res * 2 + id;
      }
    }
    return res;
  }
};

void dfs(int u, int fa) {
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i], w0 = w[i];
    if (v == fa) continue;
    d[v] = d[u] ^ w0;
    dfs(v, u);
  }
}

Trie root;

void Init() {
  ans = idx = 0;
  For(i, 0, n) {
    h[i] = -1;
    d[i] = 0;
  }
  root.init();
}

void solve() {
  while (~scanf("%d", &n)) {
    Init();
    For(i, 0, n - 1) {
      int u, v, w;
      read(u), read(v), read(w);
      add(u, v, w);
      add(v, u, w);
    }
    dfs(0, -1);

    For(i, 0, n) {
      if (i) {
        int j = root.query(d[i]);
        ckmax(ans, (ll)j ^ d[i]);
      }
      root.insert(d[i]);
    }
    printf("%lld\n", ans);
  }
}
