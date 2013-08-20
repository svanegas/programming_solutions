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

typedef pair <int, int> nadador;
const int INF = 1 << 30; //Infinito 2^30
const int MAXN = 55;
int tiempo[MAXN]; //Vector para almacenar el tiempo de cada nadador
int vueltas[MAXN]; //Vector para almacenar las vueltas de cada nadador
int n, crono;
vector <nadador> ida, venida; //Colas para carril de ida y de venida

void
cambiarLanes() {
    vector <nadador> tempI;
    int cont = 0;
    while (!ida.empty() && ida[0].first <= 0) { //Tomo todos los nadadores que                          //ya llegaron al final de ida.
        nadador tmp = ida[0];
        tmp.first = tiempo[tmp.second]; //Restablezco el tiempo del nadador
        //tempI.push_back(tmp);
        venida.push_back(tmp);
        ida.erase(ida.begin()); //Lo quito del carril de ida
        cont++;
    }
    sort(venida.end() - cont, venida.end());
    //sort(tempI.begin(), tempI.end());//Organizo los nadadores antes de meterlos
                                    //En el carril de venida
    /*for (int i = 0; i < tempI.size(); i++) { //Meto cada uno de los nadadores
                                             //en el carril de venida
        venida.push_back(tempI[i]);
    }*/
    cont = 0;
    vector <nadador> tempV;
    while (!venida.empty() && venida[0].first <= 0) { //Para cada nadador que
                                                      //llego al fin de venida
        nadador tmp = venida[0];
        vueltas[tmp.second]--; //Le resto una vuelta
        if (vueltas[tmp.second] > 0) { //Si todavia le quedan vueltas por hacer
                                       //lo pongo para ordenar en un vector tmp
            tmp.first = tiempo[tmp.second];
            //tempV.push_back(tmp);
            ida.push_back(tmp);
            cont++;
        }
        venida.erase(venida.begin()); //Lo quito del carril de venida
    }
    sort(ida.end() - cont, ida.end());
    //sort(tempV.begin(), tempV.end()); //Organizo el vector temporal de nadadores
                                      //que van hacia ida
    /*for (int i = 0; i < tempV.size(); i++) {
        ida.push_back(tempV[i]); //Los meto en el carril de ida
    }*/
}

void
competir() {
    while (!ida.empty() || !venida.empty()) { //Mientras haya algun nadador
        int tempI = INF;
        int tempV = INF;
        if (!ida.empty()) tempI = ida[0].first; //El tiempo del primer nadador
        if (!venida.empty()) tempV = venida[0].first;//Tiempo del primer nadador
        int correr = min(tempI, tempV); //Tiempo que tengo que avanzar todos los
                                        //los nadadores y el cronometro
        for (int i = 0; i < ida.size(); i++) { //Avanzo nadadores de ida
            ida[i].first -= correr;
        }
        for (int i = 0; i < venida.size(); i++) { //Avanzo nadadores de venida
            venida[i].first -= correr;
        }
        crono += correr; //Corro el cronometro
        cambiarLanes();
    }
}

int
main() {
    //while (cin >> n && n) { //Leo numero de nadadores y sea distinto de 0
    while (scanf("%d", &n) && n) {
        crono = 0; //Reinicio el cronómetro
        vector <nadador> comp; 
        for (int i = 1; i <= n; i++) { //Leo todos los nadadores
            int t, c;
            //cin >> t >> c; 
            scanf("%d%d", &t, &c);
            tiempo[i] = t; //Almaceno el tiempo del nadador i
            vueltas[i] = c; //Almaceno las vueltas del nadador i
            comp.push_back(nadador(t, i)); //Lo pongo en el vector de nadadores
        }
        sort(comp.begin(), comp.end()); //Ordeno los nadadores por tiempo
        ida = comp; //Pongo a nadar a los muñequitos
        competir();
        printf("%d\n", crono);
    }   
    return 0;
}
