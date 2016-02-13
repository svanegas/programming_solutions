#include <bits/stdc++.h>

using namespace std;

int t, m;
bool tiles[5][105];
vector <pair <int, int> > indexes;

int
main() {
  cin >> t;
  while (t--) {
    indexes.clear();
    for (int i = 0; i <= 3; ++i) {
      for (int j = 0; j <= 100; ++j) {
        tiles[i][j] = false;
      }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int d; char c;
      scanf("%d%c", &d, &c);
      switch (c) {
        case 'b':
          tiles[0][d] = true;
          indexes.push_back(make_pair(0, d));
          break;
        case 'g':
          tiles[1][d] = true;
          indexes.push_back(make_pair(1, d));
          break;
        case 'r':
          tiles[2][d] = true;
          indexes.push_back(make_pair(2, d));
          break;
        case 'y':
          tiles[3][d] = true;
          indexes.push_back(make_pair(3, d));
          break;
      }
    }
    bool can = false;
    for (int k = 0; k < m && !can; ++k) {
      int x = indexes[k].first;
      int y = indexes[k].second;
      int count = 0;
      for (int i = y; i < y + 3 && i <= 100; ++i) {
        count += tiles[x][i];
      }
      can |= count >= 3;
      if (can) break;
      count = 0;
      for (int i = 0; i <= 3; ++i) {
        count += tiles[i][y];
      }
      can |= count >= 3;
    }
    if (can) puts("YES");
    else puts("NO");
  }
  return 0;
}
