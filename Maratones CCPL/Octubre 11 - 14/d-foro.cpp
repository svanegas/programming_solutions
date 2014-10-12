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

#define D(x) cout << "DEBUG: " << #x " = " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }
#define MAXN 100005
#define INF 1<<30
#define edge pair<int, double> //nodo, peso
#define dist_node pair<double, int> // peso,nodo
vector<edge> g[MAXN];
double d[MAXN];
int p[MAXN];
vector<edge> edges;
vector<edge> doctor;
double distance(int x1, int y1, int x2, int y2){
  double first = pow((x2-x1),2);
  double second = pow((y2-y1),2);
  double result = sqrt(first + second);
  return result; 
}

void dijkstra(int s, int n){
  for(int i=0; i<=n; i++){
    d[i] = INF; p[i]=-1;
  }
  priority_queue <dist_node, vector<dist_node>, greater<dist_node> >q;
  d[s]=0.00;
  q.push(dist_node(0,s));
  while(!q.empty()){
    double dist = q.top().first;
    int cur = q.top().second;
    q.pop();
    if(dist > d[cur])continue;
    for(int i=0; i<g[cur].size(); ++i){
      int next = g[cur][i].first;
      double w_extra = g[cur][i].second;
      if(d[cur] + w_extra < d[next]){
        d[next] = d[cur] + w_extra;
        p[next] = cur;
        q.push(dist_node(d[next], next)); 
      }
    }
  }
}


int main() {
  int t;
  cin >> t;
  while(t--){
    int n,m,k,di,x1,y1;
    cin >> n >> m >> k >> di;
    for(int i=0; i<=MAXN; i++)g[i].clear();
    doctor.clear();
    edges.clear();
    for(int i=0; i<m; i++){
      cin >> x1 >> y1;
      doctor.push_back(make_pair(x1,y1)); 
      D(x1);D(y1);
    }
    int branch;
    int x=1;
    cin >> branch;
    for(int i=0; i<branch; i++){
      cin >> x1 >> y1;
      D(x);
      g[0].push_back(make_pair(x,0));
      g[x].push_back(make_pair(0,0));
      edges.push_back(make_pair(x1,y1));
      x++; 
    }
    D(g[0].size());
    for(int f=1; f<n; f++){
      vector<edge> aux;
      cin >> branch;
      for(int i=0; i<branch; i++){
        cin >> x1 >> y1;
        aux.push_back(make_pair(x1,y1));
        for(int j=0; j<edges.size(); j++){
          int x2 = edges[j].first;
          int y2 = edges[j].second;
          double dn = distance(x1,y1,x2,y2);
          if(dn <= k){
            g[x].push_back(make_pair(j+1,dn));
            g[j+1].push_back(make_pair(x,dn));   
          }
        }
        x++;
      }
      for(int i=0; i<aux.size(); i++)edges.push_back(aux[i]);
    }
    for(int i=0; i<doctor.size();i++){
      int x1 = doctor[i].first;
      int y1 = doctor[i].second;
      for(int j=0; j < edges.size(); j++){
        int x2 = edges[j].first;
        int y2 = edges[j].second;
        double dn = distance(x1,y1,x2,y2);
        if(dn <= di){
          g[x].push_back(make_pair(j+1,dn));
          g[j+1].push_back(make_pair(x,dn)); 
        }
      }
      x++;
    }
    dijkstra(0,x);
    for(int i=0; i<x; i++){
      for(int j=0; j<g[i].size(); j++){
        cout << "El nodo " << i << " tiene con: " << g[i][j].first << " con d: " << g[i][j].second << endl;
      }
    }
    for(int i=0; i<(x); i++)cout << d[i] << endl;
  }
  return 0;
}

