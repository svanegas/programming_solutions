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

typedef pair<char, char> card;
vector <stack <card> > cards;

bool
can(card c1, card c2) {
  return (c1.first == c2.first || c1.second == c2.second);  
}

int
main() {
  string word;
  while (cin >> word && word != "#") {
    cards.clear();
    stack <card> s;
    s.push(card(word[0], word[1]));
    cards.push_back(s);
    for (int i = 0; i < 51; i++) {
      cin >> word;
      stack <card> s;
      s.push(card(word[0], word[1]));
      cards.push_back(s);
    }
    for (int i = 0; i < cards.size(); i++) {
      if (i >= 3 && can(cards[i].top(), cards[i-3].top())) {
        cards[i-3].push(cards[i].top());
        cards[i].pop();
        if (cards[i].empty()) cards.erase(cards.begin() + i);
        i -= 4;
      }
      else if (i >= 1 && can(cards[i].top(), cards[i-1].top())) {
        cards[i-1].push(cards[i].top());
        cards[i].pop();
        if (cards[i].empty()) cards.erase(cards.begin() + i);
        i -= 2;
      }
    }
    printf("%d pile%s remaining:", cards.size(), (cards.size() == 1 ? "" : "s"));
    for (int i = 0; i < cards.size(); i++) {
      printf(" %d", cards[i].size()); 
    }
    puts("");
  }
  return 0;
}
