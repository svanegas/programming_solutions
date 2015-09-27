#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

set <int> g[MAXN];
vector <int> seq;
int occ[MAXN];

void
connect(int i, int j) {
  g[i].insert(j);
  g[j].insert(i);
}

int
main() {
  string line;
  bool first = true;
  while (getline(cin, line)) {
    if (!first) puts("*");
    first = false;
    seq.clear();
    stringstream ss(line);
    int num;
    while (ss >> num) seq.push_back(num);

    int n = seq.size() + 2;
    for (int i = 0; i <= n; ++i) {
      occ[i] = 0;
      g[i].clear();
    }

    bool can = true;
    for (int i = 0; i < n - 2 && can; ++i) {
      can &= seq[i] < n;
      occ[seq[i]]++;
    }

    priority_queue <int, vector <int>, greater <int> > leaves;
    for (int i = 0; i < n && can; ++i) {
      if (occ[i] == 0) leaves.push(i);
    }

    for (int i = 0; i < n - 2 && can; ++i) {
      if (leaves.empty()) {
        can = false;
        break;
      }
      int leaf = leaves.top(); leaves.pop();
      int next = seq[i];
      connect(leaf, next);
      occ[next]--;
      if (occ[next] == 0) leaves.push(next);
    }

    if (can) {
      if (seq.back() != n - 1) connect(seq.back(), n - 1);
      else connect(seq.back(), n - 2);
      printf("%d\n", n);
      for (int i = 0; i < n; ++i) {
        set <int> :: iterator it;
        for (it = g[i].begin(); it != g[i].end(); ++it) {
          if (it != g[i].begin()) printf(" ");
          printf("%d", *it);
        }
        puts("");
      }
    }
    else puts("impossible");
  }
  return 0;
}
