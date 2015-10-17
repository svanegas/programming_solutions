// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;
priority_queue <pii, vector <pii>, greater <pii> > q;

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) q.push(pii(0, i));
  string s; cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    pii next = q.top(); q.pop();
    pii second = q.top(); q.pop();
    if (s[i] == '1') next.first++;
    else second.first++;
    q.push(next);
    q.push(second);
  }
  pii low1, low2;
  low1 = q.top(); q.pop();
  low2 = q.top(); q.pop();
  cout << low1.first << " " << low2.first << endl;
  return 0;
}
