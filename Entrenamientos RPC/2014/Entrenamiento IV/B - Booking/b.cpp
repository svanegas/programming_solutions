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

#define D(x) cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

struct fecha {
  int first;
  bool second;
  fecha() {}
  fecha(int FIRST, bool SECOND) : first(FIRST), second(SECOND) {} 
  
  bool operator < (const fecha& f2) const {
    if (first < f2.first) return true;
    if (first == f2.first) {
      if (second) return false;
    }
    return false;
  }
};

int t, n, add;
string aDate, aTime, dDate, dTime;
vector <fecha> fechas;

int preDias[]   = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int preDiasBi[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //Bisiesto

int
monthToDay(int m, int year){
  int tot = 0;
  for ( int i = 0; i < m; i++){
    if (year != 2016) tot += preDias[i];
    else tot += preDiasBi[i];
  }
  return tot;
}

int
yearToDay(int year) {
  return (year - 2013) * 365;
}

int timeToMin(){
  int year, month, day, hour, minu;
  scanf("%d-%d-%d %d:%d", &year, &month, &day, &hour, &minu);
  int days = yearToDay(year);
  days += monthToDay(month-1, year);
  days += (day - 1);
  int res = (days * 24); //Queda en horas
  res += hour; //Le sumo las horas del actual dia
  res *= 60; //Lo convierto a minutos
  res += minu; //Le sumo los minutos del actual dia
  return res;
}

int
main() {
  cin >> t;
  while (t--) {
    fechas.clear();
    cin >> n >> add;
    for (int i = 0; i < n; i++) {
      string id; cin >> id;
      int arrives = timeToMin();
      int departs = timeToMin();
      departs += add;
      fecha arr = fecha(arrives, true);
      fecha dep = fecha(departs, false);
      fechas.push_back(arr);
      fechas.push_back(dep);
    }
    sort(fechas.begin(), fechas.end());
    int maxi = -1;
    int cont = 0;
    for (int i = 0; i < fechas.size(); i++) {
      fecha act = fechas[i];
      
      vector <fecha> temp, check;
      temp.push_back(act);
      int aux = i + 1;
      while (aux < fechas.size() && fechas[aux].first == act.first) {
        temp.push_back(fechas[aux++]);
      }
      if (temp.size() > 1) {
        for (int j = 0; j < temp.size(); j++) {
          if (temp[j].second) check.push_back(temp[j]);
          else check.insert(check.begin(), temp[j]);
        }
        for (int j = 0; j < check.size(); j++) {
          if (check[j].second) cont++;
          else cont--;
          maxi = max(maxi, cont); 
        }
        i = aux - 1;
      }
      else {
        if (act.second) cont++;
        else cont--;
        maxi = max(maxi, cont);
      }
    }
    cout << maxi << endl;
  }
  return 0;
}
