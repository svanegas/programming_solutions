#include <bits/stdc++.h>

using namespace std;

int n, p;

struct card {
    int num;
    string col;
    card(int N, string C) : num(N), col(C) {}
};

int pos[10];

int main() {
  cin >> n >> p;
  for (int i = 0; i <= p; ++i) pos[i] = 0;
  vector <string> colors;
  vector <card> cards;
  map<string, int> spec;
  for (int i = 0; i < n - 1; ++i) {
    string color; cin >> color;
    colors.push_back(color);
    if (color.size() >= 7 && color.substr(0, 7) == "SPECIAL") {
      spec[color] = i;
    }
  }
  int c;
  cin >> c;
  for (int i = 0; i < c; ++i) {
    int num; cin >> num;
    string col; cin >> col;
    cards.push_back(card(num, col));
  }
  int ci = 0;
  int pi = 0;
  int winner = -1;
  while (winner == -1) {
    card cur_c = cards[ci];
    ci = (ci + 1) % c;
    int found = cur_c.num;
    if (cur_c.num == 3) {
      pos[pi] = spec[cur_c.col];
      found = 0;
    }
    while (found) {
      int next_pos = pos[pi]++;
      if (next_pos == n) {
        winner = pi + 1;
        break;
      }
      if (colors[next_pos] == cur_c.col) found--;
    }
    pi = (pi + 1) % p;
  }
  cout << winner << endl;
  return 0;
}
