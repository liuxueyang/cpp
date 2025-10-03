#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;

int n, m;
PII mchs[N], tasks[N];

int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) cin >> mchs[i].first >> mchs[i].second;
    for (int i = 0; i < m; i++) cin >> tasks[i].first >> tasks[i].second;
    sort(mchs, mchs + n);
    sort(tasks, tasks + m);
    multiset<int> ys;
    LL cnt = 0, res = 0;
    for (int i = m - 1, j = n - 1; i >= 0; i--) {
      while (j >= 0 && mchs[j].first >= tasks[i].first)
        ys.insert(mchs[j--].second);
      auto it = ys.lower_bound(tasks[i].second);
      if (it != ys.end()) {
        cnt++;
        res += 500 * tasks[i].first + 2 * tasks[i].second;
        ys.erase(it);
      }
    }
    cout << cnt << ' ' << res << endl;
  }
  return 0;
}

// 作者：yxc
// 链接：https://www.acwing.com/activity/content/code/content/27694/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
