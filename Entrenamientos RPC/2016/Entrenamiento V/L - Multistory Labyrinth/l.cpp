#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
char g[MAXN][MAXN][MAXN];
int d[MAXN][MAXN][MAXN];
int n, m, h;
int srcI, srcJ, srcK;
int destI, destJ, destK;

int dx [] = { 0, -1, 0, 1, 0, 0 };
int dy [] = { -1, 0, 1, 0, 0, 0 };
int dk [] = { 0, 0, 0, 0, 1, -1 };

struct p {
  int i, j, k;
  p() {}
  p(int _i, int _j, int _k) : i(_i), j(_j), k(_k) { }  
};

bool can_go(int curI, int curJ, int curK, int nextI, int nextJ, int nextK) {
  if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m || nextK < 0 || nextK >= h) return false;
  if (g[nextI][nextJ][nextK] == '#') return false;
  if (curK != nextK) {
    if (g[curI][curJ][curK] == '-' && g[nextI][nextJ][nextK] == '-') return true;
    else return false; 
  }
  return true;
}


int
bfs() {
  for (int k = 0; k < h; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) d[i][j][k] = -1; 
    } 
  }
  queue <p> q;
  q.push(p(srcI, srcJ, srcK));
  d[srcI][srcJ][srcK] = 0;
  while (!q.empty()) {
    p cur = q.front(); q.pop();
    int curI, curJ, curK;
    curI = cur.i, curJ = cur.j, curK = cur.k;
    for (int k = 0; k < 6; ++k) {
      int nextI, nextJ, nextK;
      nextI = curI + dx[k], nextJ = curJ + dy[k], nextK = curK + dk[k];
      if (can_go(curI, curJ, curK, nextI, nextJ, nextK)) {
        if (d[nextI][nextJ][nextK] == -1) {
          d[nextI][nextJ][nextK] = d[curI][curJ][curK] + 1;
          if (nextI == destI && nextJ == destJ && nextK == destK) return d[destI][destJ][destK];
          q.push(p(nextI, nextJ, nextK)); 
        }
      }
    }
  }
  return d[destI][destJ][destK];
}

int
main() {
  while (cin >> n >> m >> h && n) {
    for (int k = 0; k < h; ++k) {
      for (int i = 0; i < n; ++i) {
        string ln; cin >> ln;
        for (int j = 0; j < m; ++j) {
          g[i][j][k] = ln[j];
          if (ln[j] == 'S') srcI = i, srcJ = j, srcK = k; 
          else if (ln[j] == 'E') destI = i, destJ = j, destK = k;
        }
      }
    }
    cout << bfs() << endl;
  }
  return 0;
}
