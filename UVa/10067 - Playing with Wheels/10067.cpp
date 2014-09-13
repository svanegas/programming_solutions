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

const int MAXN = 10000;
int t, f, n = 9999;
vector <int> source, target;
bool forb[MAXN];
vector <int> g[MAXN];
int d[MAXN];

int
getNum(vector <int> v) {
  int ans = 0;
  for (int i = 3; i >= 0; i--) {
    int digit = v[i];
    int power = (int)round(pow(10.0, (3.0 - i)));
    digit *= power;
    ans += digit;
  }
  return ans;
}

vector <int>
getVec(int num) {
  vector <int> ans;
  for (int i = 0; i < 4; i++) {
    int div = (int)round(pow(10.0, (3.0 - i)));
    ans.push_back((num / div) % 10);
  }
  return ans;
}

void
build() {
  for (int i = 0; i <= 9999; i++) { //Numbers
    vector <int> num = getVec(i);
    for (int j = 0; j < 4; j++) { //Wheels
      for (int k = -1; k < 2; k += 2) { //Direction
        int digit = num[j];
        digit += (10 + k);
        digit %= 10;
        vector <int> next = getVec(i);
        next[j] = digit;
        g[i].push_back(getNum(next));
      }
    } 
  }  
}

void
clean() {
  source.clear();
  target.clear();
  for (int i = 0; i < MAXN; i++) {
    forb[i] = false;
    d[i] = -1;
  }
}

void
bfs(int s) {
  queue <int> q;
  q.push(s);
  d[s] = 0;
  while (q.size() > 0) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < g[cur].size(); i++) {
      int next = g[cur][i];
      if (!forb[next] && d[next] == -1) {
        d[next] = d[cur] + 1;
        q.push(next); 
      } 
    } 
  }
}

int
main() {
  build();
  cin >> t;
  while (t--) {
    clean();
    for (int i = 0; i < 4; i++) {
      int xi; cin >> xi;
      source.push_back(xi);
    }
    for (int i = 0; i < 4; i++) {
      int xi; cin >> xi;
      target.push_back(xi);
    }
    bool can = true;
    cin >> f;
    for (int i = 0; i < f; i++) {
      vector <int> proh;
      for (int j = 0; j < 4; j++) {
        int xi; cin >> xi;
        proh.push_back(xi);  
      }
      int forbidden = getNum(proh);
      forb[forbidden] = true;
      if (forbidden == getNum(source) ||
          forbidden == getNum(target)) can = false;
    }
    if (can) bfs(getNum(source));
    cout << d[getNum(target)] << endl;
  }
  return 0;
}
