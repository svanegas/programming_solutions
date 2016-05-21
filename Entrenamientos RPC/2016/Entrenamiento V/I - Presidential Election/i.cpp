#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct candi {
  int id;
  ll votes;
  double perc;
  
  candi() {}
  candi(int _id, ll _votes, double _perc) : id(_id), votes(_votes), perc(_perc) {}
  
  bool operator < (const candi &than) const {
    if (votes < than.votes) return true;
    else if (votes == than.votes) {
      if (id > than.id) return true;
      else return false; 
    }
    else return false;
  }
};


const int MAXC = 505;
ll votes[MAXC];
double buffer[1005];
int cand, st, i, j;
ll grand_total, tot;
vector <candi> ans;

ll
num_ppl(double perc, ll tot) {
  return (ll) round((perc * tot) / 100.0);
}

void
print_candi(const candi &a) {
  printf("%d %lld\n", a.id, a.votes);
}

int
main() {
  int t; scanf("%d", &t);
  bool printed = false;
  while (t--) {
    if (printed) printf("\n");
    else printed = true;
    scanf("%d %d", &cand, &st);
    for (i = 0; i <= cand; ++i) votes[i] = 0LL;
    grand_total = 0LL;
    for (i = 0; i < st; ++i) {
      for (j = 0; j < cand; ++j) scanf("%lf", &buffer[j]);
      scanf("%lld", &tot);
      grand_total += tot;
      for (j = 0; j < cand; ++j) votes[j] += num_ppl(buffer[j], tot); 
    }
    ans.clear();
    for (i = 0; i < cand; ++i) {
      ans.push_back(candi(i + 1, votes[i], (votes[i] / (grand_total * 1.0)) * 100.0));
    }
    sort(ans.begin(), ans.end());
    candi win = ans.back(); ans.pop_back();
    print_candi(win);
    if (win.perc < 50.1) {
      print_candi(ans.back());
    }
  }
  return 0;
}
