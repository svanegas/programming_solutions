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

int determinar(long long num){
   long double result = sqrt((2*num)+(0.25)) - (0.5);
   long long aux = (long long)result;
   if((aux - result) != 0){
        cout<< "NO" << endl;
   } else {
        cout << "SI" << endl;     
   }  
   return 0;
}

int main(){
 long long n;
  while(cin>>n){
  if(n==0)break;
  determinar(n);          
  }  
 return 0;   
}
