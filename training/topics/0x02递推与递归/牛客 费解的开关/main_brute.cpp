#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
char mp[7][7];
int dx[5] = {0, 0, -1, 1, 0}, dy[5] = {1, -1, 0, 0, 0};  // 方位数组
void turn(int x, int y)  // 使坐标(x,y)周围的灯的状态改变
{
  for (int i = 0; i < 5; i++) {
    int a = x + dx[i];
    int b = y + dy[i];
    if (a >= 0 && a < 5 && b >= 0 && b < 5)
      mp[a][b] = '0' + '1' - mp[a][b];  // 使满足条件的灯的状态改变
  }
}
int work() {
  int res = INF;
  for (
      int k = 0; k < (1 << 5);
      k++)  // 第0行***有5个灯，每个灯都有按与不按两种选择，对应于k的2进制表示就是每位上的1/0。所以最后共有32种情况。我们将第一行所有按的情况都枚举一下，在第一行确定的情况下，剩下的行数，按与不按也就可以确定了
  {
    char re[7][7];
    int ans = 0;
    memcpy(re, mp, sizeof(mp));  // 把mp中的信息拷贝到re中
    for (int i = 0; i < 5; i++)
      if (k >> i & 1) {
        ans++;
        turn(0, i);  // 根据k的2进制表示信息我们可以知道需要将(0,i)上的灯按一下
      }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 5; j++)
        if (mp[i][j] == '0') {
          ans++;
          turn(i + 1, j);
        }
    }
    bool is_sucessful =
        true;  // 判断最后一行的灯是不是全部都是亮的，如果是的话就表示我们枚举的这个方案是成功的
    for (int i = 0; i < 5; i++)
      if (mp[4][i] == '0') {
        is_sucessful = false;
        break;
      }
    if (is_sucessful)  // 如果该方案成功的话我们需要维护一下最小值便于最后输出方案最小值
      res = min(res, ans);
    memcpy(mp, re,
           sizeof(mp));  // 再把mp中灯的开关情况恢复，便于接下来对k的枚举
  }
  if (res > 6) res = -1;
  return res;
}
int main() {
#if defined(_DEBUG) && !defined(_CPH)
  freopen("input.txt", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) cin >> mp[i][j];
    }
    cout << work() << endl;
  }
  return 0;
}

/*
作者：Trkly
链接：https://www.nowcoder.com/discuss/353148343582924800
来源：牛客网
*/
