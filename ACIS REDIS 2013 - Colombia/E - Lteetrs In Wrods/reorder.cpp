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
map <string, string> dictionary;

string
setup(string s) {
    sort(s.begin(), s.end());
    return s;    
}

int
main() {
    cin >> n;
    getchar();
    string line, palabras;
    while (n--) {
        dictionary.clear();
        getline(cin, line);
        getline(cin, palabras);
        stringstream ss(line);
        stringstream ss2(palabras);
        string word;
        while (ss >> word) {
            string ordered = setup(word);
            if (dictionary[ordered] == "") dictionary[ordered] = word;
        }
        //Procesamos las palabras desordenadas
        ss2 >> word;
        string resp = dictionary[setup(word)];
        if (resp != "") cout << resp;
        else cout << word;
        while (ss2 >> word) {
            resp = dictionary[setup(word)];
            if (resp != "") cout << " " << resp;
            else cout << " " << word;
        }
        puts("");
    }
    return 0;
}
