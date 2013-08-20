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

int
main() {
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        string parte;
        string result = "";
        ss >> parte;
        reverse(parte.begin(), parte.end());
        result += parte;
        while (ss >> parte) {
            result += " ";
            reverse(parte.begin(), parte.end());
            result += parte;
        }
        cout << result << endl;
    }
    return 0; 
} 
