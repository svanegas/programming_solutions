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

typedef pair <int, int> card; //Stores value, suit

int
value(card *hand, int n) {
	vector <int> suits(4, 0);
	priority_queue <card> singleValues;
	int lookAt = -1;
	for (int i = 0; i < n; ++i) {
		card cur = *(hand + i);
		suits[cur.second]++;
		singleValues.push(cur);
		if (suits[cur.second] >= 2) {
			lookAt = cur.second;
    }
  }
  int ans = 0;
  if (lookAt != -1) {
	  int taken = 0;
	  ans = 20;
	  while (!singleValues.empty() && taken < 2) {
		  card next = singleValues.top(); singleValues.pop();
		  if (next.second == lookAt) {
			  ans += next.first;
			  taken++;
      }
    }
  }
  else {
	  ans = singleValues.top().first; singleValues.pop();	
  }
  return ans;
}

int
maxIncrement(card *hand, int n) {
  int initialValue = value(hand, n);
  vector <card> cards;
  for (int i = 0; i < n; ++i) {
	  cards.push_back(*(hand + i));
  }
  sort(cards.rbegin(), cards.rend());
  int typeToChange = cards[0].second;
  int ans = 0;
  for (int k = 7; k >= 3; --k) {
    card newCard = card(k, typeToChange);
    int canChange = 0;
    for (int i = 0; i < n; ++i) {
	    if (cards[i] != newCard) {
        canChange++;
      }
    }
    if (canChange == 3) {
      card newCardsArray[3];
      newCardsArray[0] = cards[0];
      newCardsArray[1] = newCard;
      newCardsArray[2] = cards[2];
      ans = max(ans, value(&newCardsArray[0], 3) - initialValue); 
    }
  }
  return ans;
}

int
main() {
  map <string, int> m;
  m["espada"] = 0;
  m["basto"] = 1;
  m["copa"] = 2;
  m["oro"] = 3;
  int a, b, c;
  string x, y, z;
  while (cin >> a >> x >> b >> y >> c >> z) {
    if (a == -1) break;
    card cards[3];
    cards[0] = card(a >= 10 ? 0 : a, m[x]);
    cards[1] = card(b >= 10 ? 0 : b, m[y]);
    cards[2] = card(c >= 10 ? 0 : c, m[z]);
    cout << maxIncrement(&cards[0], 3) << endl;
  }
  return 0;
}
