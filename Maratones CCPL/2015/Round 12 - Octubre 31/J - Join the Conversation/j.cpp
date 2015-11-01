#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50005;
map <string, int> last;
vector <int> g[MAXN];
int d[MAXN];
int p[MAXN];

void
lpdag(int s) {
  queue <int> q;
  d[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int i = 0; i < g[cur].size(); ++i) {
      int next = g[cur][i];
      if (d[next] == -1 || d[next] < d[cur] + 1) {
        d[next] = d[cur] + 1;
        p[next] = cur;
        q.push(next);
      }
    }
  }
}

int main() {
  int n;
  while (cin >> n) {
    last.clear();
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
      d[i] = -1;
      p[i] = i;
    }
    for (int i = 0; i < n; ++i) {
      string author;
      cin >> author;
      author = author.substr(0, author.size() - 1);
      last[author] = i;
      string message;
      getline(cin, message);
      string word;
      stringstream ss(message);
      while (ss >> word) {
        if (word.size() >= 2 && word[0] == '@') {
          if (word != author && last.count(word)) {
            g[last[word]].push_back(i);
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (d[i] == -1) lpdag(i);
    }
    int maxi = 1;
    int ind = 0;
    for (int i = 0; i < n; ++i) {
      if (d[i] > maxi) {
        maxi = d[i];
        ind = i;
      }
    }
    stack <int> s;
    int cur = ind;
    s.push(cur);
    while (cur != p[cur]) {
      cur = p[cur];
      s.push(cur);
    }
    bool printed = false;
    printf("%d\n", maxi);
    while (!s.empty()) {
      if (printed) printf(" ");
      printf("%d", s.top() + 1);
      printed = true;
      s.pop();
    }
    puts("");
  }
  return 0;
}

/*
6
@Petr: Leaving for #NEERC tomorrow!
@Roman: This #NEERC is going to be awesome!
@Stone_in_forest: Nothing happened today.
@NEERCNews: @Petr Don't forget an unmbrella :)
@Lydia: @NEERCNews cares about @Petr - so cute
@Lydia: @Lydia @NEERCNews @Petr it won't be raining though!
*/
