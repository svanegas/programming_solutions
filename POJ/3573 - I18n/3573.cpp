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

map <string, string> expa;

string
abreviar (string s) {
    string ret;
    int num = s.size()-2;
    stringstream ss;
    ss << num;
    ss >> ret;
    string ret2;
    ret2 += tolower(s[0]);
    ret2 += ret;
    ret2 += tolower(s[s.size()-1]);
    return ret2;
}

bool
sonIguales(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    for (int i = 0; i < s1.size(); i++) {
        if (tolower(s1[i]) != tolower(s2[i])) {
            return false;
        }
    }
    return true;   
}

string
f(string word) {
    if ((word.size() == 3 && isdigit(word[1])) || (word.size() == 4 && 
        isdigit(word[1]) && isdigit(word[2]))) { //Es abrv
        string test;
        if (word.size() == 3) {
            test += tolower(word[0]);
            test += word[1];
            test += tolower(word[2]);
        }
        else {
            test += tolower(word[0]);
            test += word[1];
            test += word[2];
            test += tolower(word[3]);
        }
        string expan = expa[test];
        if (expan == "4MBiFogueCiRotoN241DA6533" || expan == "") {   
            return word;
        }
        else {
            string ret = expan;
            expan[0] = word[0];
            expan[expan.size()-1] = word[word.size()-1];
            if (isupper(expan[0]) && isupper(expan[expan.size()-1])) {
                for (int i = 0; i < expan.size(); i++) {
                    expan[i] = toupper(expan[i]);   
                }   
            }
            if (islower(expan[0]) && islower(expan[expan.size()-1])) {
                for (int i = 0; i < expan.size(); i++) {
                    expan[i] = tolower(expan[i]);   
                }   
            }
            if (isupper(expan[0]) && islower(expan[expan.size()-1])) {
                for (int i = 1; i < expan.size(); i++) {
                    expan[i] = tolower(expan[i]);   
                }   
            }
            return expan;
        }
    }
    else if (word.size() > 3) { //Si no es abreviación
        string abr = abreviar(word);
        string expansion = expa[abr];
        if (expansion == "") {
            expa[abr] = word;
            return word;
        }
        else if (!sonIguales(word, expansion)) {
            expa[abr] = "4MBiFogueCiRotoN241DA6533";
            return word;
        }
    }
    return word;   
}

int
main() {
    freopen ("i18n.in", "r", stdin);
    //freopen ("i18n.out", "w", stdout);
    string line;
    while (getline(cin, line)) {
        string word = "";
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '-' || line[i] == ',' || line[i] == '.' || 
            line[i] == '\"' || line[i] == '(' || line[i] == ')' || 
            line[i] == ':' || line[i] == ';' || line[i] == '!' || 
            line[i] == '?' || line[i] == ' ') {
                cout << f(word) << line[i];
                word = "";
            }
            else {
                word += line[i];   
            }    
        }
        cout << f(word);
        puts("");
    }
    return 0;
}
