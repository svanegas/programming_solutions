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
# define MAXN 30

using namespace std;

char latin[MAXN];
priority_queue< pair<int, char> >aux;

string find(string x){
    map <char, int> max;
    
    for(int i=0; i<x.size(); i++){
        max[x[i]] += 1;    
    }
    
    for (map<char,int>::iterator it=max.begin(); it!=max.end(); ++it){    
        aux.push(make_pair(it->second, it->first));    
    }
       
    int cont =0;
    bool know[x.size()];
    memset(know, false, sizeof(know));
    while(!aux.empty()){
        pair <int, char> auxpair = aux.top();
        for(int i=0;i<x.size();i++){
            if((x[i]==auxpair.second)&&(know[i]==false)){
                x[i]=latin[cont];
                know[i]=true; 
            }
        }
        cont++;
        aux.pop();   
    }
    cout << x << endl;
    return x;
}

int main(){
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++){
        int n, m;
        cin >> n >> m;
        for(int j=0; j<n; j++)cin >> latin[j];
        string line;
        cin >> line;
        find(line);    
    }

return 0;
}
