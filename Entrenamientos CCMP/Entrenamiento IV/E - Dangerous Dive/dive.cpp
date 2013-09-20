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

using namespace std;

int main(){
    int n,r;
    while(cin>>n>>r){
        int a[n];
        memset(a,0,sizeof(a));
        int cont =n-r;
        for(int i=0;i<r;i++){
            int reg;
            cin >> reg;
            a[reg-1]=1;        
        }      
        int cent = 0; 
        int aux = 0;
        if(n==r) cout << "*"  << endl;
        else{       
            for(int i=0;i<n;i++){
                if(a[i]==0){
                    cout<< i+1 << " ";
                    cent = 1;
                    aux++;   
                }
                if(aux >=cont)break;
            }
            cout << endl;
        }
         
    }    
    

return 0;
}
