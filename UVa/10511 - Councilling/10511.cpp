// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
typedef vector <int> vi;
typedef pair <int, int> pii;
map <int, vi> g;
map <int, map <int, int> > c;
map <int, map <int, int> > f;
map <int, int> prev;
map <string, int> party;
map <string, int> club;
map <int, string> residents;
map <int, string> clubs;
vector <pii> club_to_res;
vector <pii> res_to_party;

void
connect(int i, int j, int cap) {
  g[i].push_back(j);
  g[j].push_back(i);
  c[i][j] += cap;
}

int
maxflow(int s, int t, int n) {
  f.clear();
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      f[i][j] = 0;
    }
  }
  int flow = 0;
  while (true) {
    prev.clear();
    for (int i = 0; i <= n; i++) prev[i] = -1;
    queue <int> q;
    q.push(s);
    prev[s] = -2;
    while (q.size() > 0){
      int u = q.front(); q.pop();
      if (u == t) break;
      for (int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if (prev[v] == -1 and c[u][v] - f[u][v] > 0){
          q.push(v);
          prev[v] = u;
        }
      }
    }
    if (prev[t] == -1) break;
    int extra = INF;
    int end = t;
    while (end != s) {
      int start = prev[end];
      extra = min(extra, c[start][end] - f[start][end]);
      end = start;
    }
    end = t;
    while (end != s) {
      int start = prev[end];
      f[start][end] += extra;
      f[end][start] = -f[start][end];
      end = start;
    }
    flow += extra;
  }
  return flow;
}

int
main() {
  int t; scanf("%d", &t);
  string line;
  getline(cin, line);
  getline(cin, line);
  while (t--) {
    c.clear();
    g.clear();
    party.clear();
    club.clear();
    residents.clear();
    club_to_res.clear();
    res_to_party.clear();
    int cur_club = 0, cur_party = 0, cur_res = 0;
    for (int i = 0; getline(cin, line) && line != ""; ++i, ++cur_res) {
      stringstream ss(line);
      string res, part, clu;
      ss >> res >> part;
      residents[i] = res;
      if (party.count(part) == 0) party[part] = cur_party++;
      res_to_party.push_back(make_pair(i, party[part]));
      while (ss >> clu) {
        if (club.count(clu) == 0) {
          clubs[cur_club] = clu;
          club[clu] = cur_club++;
        }
        club_to_res.push_back(make_pair(club[clu], i));
      }
    }
    int n = cur_club + cur_party + cur_res;
    int source = n, dest = n + 1;
    for (int i = 0; i < club_to_res.size(); ++i) {
      int from = club_to_res[i].first;
      int to = club_to_res[i].second;
      connect(from, to + cur_club, 1);
    }
    for (int i = 0; i < res_to_party.size(); ++i) {
      int from = res_to_party[i].first;
      int to = res_to_party[i].second;
      connect(from + cur_club, to + cur_club + cur_res, 1);
    }
    for (int i = 0; i < cur_club; ++i) connect(source, i, 1);
    for (int i = 0; i < cur_party; ++i) {
      int half = cur_club % 2 ? cur_club / 2 : cur_club / 2 - 1;
      connect(i + cur_club + cur_res, dest, half);
    }
    if (cur_club > 0 && maxflow(source, dest, n + 2) == cur_club) {
      for (int i = 0; i < cur_club; ++i) {
        for (int j = 0 + cur_club; j < cur_club + cur_res; ++j) {
          if (f[i][j] == 1) {
            string ans_res = residents[j - cur_club];
            string ans_club = clubs[i];
            printf("%s %s\n", ans_res.c_str(), ans_club.c_str());
          }
        }
      }
    }
    else puts("Impossible.");
    if (t) puts("");
  }
  return 0;
}
