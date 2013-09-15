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

int n;
vector <string> dictionary;
vector <string> original;

string
setup(string s) {
    sort(s.begin()+1, s.end()-1);
    return s;    
}

string
find(string s) {
    for (int i = 0; i < dictionary.size(); i++) {
        if (dictionary[i] == s) return original[i];   
    }
    return "";
}

int
main() {
    cin >> n;
    getchar();
    string line, palabras;
    while (n--) {
        getline(cin, line);
        getline(cin, palabras);
        stringstream ss(line);
        stringstream ss2(palabras);
        string word;
        while (ss >> word) {
            dictionary.push_back(setup(word));
            original.push_back(word);
        }
        //Procesamos las palabras desordenadas
        ss2 >> word;
        string buscar = setup(word);
        string poner = find(buscar);
        if (poner == "") poner = word;
        cout << poner;
        while (ss2 >> word) {
            buscar = setup(word);
            poner = find(buscar);
            if (poner == "") poner = word;
            cout << " " << poner;
        }
        puts("");
    }
    return 0;
}
