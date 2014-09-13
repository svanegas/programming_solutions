//Santiago Vanegas Gil.
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
#include <bitset>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int n;
set <string> learned;
map <string, bool> knows;

bool
isValidWord(string word) {
  return word != "." && word != "," && word != ":"
      && word != ";" && word != "?" && word != "!";
}

string
convert(string s) {
  string ret = "";
  for (int i = 0; i < s.size(); i++) ret += tolower(s[i]);
  return ret;  
}

bool
isLearned(string sentence) {
  return learned.find(sentence) != learned.end();
}

int
main() {
  int z = 1;
  while (cin >> n) {
    if (z != 1) cout << endl;
    printf("Learning case %d\n", z++);
    learned.clear();
    knows.clear();
    knows["joe"] = true;
    string word;
    vector <string> lSentence;
    while (cin >> word) {
      if (!isValidWord(word) || word == "*") {
        for (int i = 0; i < lSentence.size(); i++) {
          string toLearn = lSentence[i];
          learned.insert(toLearn);
          for (int j = i + 1; j < min(i + n, (int) lSentence.size()); j++) {
            toLearn += (" " + lSentence[j]);
            learned.insert(toLearn);
          }   
        }
        lSentence.clear();
        if (word == "*") break;
        continue; 
      }
      string conv = convert(word);
      lSentence.push_back(conv);
      knows[conv] = true;
      learned.insert(conv);
    }
    lSentence.clear();
    vector <string> dontKnow;
    string globalStnc = "";
    while (cin >> word) {
      if (!isValidWord(word) || word == "#") {
        for (int i = 0; i < dontKnow.size(); i++) {
          printf("What does the word \"%s\" mean?\n", dontKnow[i].c_str()); 
        }
        dontKnow.clear();
        bool ask = false;
        for (int i = 0; i < lSentence.size(); i++) {
          string stnc = lSentence[i];
          if (!isLearned(stnc)) ask = true;
          learned.insert(stnc); 
          for (int j = i + 1; j < min(i + n, (int) lSentence.size()); j++) {
            stnc += (" " + lSentence[j]);
            if (!isLearned(stnc)) ask = true;
            learned.insert(stnc);
          }
        }
        lSentence.clear();
        if (ask) {
          globalStnc.erase(globalStnc.begin());
          printf("What does the sentence \"%s\" mean?\n", globalStnc.c_str()); 
        }
        globalStnc = "";
        if (word == "#") break;
        continue;  
      }
      globalStnc += (" " + word);
      string conv = convert(word);
      learned.insert(conv);
      if (!knows[conv]) {
        dontKnow.push_back(word);
        knows[conv] = true;
      }
      lSentence.push_back(conv);
    }
  }
  return 0;
}
