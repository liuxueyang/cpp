#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>

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
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

#ifndef _WIN64
#define begin_color "\e[91m"
#define end_color "\e[39m"
#else
#define begin_color ""
#define end_color ""
#endif

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

template <typename ForwardIterator>
void dbgr(ForwardIterator begin, ForwardIterator end) {
  cerr << begin_color << "[";
  ForwardIterator it = begin;
  while (it != end) {
    if (it != begin)
      cerr << ", ";
    __print(*it);
    it++;
  }
  cerr << "]" << end_color << '\n';
}

#define dbg(x...)                                                              \
  cerr << begin_color << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
  _print(x);                                                                   \
  cerr << end_color;
#define dbgi(x) cerr << begin_color << x << ' ' << end_color;
#define dbgln() cerr << '\n';

#endif // DEBUG_H_
