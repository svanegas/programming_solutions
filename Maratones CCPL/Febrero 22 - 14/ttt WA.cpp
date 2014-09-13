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

#define D(x) //cout << #x " = " << (x) << endl

using namespace std;

char matr[3][3];
int cantX, cantO;
bool ganaX, ganaO;

void
winner() {
    string res;
    for (int i = 0; i < 3; i++) {
        res = "";
        for (int j = 0; j < 3; j++) {
            res += matr[j][i];
        }
        if (res == "XXX") ganaX = true;
        if (res == "OOO") ganaO = true;
    }
    if (matr[0][0] == 'O' && matr[1][1] == 'O' && matr[2][2] == 'O') ganaO = true;
    if (matr[0][2] == 'O' && matr[1][1] == 'O' && matr[2][0] == 'O') ganaO = true;
}


int
main() {
    int n;
    cin >> n;
    while (n--) {
        cantX = cantO = 0;
        ganaX = ganaO = false;
        for (int i = 0; i < 3; ++i) {
            string s; cin >> s;
            for (int j = 0; j < 3; j++) {
                matr[i][j] = s[j];
                if (s[j] == 'X') cantX++;
                if (s[j] == 'O') cantO++;
            }
            //Si las X ganan en fila
            if (s == "XXX") {
                ganaX = true;
            }
            else if (s == "OOO") {
                ganaO = true;
            }
        }
        //Llamar revisar ganar columnas
        winner();
        if (cantX - 1 > cantO) {
            cout << "no" << endl;
            if (n) {
                string line;
                getline(cin, line);
            }
            continue;
        }
        if (ganaO && ganaX) {
            cout << "no" << endl;
            if (n) {
                string line;
                getline(cin, line);
            }
            continue;
        }
        if (cantX < cantO) {
            cout << "no" << endl;
            if (n) {
                string line;
                getline(cin, line);
            }
            continue;
        }
        if (cantX > cantO && ganaO) {
            cout << "no" << endl;
            if (n) {
                string line;
                getline(cin, line);
            }
            continue;
        }
        if (cantX == cantO) {
            cout << "yes" << endl;
            if (n) {
                string line;
                getline(cin, line);
            }
            continue;
        }
        if (cantX > cantO) {
            cout << "yes" << endl;
            if (n) {
                string line;
                getline(cin, line);
            }
            continue;
        }


    }
    return 0;
}
