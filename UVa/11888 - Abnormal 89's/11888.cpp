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

const int MAXN = 200005;
//string s;
//char* s = new char[MAXN];
char s[MAXN];
int t;

bool
pal(int low, int high) {
  int n = (high - low) + 1;
  for (int i = low; i <= low + (n / 2); i++) {
    if (s[i] != s[high - (i - low)]) return false;
  }
  return true;
}

int
main() {
  scanf("%d", &t);
  getchar();
  while (t--) {
    //scanf("%s", s);
    //printf("Hola: %d\n", strlen(s));
    gets(s);
    //cin >> s;
    bool alindrome = false;
    for (int i = 0; i < strlen(s) - 1; i++) {
    //for (int i = 0; i < s.size() - 1; i++) {
      int i1, f1, i2, f2;
      i1 = 0; f1 = i;
      i2 = f1 + 1; f2 = strlen(s) - 1;
      //i2 = f1 + 1; f2 = s.size() - 1;
      if (pal(i1, f1) && pal(i2, f2)) {
        printf("%s\n", "alindrome");
        alindrome = true;
        break; 
      }
    }
    if (!alindrome) { 
      if (pal(0, strlen(s) - 1)) printf("%s\n", "palindrome");
      //if (pal(0, s.size() - 1)) printf("%s\n", "palindrome");
      else printf("%s\n", "simple");
    }
  }
  return 0;
}
