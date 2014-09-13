#include <iostream>
#include <algorithm>
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
#include <stack>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

template <class T> string toStr(const T &x) 
{ stringstream s; s << x; return s.str(); } 
  
template <class T> int toInt(const T &x) 
{ stringstream s; s << x; int r; s >> r; return r; }


vector <char> numbers;

int main(){
    string line;
    while(getline(cin, line)){
       numbers.clear();
       stringstream ss(line);
       char num;
       int n;
       int contC = 0;
       ss >> n;
       if(n == 0) break;
       while(ss >> num){
          if(num == '0') contC++;
          else numbers.push_back(num);      
       }
       sort(numbers.begin(), numbers.end());
       
       string n1, n2;
       n1 = n2 = "";
       
       n1 += numbers[0];
       numbers.erase(numbers.begin());
       n2 += numbers[0];
       numbers.erase(numbers.begin());
       
       if(n % 2 == 0){
          int ceros = contC / 2;
          for(int i = 0; i < ceros; ++i){
             n1 += '0'; n2 += '0';        
          }
          if(contC % 2 == 1) n2 += '0';
          n = numbers.size();
          for(int i = 0; i < n; i = i + 2){
             n1 += numbers[i];
             if(i+1 < n) n2 += numbers[i+1];        
          }
       }else{
            int ceros = contC / 2;
            for(int i = 0; i < ceros; ++i){
                n1 += '0'; n2 += '0';    
            } 
            bool b = false;
            if(contC % 2 == 1){
                     n1 += '0';
                     b = true;
            }
            n = numbers.size();
            if(b){
                for(int i = 0; i < n; i = i+2){
                        n2 += numbers[i];
                        n1 += numbers[i+1];  
                }
            }
            else{
               for(int i = 0; i < n-1; i = i+2){
                  n1 += numbers[i];
                  n2 += numbers[i+1];        
               }
               n1 += numbers[n-1];
            }
       }
       int nn1, nn2;
       nn1 = toInt(n1);
       nn2 = toInt(n2);
       
       cout << nn1 + nn2 << endl;
    }
    
    
    
    
    return 0;    
}
