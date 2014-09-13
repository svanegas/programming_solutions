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

#define D(x) //cout << #x " is " << x << endl

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

map<int, int> diasMes;

int dia, mes, ano;

vector<int>
partir(string fecha) {
    istringstream ss(fecha);
    string dia, mes, ano;
    getline(ss, dia, '-');
    getline(ss, mes, '-');
    getline(ss, ano, '-');
    vector <int> ret;
    ret.push_back(toInt(dia));
    ret.push_back(toInt(mes));
    ret.push_back(toInt(ano));
    return ret;
}

void
sumar(int dif) {
    int newDia, newMes, newAno;
    newDia = dia + dif;
    newMes = mes;
    newAno = ano;
    while (newDia > diasMes[mes]) {
        newDia -= diasMes[mes];
        newMes++;
        if (newMes > 12) {
            newAno++;
            newMes = 1;
            if (newAno % 4 == 0) {
                diasMes[2] = 29;
                if (newAno%100 == 0 && newAno%400 != 0) {
                    diasMes[2] = 28;   
                }   
            }
        }
    }
    printf("%d-%02d-%02d\n", newAno, newMes, newDia);
    //cout << newAno << "-" << newMes << "-" << newDia << endl;
}

int
main() {
    diasMes[1] = 31;
    diasMes[2] = 28; //Febrero
    diasMes[3] = 31;
    diasMes[4] = 30;
    diasMes[5] = 31;
    diasMes[6] = 30;
    diasMes[7] = 31;
    diasMes[8] = 31;
    diasMes[9] = 30;
    diasMes[10] = 31;
    diasMes[11] = 30;
    diasMes[12] = 31;
    string fecha;
    while (cin >> fecha) {
        diasMes[2] = 28;
        vector <int> fech = partir(fecha);
        
        ano = fech[0];
        mes = fech[1];
        dia = fech[2];
        int dif = 0.0075 * ano;
        if (ano%4 == 0) {
            dif = 0.0075 * (ano-1);   
        }
        
        if (ano%4 == 0) {
            diasMes[2] = 29;
            if (!(ano%100 == 0 && ano%400 != 0)) {
                dif--; 
            }
        }
        D(ano);
        D(mes);
        D(dia);
        sumar(dif);
    }
	return 0;
}
