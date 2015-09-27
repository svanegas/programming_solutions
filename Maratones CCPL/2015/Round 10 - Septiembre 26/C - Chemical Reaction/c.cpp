// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

template <class T> string toStr(const T &x) {
  stringstream ss; ss << x; return ss.str();
}

typedef long long ll;
const int MAXM = 8;
const ll INF = 1LL << 60;
map <string, ll> memo;
int m, n;
struct mix {
  ll heat;
  char res;
  mix() {}
  mix(ll H, char R) : heat(H), res(R) { }
  bool operator < (const mix &than) const {
    return heat < than.heat;
  }
};
mix table[MAXM][MAXM];

int num(char c) {
  return c - '0';  
}

ll
solve(string tubes) {
  if (tubes.size() == 2) {
    int x = num(tubes[0]), y = num(tubes[1]);
    return min(table[x][y].heat, table[y][x].heat); 
  }
  sort(tubes.begin(), tubes.end());
  // ll val = convert(tubes);
  if (memo.count(tubes)) return memo[tubes];
  ll mini = INF;
  for (int i = 0; i < tubes.size(); ++i) {
    for (int j = 0; j < tubes.size(); ++j) {
      if (i == j) continue;
      string next;
      for (int k = 0; k < tubes.size(); ++k) {
        if (k != i && k != j) next += tubes[k];
      }
      int a = num(tubes[i]), b = num(tubes[j]);
      next += table[a][b].res;
      mini = min(mini, table[a][b].heat + solve(next));
    }
  }
  return memo[tubes] = mini;
}

void
fill_table() {
  char elem; ll heat;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%*c %c %lld", &elem, &heat);
      table[i][j] = mix(heat, elem);
    }
  }
}

int
main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memo.clear();
    scanf("%d", &m);
    fill_table();
    scanf("%d", &n);
    string tubes = "";
    for (int i = 0; i < n; ++i) {
      // End-line and char or space and char.
      char ki; scanf("%*c %c", &ki);
      tubes += ki;
    }
    printf("%lld\n", solve(tubes));
    scanf("%*s");
  }
  return 0;
}

