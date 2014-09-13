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

int main(){
 long double num;
 while(cin>>num){
    if(num==0)break;  
    long double result = sqrt(num);     
    cout << ceil (result) << endl;
 }   
 return 0;   
}
