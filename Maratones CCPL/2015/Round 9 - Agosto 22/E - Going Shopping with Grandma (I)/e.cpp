#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MAXM 1005
#define MAXN 2005
#define ll long long

ll dp[MAXN][MAXN];
ll modulo = 9999959999LL;

int
main() {

  int l, s;

  for(int i = 0; i < MAXN; ++i)
    for(int j = 0; j < MAXM; ++j) dp[i][j] = 0LL;

  for(int i = 0; i < MAXN; ++i){
    dp[0][i] = i+1;
  }

  for(int m = 1; m < MAXM; ++m){
    for(int n = 0; n < MAXN; ++n){
        dp[m][n] = ( dp[m-1][n+1] + 1LL )% modulo;

        if(n > 0) dp[m][n] =  (dp[m][n-1] + dp[m][n] ) % modulo;
    }
  }

  while(cin >> l >> s && (l || s)){

    cout << dp[l][s] % modulo << endl;
  }


  return 0;
}
