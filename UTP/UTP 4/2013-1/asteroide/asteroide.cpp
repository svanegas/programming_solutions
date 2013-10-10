#include <algorithm>
#include <iostream>
#include <iterator>
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

using namespace std;

double distancia(double xna, double yna, double xas, double yas){
   return sqrt(((xas - xna)*(xas - xna)) + ((yas - yna)*(yas - yna))); 
}

int main(){
  int n;
  while(cin>>n){
   if(n==0)break;
   double xn, yn;
   cin >> xn >> yn;
   double xa, ya, r;
   cin >> xa  >> ya >> r; 
   int nas=1;
   double mind = distancia(xn,yn,xa,ya) - r;
   for(int i=2;i<=n;i++){
     cin >> xa  >> ya >> r;
     double resul = distancia(xn,yn,xa,ya);  
      if(mind > (resul - r)){
       mind = resul-r;
       nas = i;
      }
     
    }
    cout << nas << endl;
  }
        
    
    
 return 0;   
}
