#include <bits/stdc++.h>

using namespace std;

const int MAXN = 220;
char board[MAXN][MAXN];
int ind, curI, curJ, minI, maxI, maxJ;

int dirI[] = { 0, 1, 0, -1 };
int dirJ[] = { 1, 0, -1, 0 };

void
updateLimits() {
  minI = min(minI, curI);
  maxI = max(maxI, curI);
  maxJ = max(maxJ, curJ);
}

int
main() {
  int t;
  cin >> t;
  printf("%d\n", t);
  while (t--) {
    string moves;
    cin >> moves;
    for (int i = 0; i <= 205; ++i) {
      for (int j = 0; j <= 205; ++j) {
        board[i][j] = '#';
      }
    }
    curI = 105, curJ = 0;
    ind = 0;
    minI = maxI = curI; maxJ = curJ;
    for (int i = 0; i < moves.size(); ++i) {
      board[curI][curJ] = '.';
      char mov = moves[i];
      int rInd = (ind + 1) % 4;
      int fInd = ind;
      int lInd = (4 + (ind - 1)) % 4;
      int bInd = (ind + 2) % 4;
      if (mov == 'R') {
        ind = rInd;
        curJ += dirJ[ind];
        curI += dirI[ind];
      }
      else if (mov == 'F') {
        board[curI + dirI[rInd]][curJ + dirJ[rInd]] = '#';
        curJ += dirJ[ind];
        curI += dirI[ind];
      }
      else if (mov == 'L') {
        board[curI + dirI[rInd]][curJ + dirJ[rInd]] = '#';
        board[curI + dirI[fInd]][curJ + dirJ[fInd]] = '#';
        ind = lInd;
        curJ += dirJ[ind];
        curI += dirI[ind];
      }
      else {
        board[curI + dirI[rInd]][curJ + dirJ[rInd]] = '#';
        board[curI + dirI[fInd]][curJ + dirJ[fInd]] = '#';
        board[curI + dirI[lInd]][curJ + dirJ[lInd]] = '#';
        ind = bInd;
        curJ += dirJ[ind];
        curI += dirI[ind];
      }
      updateLimits();
    }
    board[curI][curJ] = '.';
    printf("%d %d\n", maxI - minI + 3, maxJ + 2);
    for (int j = 0; j <= maxJ; ++j) printf("#");
    puts("#");
    for (int i = minI; i <= maxI; ++i) {
      for (int j = 0; j <= maxJ; ++j) {
        printf("%c", board[i][j] == '.' ? '.' : '#');
      }
      puts("#");
    }
    for (int j = 0; j <= maxJ; ++j) printf("#");
    puts("#");
  }
  return 0;
}
