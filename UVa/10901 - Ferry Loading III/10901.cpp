#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;
typedef pair <ll, int> car;
queue <car> left_q;
queue <car> right_q;
int n, m;
ll t;
ll time_tot;
bool in_left;
const int MAXN = 10005;
ll ans[MAXN];

void
go_board(queue <car> &q) {
  for (int i = 0; i < n && !q.empty(); ++i) {
    car pushing = q.front();
    if (pushing.first <= time_tot) {
      q.pop();
      int ind = pushing.second;
      ans[ind] = time_tot + t;
    }
    else break;
  }
  in_left = !in_left;
  time_tot += t;
}

void
go() {
  time_tot = 0LL;
  in_left = true;
  while (!left_q.empty() || !right_q.empty()) {
    car nextL = car(INF, -1), nextR = car(INF, -1);
    if (!left_q.empty()) nextL = left_q.front();
    if (!right_q.empty()) nextR = right_q.front();
    ll arrived = min(nextL.first, nextR.first);
    time_tot += max(arrived - time_tot, 0LL);
    if (in_left && nextL.first <= time_tot) {
      go_board(left_q);
      continue;
    }
    if (!in_left && nextR.first <= time_tot) {
      go_board(right_q);
      continue;
    }
    if (nextL.first == nextR.first) {
      if (in_left) go_board(left_q);
      else go_board(right_q);
      continue;
    }
    if (nextL.first < nextR.first) {
      if (!in_left) {
        time_tot += t;
        in_left = true;
      }
      go_board(left_q);
      continue;
    }
    if (nextL.first > nextR.first) {
      if (in_left) {
        time_tot += t;
        in_left = false;
      }
      go_board(right_q);
      continue;
    }
  }
}

int main() {
  int z;
  cin >> z;
  while (z--) {
    cin >> n >> t >> m;
    for (int i = 0; i < m; ++i) {
      ll ti;
      string side;
      cin >> ti >> side;
      if (side == "left") left_q.push(car(ti, i));
      else right_q.push(car(ti, i));
    }
    go();
    for (int i = 0; i < m; ++i) cout << ans[i] << endl;
    if (z) cout << endl;
  }
  return 0;
}
