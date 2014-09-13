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

const long long INF = 1LL << 60;
const int MAXN = 25;
int t, n, m, o;
long long bas[MAXN][MAXN][MAXN];

int
main() {
    cin >> t;
    while (t--) {
        cin >> n >> m >> o;
        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < o; k++) {
                    cin >> bas[i][j][k];
                    //1
                    if (i > 0 && j > 0 && k > 0) {
                        bas[i][j][k] += bas[i-1][j][k];
                        bas[i][j][k] += bas[i][j-1][k];
                        bas[i][j][k] -= bas[i-1][j-1][k];
                        
                        //f(2)
                        bas[i][j][k] += bas[i][j][k-1];
                        bas[i][j][k] -= bas[i-1][j][k-1];
                        bas[i][j][k] -= bas[i][j-1][k-1];
                        bas[i][j][k] += bas[i-1][j-1][k-1];
                    }
                    //2
                    else if (i > 0 && j > 0) {
                        bas[i][j][k] += bas[i-1][j][k];
                        bas[i][j][k] += bas[i][j-1][k];
                        bas[i][j][k] -= bas[i-1][j-1][k];   
                    }
                    //3
                    else if (i > 0 && k > 0) {
                        bas[i][j][k] += bas[i-1][j][k];
                        bas[i][j][k] += bas[i][j][k-1];
                        bas[i][j][k] -= bas[i-1][j][k-1];   
                    }
                    //4
                    else if (j > 0 && k > 0) {
                        bas[i][j][k] += bas[i][j-1][k];
                        bas[i][j][k] += bas[i][j][k-1];
                        bas[i][j][k] -= bas[i][j-1][k-1];   
                    }
                    else if (i > 0) bas[i][j][k] += bas[i-1][j][k]; 
                    else if (j > 0) bas[i][j][k] += bas[i][j-1][k];
                    else if (k > 0) bas[i][j][k] += bas[i][j][k-1];   
                }
            } 
        }
        long long maxi = -1 * INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < o; k++) {
                    for (int a = i; a < n; a++) {
                        for (int b = j; b < m; b++) {
                            for (int c = k; c < o; c++) {
                                long long sub = bas[a][b][c];
                                //1
                                if (i > 0 && j > 0 && k > 0) {
                                    sub -= bas[i-1][b][c];
                                    sub -= bas[a][j-1][c];
                                    sub += bas[i-1][j-1][c];
                                    
                                    //f(2)
                                    sub -= bas[a][b][k-1];
                                    sub += bas[i-1][b][k-1];
                                    sub += bas[a][j-1][k-1];
                                    sub -= bas[i-1][j-1][k-1];
                                }
                                //2
                                else if (i > 0 && j > 0) {
                                    sub -= bas[i-1][b][c];
                                    sub -= bas[a][j-1][c];
                                    sub += bas[i-1][j-1][c];   
                                }
                                //3
                                else if (i > 0 && k > 0) {
                                    sub -= bas[i-1][b][c];
                                    sub -= bas[a][b][k-1];
                                    sub += bas[i-1][b][k-1];   
                                }
                                //4
                                else if (j > 0 && k > 0) {
                                    sub -= bas[a][j-1][c];
                                    sub -= bas[a][b][k-1];
                                    sub += bas[a][j-1][k-1];   
                                }
                                else if (i > 0) sub -= bas[i-1][b][c]; 
                                else if (j > 0) sub -= bas[a][j-1][c];
                                else if (k > 0) sub -= bas[a][b][k-1];
                                maxi = max(sub, maxi);
                            }   
                        }   
                    }
                }
            }   
        }
        cout << maxi << endl;
        if (t) cout << endl;
    }
	return 0;
}
