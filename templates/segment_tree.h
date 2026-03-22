#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

struct Tag {
  ll val;

  bool empty() const { return val == 0; }
  Tag operator+(const Tag &rh) const {
    Tag res{val + rh.val};
    return res;
  }
  void clear() { val = 0; }
};

struct Info {
  int len;
  ll val;

  Info operator+(const Info &rh) const {
    Info res{len + rh.len, val + rh.val};
    return res;
  }

  Info operator+(const Tag &t) const {
    Info res{len, val + 1LL * len * t.val};
    return res;
  }
};

struct Node {
  Info info;
  Tag tag;

  Node() : info{}, tag{} {}
  Node(ll val) : info{1, val}, tag{0} {}
};

template <typename V> struct SegmentTree {
  int n{0};
  vector<V> a{};

  vector<Node> seg{};

  explicit SegmentTree(vector<V> &a_) {
    n = int(a_.size());
    a = vector<V>(n + 1);
    copy(a_.begin(), a_.end(), a.begin() + 1);
    seg = vector<Node>(n * 4 + 10);
    build(1, 1, n);
  }

  void change(int pos, V val) {
    a[pos] = val;
    change(1, 1, n, pos, val);
  }
  void modify(int ql, int qr, Tag t) { modify(1, 1, n, ql, qr, t); }
  Info query(int ql, int qr) { return query(1, 1, n, ql, qr); }
  void add(int pos, V val) { modify(pos, pos, {val}); }

  static pair<int, int> child(int id) { return {id * 2, id * 2 + 1}; }

  void update(int id) {
    auto [lc, rc] = child(id);
    seg[id].info = seg[lc].info + seg[rc].info;
  }

  void build(int id, int l, int r) {
    if (l == r) {
      seg[id] = Node(a[l]);
      return;
    }

    int mid = (l + r) / 2;
    auto [lc, rc] = child(id);
    build(lc, l, mid);
    build(rc, mid + 1, r);
    update(id);
  }

  void push_down(int id) {
    Tag &t = seg[id].tag;
    if (t.empty())
      return;

    auto [lc, rc] = child(id);
    set_tag(lc, t);
    set_tag(rc, t);
    t.clear();
  }

  void set_tag(int id, Tag t) {
    seg[id].info = seg[id].info + t;
    seg[id].tag = seg[id].tag + t;
  }

  void change(int id, int l, int r, int pos, V val) {
    if (l == r) {
      seg[id] = Node(val);
      return;
    }

    push_down(id);
    int mid = (l + r) / 2;
    auto [lc, rc] = child(id);
    if (pos <= mid)
      change(lc, l, mid, pos, val);
    else
      change(rc, mid + 1, r, pos, val);
    update(id);
  }

  void modify(int id, int l, int r, int ql, int qr, Tag t) {
    if (l >= ql && r <= qr) {
      set_tag(id, t);
      return;
    }
    int mid = (l + r) / 2;
    auto [lc, rc] = child(id);
    push_down(id);
    if (qr <= mid)
      modify(lc, l, mid, ql, qr, t);
    else if (ql > mid)
      modify(rc, mid + 1, r, ql, qr, t);
    else {
      modify(lc, l, mid, ql, mid, t);
      modify(rc, mid + 1, r, mid + 1, qr, t);
    }
    update(id);
  }

  Info query(int id, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) {
      return seg[id].info;
    }
    int mid = (l + r) / 2;
    auto [lc, rc] = child(id);
    push_down(id);
    if (qr <= mid)
      return query(lc, l, mid, ql, qr);
    else if (ql > mid)
      return query(rc, mid + 1, r, ql, qr);
    else
      return query(lc, l, mid, ql, mid) + query(rc, mid + 1, r, mid + 1, qr);
  }
};

#endif
