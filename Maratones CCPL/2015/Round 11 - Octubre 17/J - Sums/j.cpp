#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll longitud;

ll primero(ll x){
  double w = sqrt(1.0*2*x);
  ll a1, n = (int) floor(w) + 1;

  for(int i = 2; i <= n; ++i){
    a1 = (2 * x - i * i + i) / (2 * i);
    if(a1 > 0){
      ll aux = (2 * a1 + i - 1 ) * i / 2;
      if(aux == x){
        longitud  = i;
        return a1;
      }
    }
  }
  longitud = 1;
  return x;
}

int main(){
  int t;
  cin >> t;
  ll x;
  while(t--){
    cin >> x;
    ll first = primero(x);
    if(first == x){
      cout << "IMPOSSIBLE";
    }else{
      cout << x << " = " << first;
      for(int i = 2; i <= longitud; ++i){
        cout << " + " << first + i - 1;
      }
    }
    cout << endl;
  }
  return 0;
}
