#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k;
char s[N], t[N];

int main() {
#ifdef _DEBUG
#ifndef _CPH
  freopen("input.txt", "r", stdin);
#endif
#endif

  while (~scanf("%d %d", &n, &k)) {
    memset(s, 0, sizeof s);
    memset(t, 0, sizeof t);

    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      if (s[i] == '.')
        t[i] = '.';
      else if (s[i] == 'o') {
        t[i] = 'o';
        k--;
      } else {  // s[i] == '?'
        if (s[i - 1] == 'o' || s[i + 1] == 'o') {
          t[i] = s[i] = '.';
        }
      }
    }
    // k 代表还剩下需要多少个 o
    if (k == 0) {
      for (int i = 1; i <= n; i++) {
        if (s[i] == '?') t[i] = '.';
      }
    } else {
      int mx = 0, l = 0;
      for (int i = 1; i <= n + 1; i++) {
        if (s[i] == '?')
          l++;
        else {
          mx += (l + 1) / 2;
          l = 0;
        }
      }  // ....????
      if (mx == k) {
        int l = 0;
        for (int i = 1; i <= n + 1; i++) {
          if (s[i] == '?')
            l++;
          else {
            if (l & 1) {
              for (int j = 1; j <= l; j++) {
                t[i - j] = ".o"[j & 1];
                // o.o.o.o
              }
            } else {
              for (int j = 1; j <= l; j++) t[i - j] = '?';
            }
            l = 0;
          }
        }
      } else {
        for (int i = 1; i <= n; i++) {
          if (s[i] == '?') t[i] = '?';
        }
      }
    }
    puts(t + 1);
  }
  return 0;
}
