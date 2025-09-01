#include <algorithm>
#include <array>
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
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<bool> VB;
typedef vector<vector<bool>> VVB;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998'244'353;
const ll INFL = 0x3f3f3f3f'3f3f3f3f;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};
mt19937_64 _m_gen64;

const ull Pr = 131, Pr1 = 13331;

#define For(i, a, b) for (int i = int(a); i < int(b); ++i)
#define Rof(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define For1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define Rof1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define ForE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nemp(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define all1(a, len) (a + 1), (a + 1 + len)
#define SZ(a) int((a).size())
#define NL cout << '\n';

template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
}

template <class T>
istream &operator>>(istream &is, vector<T> &a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    is >> a[i];
  }
  return is;
}

template <class T>
ostream &operator<<=(ostream &os, const vector<T> &a) {
  int n = int(a.size());
  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i == n - 1];
  }
  return os;
}

template <class T>
istream &operator>>=(istream &is, vector<T> &a) {
  for (auto &x : a) is >> x;
  return is;
}

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

// For LeetCode
#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *

#ifdef _DEBUG

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
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
  string serialize(TreeNode *root) {
    if (!root) return "";

    vector<TNP> a;
    a.pb(root);
    string ans;

    while (nemp(a)) {
      vector<TNP> b;

      string tmp;
      for (auto x : a) {
        if (nemp(ans)) {
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
          b.pb(x->left);
          b.pb(x->right);

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
  TreeNode *deserialize(string data) {
    vector<TNP> a;
    int n = SZ(data);
    vector<string> b;

    if (!n) return nullptr;

    string t;
    for (auto x : data) {
      if (x == ',') {
        b.pb(t);
        t = "";
      } else
        t += x;
    }
    b.pb(t);

    for (auto x : b) {
      if (x == "null")
        a.pb(nullptr);
      else
        a.pb(new TN(stoi(x)));
    }

    int m = SZ(a);
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

#endif
// End of LeetCode

class LRUCache1 {
 public:
  list<pair<int, int>> lst;
  unordered_map<int, list<pair<int, int>>::iterator> mp;
  int cap;

  LRUCache1(int capacity) {
    lst = {};
    mp = {};
    cap = capacity;
  }

  int get(int key) {
    auto it = mp.find(key);
    if (it == mp.end()) return -1;

    pair<int, int> val = *it->second;
    lst.erase(it->second);
    lst.insert(lst.begin(), val);
    mp[key] = lst.begin();
    return val.second;
  }

  void put(int key, int value) {
    auto it = mp.find(key);
    if (it == mp.end()) {
      lst.insert(lst.begin(), pair<int, int>(key, value));
      mp[key] = lst.begin();
      if (lst.size() > cap) {
        auto it1 = prev(lst.end());
        auto [k, v] = *it1;
        mp.erase(k);
        lst.erase(it1);
      }
    } else {
      get(key);
      *lst.begin() = pair<int, int>(key, value);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

struct MListNode {
  int key, value;
  MListNode *next, *prev;

  MListNode(int key_, int value_)
      : key(key_), value(value_), next(nullptr), prev(nullptr) {}
  MListNode() : MListNode(0, 0) {}
};

struct List {
  MListNode *head, *tail;
  int sz;

  List() {
    head = new MListNode();
    tail = new MListNode();
    head->next = tail;
    tail->prev = head;
    sz = 0;
  }

  void push_front(MListNode *node) { insert(head, node); }
  void pop_back() { remove(tail->prev); }

  void remove(MListNode *node) {
    MListNode *pre = node->prev;
    MListNode *nxt = node->next;

    pre->next = nxt;
    nxt->prev = pre;
    delete node;
    sz--;
  }

  void insert(MListNode *pos, MListNode *node) {
    MListNode *nxt = pos->next;
    pos->next = node;
    node->prev = pos;

    node->next = nxt;
    nxt->prev = node;
    sz++;
  }
};

class LRUCache {
 public:
  int cap;
  List *lst;
  unordered_map<int, MListNode *> mp;

  LRUCache(int capacity) {
    cap = capacity;
    lst = new List();
    mp = {};
  }

  int get(int key) {
    auto it = mp.find(key);
    if (it == mp.end()) return -1;

    auto node = it->second;
    int value = node->value;
    lst->remove(node);

    MListNode *new_node = new MListNode(key, value);
    lst->push_front(new_node);
    mp[key] = new_node;
    return value;
  }

  void put(int key, int value) {
    auto it = mp.find(key);
    if (it == mp.end()) {
      MListNode *new_node = new MListNode(key, value);
      lst->push_front(new_node);
      mp[key] = new_node;
      if (lst->sz > cap) {
        MListNode *last_node = lst->tail->prev;
        mp.erase(last_node->key);
        lst->pop_back();
      }
    } else {
      get(key);
      mp[key]->value = value;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#ifdef _DEBUG

int main(void) {
  freopen("input.txt", "r", stdin);
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _m_gen64.seed(Pr);

  // Solution a;

  return 0;
}

#endif
