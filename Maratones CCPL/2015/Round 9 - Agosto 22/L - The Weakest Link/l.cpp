#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 100010
//char T[MAX_N];
string T;
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
 
void countingSort(int k) {
  int i, sum, maxi = max(300, n);
  memset(c, 0, sizeof c);
  for (i = 0; i < n; ++i)
    c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; ++i) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for (i = 0; i < n; ++i)
    tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
  for (i = 0; i < n; ++i)
    SA[i] = tempSA[i];
}
 
void
constructSA() {
  int i, k, r;
  for (i = 0; i < n; ++i) RA[i] = T[i];
  for (i = 0; i < n; ++i) SA[i] = i;
  for (k = 1; k < n; k <<= 1) {
    countingSort(k);
    countingSort(0);
    tempRA[SA[0]] = r = 0;
    for (i = 1; i < n; ++i)
      tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; ++i)
      RA[i] = tempRA[i];
    if (RA[SA[n-1]] == n-1) break;
  }
}
 
int
main() {
  int tests;
  cin >> tests;
  cin.ignore();
  while (tests--) {
    getline(cin, T);
    T += T;
    n = T.size() + 1;
    T += (char) ('z' + 1); // BE FUCKING CAREFUL WHITH THIS CHARACTER, ensuere that has a greater
                           // value of all possible letters or the lowest i won't work.
                           // try case 'aa' expected output 1 since it's the lowest value.
    constructSA();
    // for (int i = 0; i < n; ++i) printf("%2d\t%s\n", SA[i], T.begin() + SA[i]);
    for (int i = 0; i < n; ++i) {
      if (SA[i] < (n - 1) / 2) {
        printf("%d\n", SA[i] + 1);
        break;
      }
    }
  }
  return 0;
}
