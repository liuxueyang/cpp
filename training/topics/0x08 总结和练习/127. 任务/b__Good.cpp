#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> PII;

const int N = 100000 + 10;
int n, m;
PII a[N], b[N];
int main() {
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= m; i++) cin >> b[i].first >> b[i].second;

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    multiset<int> s;
    s.clear();
    long long cnt = 0, ans = 0;
    for (int i = m, j = n; i >= 1; i--) {
      // 将时间足够的机器放到set中
      while (j >= 1 && b[i].first <= a[j].first) s.insert(a[j--].second);

      multiset<int>::iterator it = s.lower_bound(b[i].second);
      if (it != s.end()) {
        cnt++;
        ans += 500 * b[i].first + 2 * b[i].second;
        s.erase(it);
      }
    }
    cout << cnt << " " << ans << endl;
  }
  return 0;
}

// 作者：墨染空
// 链接：https://www.acwing.com/solution/content/2546/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
