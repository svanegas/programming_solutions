# include <algorithm>
# include <iostream>
# include <iterator>
# include <sstream>
# include <fstream>
# include <cassert>
# include <cstdlib>
# include <string>
# include <cstring>
# include <cstdio>
# include <vector>
# include <cmath>
# include <queue>
# include <stack>
# include <map>
# include <set>
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){
    int ab, ac, bd;
    while (cin >> ab>>ac>>bd){
        int num= ab*ac;
        int deno = bd - ac;
        int d = __gcd(num, deno);
        if(ac==0)deno=bd,d=1;
        cout << num/d << "/" << deno/d << endl;
             
    }  
return 0;
}
