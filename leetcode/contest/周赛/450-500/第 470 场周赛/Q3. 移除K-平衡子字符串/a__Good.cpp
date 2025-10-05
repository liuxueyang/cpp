#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string removeSubstring(string s, int K) {
    string ans;
    typedef pair<int, int> pii;
    vector<pii> vec = {{0, 0}};
    for (char c : s) {
      if (c == '(') {
        if (ans.empty() || ans.back() == ')')
          vec.push_back({1, 0});
        else {
          vec.push_back(vec.back());
          vec.back().first++;
        }
      } else {
        vec.push_back(vec.back());
        vec.back().second++;
      }
      ans.push_back(c);
      while (vec.back().first >= K && vec.back().second >= K) {
        for (int i = 1; i <= K * 2; i++) ans.pop_back(), vec.pop_back();
      }
    }
    return ans;
  }
};

// https://leetcode.cn/discuss/post/3798458/di-470-chang-zhou-sai-by-leetcode-ne73/comments/3136729/
