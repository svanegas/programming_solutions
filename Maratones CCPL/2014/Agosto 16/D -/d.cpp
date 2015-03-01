//Just Code It.
using namespace std;
#include<algorithm>
#include<iostream>
#include<iterator>
#include<sstream>
#include<fstream>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str();}
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x "=" << (x) << endl

const double EPS = 1e-9;

int gcd(int a, int b) {
    int ans;
    if (b == 0) ans = a;
    else ans = gcd(b, a % b);
    return abs(ans);
}

int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        vector<int> numbers;
        numbers.push_back(n);
        while(cin>>n){
            if(n==0)break;
            numbers.push_back(n);
        }
        int ans = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            for (int j = i + 1; j < numbers.size(); ++j) {
                ans = gcd(ans, numbers[i] - numbers[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
