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

int t, n;
vector <string> vEncr;
string sDecr, aBuscar;
map <char, char> decrEncr1;
map <char, char> encrDecr1;

map <char, set<char> > finalDecrEncr;
map <char, char> finalEncrDecr;

string
buidMessage(string encr) {
    string res = "";
    for (int i = 0; i < encr.size(); i++) {
        res += encrDecr1[encr[i]];
    }
    return res;
}

string
decryptMessage(string toDecrypt) {
    string res = "";
    for (int i = 0; i < toDecrypt.size(); i++) {
        res += ((finalEncrDecr.count(toDecrypt[i]) == 0) ? '?' : finalEncrDecr[toDecrypt[i]]);
    }
    return res;
    
}

void
fillLastChar() {
    bool estaFirst[26], estaSec[26];
    memset(estaFirst, false, sizeof estaFirst);
    memset(estaSec, false, sizeof estaSec);
    char fFirst, fSec;
    
    map <char, char> :: iterator it;
    for (it = finalEncrDecr.begin(); it != finalEncrDecr.end(); ++it) {
        estaFirst[char((it->first)-'a')] = true;
    }
    
    for (int i = 0; i < 26; i++) if (!estaFirst[i]) fFirst = char(i+'a');
    
    map <char, set<char> > :: iterator it2;
    for (it2 = finalDecrEncr.begin(); it2 != finalDecrEncr.end(); ++it2) {
        estaSec[char((it2->first)-'a')] = true;      
    }
    
    for (int i = 0; i < 26; i++) if (!estaSec[i]) fSec = char(i+'a');
    
    finalEncrDecr[fFirst] = fSec;
}

int
main() {
    cin >> t;
    while (t--) {
        finalDecrEncr.clear();
        finalEncrDecr.clear();
        vEncr.clear();
        cin >> n;
        while (n--) {
            string encr; cin >> encr;
            vEncr.push_back(encr);
        }
        cin >> sDecr >> aBuscar;
        for (int i = 0; i < vEncr.size(); i++) {
            decrEncr1.clear();
            encrDecr1.clear();
            string sAnaliz = vEncr[i];
            if (sAnaliz.size() != sDecr.size()) continue;
            for (int j = 0; j < sAnaliz.size(); j++) {
                decrEncr1[sDecr[j]] = sAnaliz[j];
            }
            map <char, char> :: iterator it;
            for (it = decrEncr1.begin(); it != decrEncr1.end(); ++it) {
                encrDecr1[it->second] = it->first;
            }
            if (buidMessage(sAnaliz) == sDecr) {
                for (it = decrEncr1.begin(); it != decrEncr1.end(); ++it) {
                    finalDecrEncr[it->first].insert(it->second);
                }
            }
        }
        if (finalDecrEncr.size() == 0) {
            cout << "IMPOSSIBLE" << endl; 
            continue;
        }
        map <char, set<char> > :: iterator it;
        for (it = finalDecrEncr.begin(); it != finalDecrEncr.end(); ++it) {
            bool qMark = false;
            qMark = ((it->second).size() > 1);
            set <char> :: iterator jt;
            for (jt = (it->second).begin(); jt != (it->second).end(); ++jt) {
                finalEncrDecr[*jt] = qMark ? '?' : it->first;
            } 
        }
        
        if (finalEncrDecr.size() == 25) fillLastChar();   
        
        cout << decryptMessage(aBuscar) << endl;
    }
	return 0;
}
