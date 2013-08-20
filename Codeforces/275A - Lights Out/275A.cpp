#include <iostream>

using namespace std;

int v[3][3];
int p[3][3];

void 
push(int i, int j) {
    if(v[i][j] == 0) {
        v[i][j] = 1;
        //cout << "En i: " << (i) << " j: " << (j) << " cambie 0 por 1" << endl;
    }
    else {
        v[i][j] = 0;
        //cout << "En i: " << (i) << " j: " << (j) << " cambie 1 por 0" << endl;
    }
    if((i-1) >= 0 && (i-1) < 3) {
        if(v[(i-1)][j] == 0) {
            v[i-1][j] = 1;
            //cout << "i: " << (i-1) << " j: " << j << " cambie 0 por 1" << endl;
        }
        else {
            v[i-1][j] = 0;
            //cout << "i: " << (i-1) << " j: " << j << " cambie 1 por 0" << endl;
        }
    }
    if((i+1) >= 0 && (i+1) < 3) {
        if(v[(i+1)][j] == 0) {
            v[i+1][j] = 1;
            //cout << "i: " << (i+1) << " j: " << j << " cambie 0 por 1" << endl;
        }
        else {
            v[i+1][j] = 0;
            //cout << "i: " << (i+1) << " j: " << j << " cambie 1 por 0" << endl;
        }
    }
    if((j-1) >= 0 && (j-1) < 3) {
        if(v[i][(j-1)] == 0) {
            //cout << "i: " << (i) << " j: " << (j-1) << " cambie 1 por 0" << endl;
            v[i][j-1] = 1;
        }
        else {
            v[i][j-1] = 0;
            //cout << "i: " << (i) << " j: " << (j-1) << " cambie 0 por 1" << endl;
        }
    }
    if((j+1) >= 0 && (j+1) < 3) {
        if(v[i][(j+1)] == 0) {
            v[i][j+1] = 1;
            //cout << "i: " << (i) << " j: " << (j+1) << " cambie 0 por 1" << endl;
        }
        else {
            v[i][j+1] = 0;
            //cout << "i: " << (i) << " j: " << (j+1) << " cambie 1 por 0" << endl;
        }
    }
}

int
main() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            v[i][j] = 1;
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> p[i][j];         
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(p[i][j] % 2 == 1) {
                push(i, j);   
            }
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(j == 2)
                cout << v[i][j] << endl;    
            else 
                cout << v[i][j];   
        }
    }
}
