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

const int MAXN = 1000005;
int group[MAXN];
int q, z = 1;
string s;

int main(){
    while (cin >> s && s.size() > 0) {
        cout << "Case " << (z++) << ":" << endl;
        char cur = s[0];
        int gr = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != cur) {
                gr++;
                cur = s[i];
            }
            group[i] = gr;
        }
        cin >> q;
        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            if (group[a] == group[b]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
