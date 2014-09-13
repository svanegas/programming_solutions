//Santiago Vanegas Gil.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef pair <int, vector <vector <char> > > gamecito;
typedef long long ll;
const ll INF = 1LL << 60;
int n, m, k, w;
ll sum;
vector <gamecito> levels;
vector <gamecito> used;
vector <pair <int, int> > ans;

ll
getDiff(gamecito lvl1, gamecito lvl2) {
  ll diff = 0LL;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      diff += (lvl1.second[i][j] != lvl2.second[i][j]); 
    }
  } 
  return diff;
}

int
main() {
  printf("Time Limit");
  return 0;
  sum = 0;
  //cin >> n >> m >> k >> w;
  scanf("%d %d %d %d", &n, &m, &k, &w);
  for (int l = 0; l < k; l++) {
    vector <vector <char> > game;
    for (int i = 0; i < n; i++) {
      char sRow[m]; scanf("%s", sRow);
      vector <char> row;
      for (int j = 0; j < m; j++) {
        row.push_back(sRow[j]);
      }
      game.push_back(row);
    }
    levels.push_back(gamecito(l, game));
  }
  
  while (!levels.empty()) {
    ll minCost = INF;
    int absIndexMin = -1;
    int absIndexTaken = -1;
    int toDelete = -1;
    for (int l = 0; l < levels.size(); l++) {
      ll partialMin = n * m;
      int indexMin = levels[l].first;
      int takenMin = -1;
      for (int o = 0; o < used.size(); o++) {
        ll cost = getDiff(levels[l], used[o]);
        cost *= (w * 1LL);
        if (cost < partialMin) {
          partialMin = cost;
          indexMin = levels[l].first;
          takenMin = used[o].first;
        }
      }
      if (partialMin < minCost) {
        toDelete = l;  
        minCost = partialMin;
        absIndexMin = indexMin;
        if (takenMin == -1) absIndexTaken = 0; 
        else absIndexTaken = takenMin + 1;
      }
    }
    
    sum += minCost;
    ans.push_back(make_pair(absIndexMin + 1, absIndexTaken));
    used.push_back(levels[toDelete]);
    levels.erase(levels.begin() + toDelete);
  }
  
  printf("%d\n", sum);
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
