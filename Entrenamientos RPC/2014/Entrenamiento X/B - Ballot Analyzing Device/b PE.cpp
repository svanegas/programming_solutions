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

const double EPS = 1e-4;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

struct candidate {
  int id, votes;
  string name;
  candidate (int _id, string _name, int _votes) : id(_id), name(_name), votes(_votes) {}
  
  bool operator < (const candidate &than) const {
    if (votes < than.votes) return true;
    else if (votes == than.votes) {
      return id > than.id; 
    }
    else return false;
  }
};

int n, m;
vector <candidate> cand;
string trash;

int
main() {
  cin >> n >> m;
  getline(cin, trash);  
  for (int i = 0; i < n; ++i) {
    string name;
    getline(cin, name);
    cand.push_back(candidate(i, name, 0));
  }
  string vote;
  int invalid = 0;
  for (int i = 0; i < m; ++i) {
    getline(cin, vote);
    int selected = -1;
    for (int j = 0; j < n; ++j) {
      if (vote[j] == 'X') {
        if (selected != -1) {
          selected = -1;
          break;
        } 
        else selected = j;
      }
    }
    if (selected == -1) invalid++;
    else cand[selected].votes++;
  }
  sort(cand.begin(), cand.end());
  for (int i = n - 1; i >= 0; --i) {
    printf("%s %.2lf%%\n", cand[i].name.c_str(), (100. * cand[i].votes / m) + EPS);
  }
  printf("Invalid %.2lf%%\n", (100. * invalid / m) + EPS);
  return 0;
}
