/**
 *  author: xing huan liu kong
 *  created: 2025-02-28 19:56:15
 **/
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define point(x) fixed << setprecision(x)
using namespace std;

#define int long long
typedef pair<int, int> PII;
typedef array<int, 3> arr;

void solve() {
  string s;
  while (cin >> s) {
    int n = s.size();

    vector<int> a(26, 0);
    for (auto i : s) {
      a[i - 'a']++;
    }

    vector<PII> v;
    for (int i = 0; i < 26; i++) {
      if (a[i]) {
        v.push_back({i, a[i]});
      }
    }

    sort(v.begin(), v.end(), [&](PII x, PII y) { return x.second > y.second; });

    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].second == v[0].second)
        ans++;
      else
        break;
    }

    int l = 1, r = n;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (mid * (v[0].second - 1) + ans <= n)
        l = mid;
      else
        r = mid - 1;
    }

    string str(n, ' ');

    for (int i = 0, idx = 0; i < l; i++) {
      for (int j = i; j < n; j += l) {
        if (!v[idx].second) idx++;
        str[j] = char(v[idx].first + 'a');
        v[idx].second--;
      }
    }
    cout << l << endl;
    cout << str << endl;
  }
}

signed main(void) {
#ifdef _DEBUG
#ifndef _CPH
  freopen("input.txt", "r", stdin);
#endif
#endif

  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}