#include <bits/stdc++.h>

using namespace std;

struct wheel {
  int x, y, r;
  wheel () {}
  wheel (int X, int Y, int R) : x(X), y(Y), r(R) { }
};

double dist(wheel p1, wheel p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

const int MAXN = 1005;
vector <wheel> wheels;
vector <int> g[MAXN];
bool d[MAXN];
int ori[MAXN];

void
bfs(int s) {
  queue <int> q;
  q.push(s);
  d[s] = true;
  ori[s] = 1;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int i = 0; i < g[cur].size(); ++i) {
      int next = g[cur][i];
      if (!d[next]) {
        d[next] = true;
        ori[next] = 1 - ori[cur];
        q.push(next);
      }
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) {
    wheels.clear();
    int n; cin >> n;
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
      d[i] = false;
      ori[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
      int x, y, r;
      cin >> x >> y >> r;
      wheels.push_back(wheel(x, y, r));
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j) {
          double d = dist(wheels[i], wheels[j]);
          if (d - (wheels[i].r * 1.0) <= wheels[j].r * 1.0) {
            g[i].push_back(j);
            g[j].push_back(i);
          }
        }
      }
    }
    bfs(0);
    for (int i = 0; i < n; ++i) {
      if (d[i]) {
        int gcd = __gcd(wheels[i].r, wheels[0].r);
        int num = wheels[0].r/ gcd;
        int den = wheels[i].r / gcd;
        printf("%d", num);
        if (den != 1) printf("/%d", den);
        if (ori[i] == 1) puts(" clockwise");
        else puts(" counterclockwise");
      }
      else puts("not moving");
    }
  }
  return 0;
}
