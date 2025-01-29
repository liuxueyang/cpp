#include <bits/stdc++.h>
using namespace std;
int ans[1000];
string s;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int T, n, i, j, c;
  for (cin >> T; T > 0; T--) {
    cin >> n;
    for (i = 0; i < n; i++) ans[i] = -1;
    for (i = 0; i < n; i++) {
      cin >> s;
      c = 0;
      for (j = i + 1; j < s.length(); j++) c += s[j] - '0';
      for (j = n - 1; j > -1; j--) {
        if (ans[j] != -1) continue;
        if (c > 0)
          c--;
        else {
          ans[j] = i;
          break;
        }
      }
    }
    for (i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
    cout << '\n';
  }
  return 0;
}