#include <bits/stdc++.h>
#include "debug.h"

using namespace std;
#define int long long
signed main() {
#ifndef _CPH
  freopen("input.txt", "r", stdin);
  freopen("std_output.txt", "w", stdout);
#endif

  int N, T;
  cin >> T;
  while (T--) {
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    vector<int> dp(N, 0);
    for (int i = 1; i < N; ++i) {
      if (A[i] - A[i - 1] > abs(B[i] - B[i - 1])) {
        dp[i] = 1 + dp[i - 1];
      }
    }
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        if (dp[i]) {
            dbg(i, dp[i]);
        }
      sum += dp[i];
    }
    cout << sum << endl;
  }

  return 0;
}
