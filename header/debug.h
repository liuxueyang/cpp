#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <vector>

using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

#if defined(MYNOCOLOR)
#define _BEGIN_COLOR ""
#define _END_COLOR ""
#else
#define _BEGIN_COLOR "\e[91m"
#define _END_COLOR "\e[39m"
#endif  // endof defined

template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}

template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}

void _print() { cerr << "]\n"; }

template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}

template <typename ForwardIterator>
void dbgr(ForwardIterator begin, ForwardIterator end) {
  cerr << _BEGIN_COLOR << "[";
  ForwardIterator it = begin;
  while (it != end) {
    if (it != begin) cerr << ", ";
    __print(*it);
    it++;
  }
  cerr << "]" << _END_COLOR << '\n';
}

#define dbg(...)                                                              \
  cerr << _BEGIN_COLOR << __func__ << ":" << __LINE__ << " [" << #__VA_ARGS__ \
       << "] = [";                                                            \
  _print(__VA_ARGS__);                                                        \
  cerr << _END_COLOR

#define dbgi(x) cerr << _BEGIN_COLOR << x << ' ' << _END_COLOR
#define dbgI(x) cerr << _BEGIN_COLOR << x << ' ' << _END_COLOR << '\n'
#define dbgln() cerr << '\n'

// Beginning of LeetCode section
#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode* next) : val(val), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

void PrePrintLCTree(TNP root) {
  if (!root) return;
  dbgi(root->val);
  PrePrintLCTree(root->left);
  PrePrintLCTree(root->right);
}

class LCCodec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) return "";

    vector<TNP> a;
    a.push_back(root);
    string ans;

    while (!a.empty()) {
      vector<TNP> b;

      string tmp;
      for (auto x : a) {
        if (!ans.empty()) {
          ans += ',';
        }

        if (x)
          ans += to_string(x->val);
        else
          ans += "null";
      }

      bool ok{false};
      for (auto x : a) {
        if (x) {
          b.push_back(x->left);
          b.push_back(x->right);

          if (x->left || x->right) {
            ok = true;
          }
        }
      }

      if (ok)
        a = std::move(b);
      else
        a = {};
    }

    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<TNP> a;
    int n = int(data.size());
    vector<string> b;

    if (!n) return nullptr;

    string t;
    for (auto x : data) {
      if (x == ',') {
        b.push_back(t);
        t = "";
      } else
        t += x;
    }
    b.push_back(t);

    for (auto x : b) {
      if (x == "null")
        a.push_back(nullptr);
      else
        a.push_back(new TN(stoi(x)));
    }

    int m = int(a.size());
    int i = 0, j = 1;

    while (i < m) {
      while (i < m && !a[i]) ++i;
      if (i >= n) break;

      if (j < m) a[i]->left = a[j++];
      if (j < m) a[i]->right = a[j++];
      ++i;
    }

    return a[0];
  }
};

LNP CreateList(std::vector<int> a) {
  LN *du{new LN(0)}, *cur{}, *pre{du};

  for (auto x : a) {
    cur = new LN(x);
    pre->next = cur;
    pre = cur;
  }

  auto res = du->next;
  delete du;
  return res;
}

void PrintList(LNP head) {
  while (head) {
    dbgi(head->val);
    head = head->next;
  }
  dbgln();
}
// End of LeetCode section

#endif  // DEBUG_H_
