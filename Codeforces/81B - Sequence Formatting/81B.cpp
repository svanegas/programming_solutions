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

string line, token;
bool poner = false, borrar = true;

int
main() {
    cout << "WRONG ANSWER, MY WORST ALGORITHM EVER" << endl;
    return 0;
    getline(cin, line);
    size_t found = line.find(",");
    if (found != string::npos) poner = true;
    istringstream iss(line);
    getline(iss, token, ',');
    stringstream ss1;
    ss1 << token;
    //ss1 >> token;
    
    string shit = "";
    int fck2 = 0;
    while (ss1 >> token) {
        if (fck2 == 0) {
            shit += token;
            fck2++;
            continue;
        }
        fck2++;
        shit += " ";
        shit += token;
    }
    
    if (poner) cout << shit << ",";
    else {
        size_t found = line.find(".");
        if (found == string::npos) cout << shit;
    }
        
    /*if (poner) cout << token << ",";
    else {
        size_t found = line.find(".");
        if (found == string::npos) cout << token;
    }*/
    string res = "";
    while (getline(iss, token, ',')) {
        stringstream ss;
        ss << token;
        int fck = 0;
        while (ss >> token) {
            fck++;
            //cout << " " << token << ",";
            res += " ";
            res += token;
            
        }
        if (fck == 0) res += " ,";
        else res += ",";
    }
    //printf("Hola con res:");
    //cout << res << "|token:" << token << "|" << endl;
    if (res.size() == 0) {
        size_t found2 = line.find(".");
        if (found2 == string::npos);
        else {
            res = token;
        }
        borrar = false;
        while (ss1 >> token) {
            res += " ";
            res += token;
        }
    }
    if (line[line.size()-1] != ',' && borrar) res.erase(res.end()-1);
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == '.') {
            if (i != 0 && res[i-1] != ' ') {
                res.insert(i, " ");  
                i++;
            } 
            i += 2;
        }
    }
    if (poner && line != ",") {
        if (res.size() != 0)
        for (int i = 0; i < res.size() - 1; i++) {
            if (res[i] == ' ' && res[i+1] == ' ') {
                res.erase(res.begin()+i);  
                i--;
            }
        }
    }
    cout << res << endl;
	return 0;
}
