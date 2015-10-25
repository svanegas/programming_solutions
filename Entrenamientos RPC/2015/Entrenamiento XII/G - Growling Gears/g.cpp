#include <bits/stdc++.h>

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

typedef pair<string, double> pareja;

#define D(x)// cout << #x " = " << (x) << endl;

int main(){
   int cases;
   cin >> cases;
   double resT, aux;
   int a, b, c, engines, res;
   while(cases--){
      cin >> engines;
      cin >> a >> b >> c;
      res = 1;
      aux = 1.0 * b / 2.0 / a;
      resT = -1.0*a*aux*aux + 1.0*b*aux + 1.0*c;
      D(resT);
      for(int i = 2; i <= engines; ++i){
         cin >> a >> b >> c;
         aux = 1.0 * b / 2.0 / a;
         aux = -1.0*a*aux*aux + 1.0*b*aux + 1.0*c;
         if(aux > resT){
            res = i;
            resT = aux;
         }
         D(resT);
      }
      cout << res << endl;
   }
   return 0;
}
