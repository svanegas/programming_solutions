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
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef vector <vector <char> > printMat;
int n;
map <string, printMat> m;
vector <string> notes;

void
printScore(int lines) {
  for (int i = 1; i <= lines; ++i) {
    for (int j = 1; j <= 11; ++j) {
      for (int k = 1; k <= 4; ++k) {
        if (i == 1 && k == 1) printf("||");
        else if (k == 1) printf(" |");
        else printf("|");
        for (int l = 1; l <= 24; ++l) {
          int row = (i - 1) * 16;
          int col = (k - 1) * 4;
          int cell = (l - 1) / 6;
          int ind = row + col + cell;
          if (ind < n) {
            printMat matr = m[notes[ind]];
            printf("%c", matr[j-1][(l-1)%6]);
          }
          else {
            if (j % 2 == 1) printf(" ");
            else printf("-");
          }
        }
        if (k == 4) {
          printf("|");
          if (i == lines) printf("|");
        }
      }
      puts("");
    } 
  }
  puts("");
}

void
computePrintMatrix(string readNote) {
  printMat mat(11);
  for (int i = 0; i < mat.size(); ++i)
    for (int j = 0; j < 6; ++j)
      mat[i].push_back(i % 2 == 0 ? ' ' : '-'); 
  char key;
  key = readNote[0];
  if (key < 'E') key += 7;
  int row = 9 - (key - 'E');
  if (readNote.size() == 2) mat[row][0] = '#';
  mat[row][1] = 'x';
  mat[row][2] = '|';
  mat[row-1][2] = '|';
  mat[row-2][2] = '|';
  mat[row-2][3] = '\\';
  m[readNote] = mat;
}

void
buildMatrixes() {
  for (char c = 'A'; c <= 'G'; c++) {
    string s = "";
    s += c;
    computePrintMatrix(s);
    computePrintMatrix(s + "#");
  }
}

int
main() {
  buildMatrixes();
  while (cin >> n && n != -1) {
    int beats = (int) ceil(n / 16.0);
    notes.clear();
    for (int i = 0; i < n; ++i) {
      string s; cin >> s;
      notes.push_back(s);
    }
    printScore(beats);
  }
  return 0;
}
