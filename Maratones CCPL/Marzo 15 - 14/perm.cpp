using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
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

//157.253.238.31/boca/ team501

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) //cout << #x " = " << (x) << endl;

const int MAXN = 22;
typedef unsigned long long ull;
ull arr[MAXN];
ull c;
string s, res;
ull n;

int
main() {
    arr[0] = arr[1] = arr[2] = 0;
    arr[3] = 2;
    int j = 3;
    for (int i = 4; i < MAXN; i++) {
        arr[i] = arr[i-1] * j;
        j++;
    }
    cin >> c;
    while (c--) {
        cin >> s >> n;
        res = "";
        n++;
        sort(s.begin(), s.end());
        int tama = s.size();
        if(tama > 2){
        
            while (true) {
                D(n);
                if (n == 0) {
                      reverse(s.begin(), s.end());
                      res += s;
                      break;
                }
                D(arr[tama]);
                double div = ((double) n) / ((double) arr[tama]);
                D(div);
                n = n % arr[tama];
    
                int digit;
                digit = (int) ceil(div);
                res += s[digit-1];
                s.erase(digit-1, 1);
                tama--;
                D(tama);
                if (tama == 2) break;
            }
            if (tama == 2){
                if (n == 1) {
                    res += s[0];
                    res += s[1];
                }
                else {
                    res += s[1];
                    res += s[0];
                }
            }
        }else{
           if(tama == 2){
              if(n == 1) res = s;
              else{
                    res += s[1];
                    res += s[0];
              }     
           } else res = s;     
        }
        cout << res << endl;
    }
    return 0;
}
