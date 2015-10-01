// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL << 30;
int a, b, c, target;

struct state {
  int a, b, c;
  state() {}
  state(int A, int B, int C) : a(A), b(B), c(C) {} 
  bool operator < (const state &than) const {
    if (a < than.a) return true;
    else if (a == than.a) {
      if (b < than.b) return true;
      else if (b == than.b) return c < than.c;
      else return false;
    }
    else return false;
  }
};
typedef pair <ll, state> edge;
map <state, ll> dist;

pair <ll, int>
validate_state(state cur, ll w, ll ans, int closest) {
  if (cur.a == closest) ans = min(ans, w);
  if (cur.b == closest) ans = min(ans, w);
  if (cur.c == closest) ans = min(ans, w);
  if (target - cur.a >= 0 && cur.a > closest) {
    closest = cur.a;
    ans = w;
  }
  if (target - cur.b >= 0 && cur.b > closest) {
    closest = cur.b;
    ans = w;
  }
  if (target - cur.c >= 0 && cur.c > closest) {
    closest = cur.c;
    ans = w; 
  }
  return make_pair(ans, closest);
}

vector <edge>
generate_nexts(state cur) {
  int av_a = cur.a;
  int av_b = cur.b;
  int av_c = cur.c;
  vector <edge> states;
  if (av_a > 0) {
    int miss = b - av_b;
    if (miss > 0) {
      int poured = av_a >= miss ? miss : av_a;
      states.push_back(edge(poured * 1LL, state(av_a - poured, av_b + poured, av_c)));
    }
    miss = c - av_c;
    if (miss > 0) {
      int poured = av_a >= miss ? miss : av_a;
      states.push_back(edge(poured * 1LL, state(av_a - poured, av_b, av_c + poured)));
    }
  }
  if (av_b > 0) {
    int miss = a - av_a;
    if (miss > 0) {
      int poured = av_b >= miss ? miss : av_b;
      states.push_back(edge(poured * 1LL, state(av_a + poured, av_b - poured, av_c)));
    }
    miss = c - av_c;
    if (miss > 0) {
      int poured = av_b >= miss ? miss : av_b;
      states.push_back(edge(poured * 1LL, state(av_a, av_b - poured, av_c + poured)));
    }
  }
  if (av_c > 0) {
    int miss = a - av_a;
    if (miss > 0) {
      int poured = av_c >= miss ? miss : av_c;
      states.push_back(edge(poured * 1LL, state(av_a + poured, av_b, av_c - poured)));
    }
    miss = b - av_b;
    if (miss > 0) {
      int poured = av_c >= miss ? miss : av_c;
      states.push_back(edge(poured * 1LL, state(av_a, av_b + poured, av_c - poured)));
    }
  }
  return states;
}

pair <ll, int>
dijkstra(state src) {
  dist.clear();
  priority_queue <edge, vector <edge>, greater <edge> > q;
  q.push(edge(0LL, src));
  dist[src] = 0LL;
  int closest = src.c <= target ? src.c : -1;
  ll ans = 0LL;
  while (!q.empty()) {
    edge cur_edge = q.top(); q.pop();
    state cur = cur_edge.second;
    ll w = cur_edge.first;
    pair <ll, int> data = validate_state(cur, w, ans, closest);
    ans = data.first;
    closest = data.second;
    if (w > dist[cur]) continue;
    w = dist[cur];
    vector <edge> nexts = generate_nexts(cur);
    for (int i = 0; i < nexts.size(); ++i) {
      state next = nexts[i].second;
      ll w_extra = nexts[i].first;
      ll new_dist = w + w_extra;
      if (!dist.count(next)) {
        dist[next] = new_dist;
        q.push(edge(new_dist, next));
      }
      else if (new_dist < dist[next]) {
        dist[next] = new_dist;
        q.push(edge(new_dist, next)); 
      }
    }
  }
  return make_pair(ans, closest);
}

int
main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d", &a, &b, &c, &target);
    pair <ll, int> ans = dijkstra(state(0, 0, c));
    printf("%lld %d\n", ans.first, ans.second);
  }
  return 0;
}

