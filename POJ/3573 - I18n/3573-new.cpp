//Santiago Vanegas Gil.
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
//only libraries used.

using namespace std;

typedef vector <string> expansions;
map <string, expansions> m;

string
computeAbbreviation(const string &word) {
  stringstream ss;
  char ini = tolower(word[0]);
  char fin = tolower(word[word.size() - 1]);
  ss << ini;
  ss << (word.size() - 2);
  ss << fin;
  return ss.str();
}

string
processWord(const string &word) {
//  printf("Arrived with word %s|\n", word.c_str());
  if (word.size() < 3) return word;
  string abb;
  if (isdigit(word[1])) {
    string abb = word;
    abb[0] = tolower(abb[0]);
    abb[abb.size() - 1] = tolower(abb[abb.size() - 1]);
    string expanded;
    //printf("Checking for key: %s\n", abb.c_str());
    if (m.count(abb)) {
      expansions possExpansions = m[abb];
      if (possExpansions[0] == "-1") {
        //Ambiguous word
        return word;
      }
      if (isupper(word[0])) {
        if (isupper(word[word.size() - 1])) expanded = m[abb][1];
        else expanded = m[abb][0];
      }
      else expanded = m[abb][2];
      return expanded;
    }
    return word;
  }
  abb = computeAbbreviation(word);
  expansions expa(3);
  if (m.count(abb)) {
    expa = m[abb];
    if (expa[0] != word && expa[1] != word && expa[2] != word) {
      //The word stored in map doesn't correspond to word to save, so
      //this abbreviation is ambiguous.
      m[abb][0] = "-1";
      m[abb][1] = "-1";
      m[abb][2] = "-1";
      return word;
    }
  }
  //Word must be stored in the map
  string cap = "", up = "", low = "";
  for (int i = 0; i < word.size(); ++i) {
    if (i == 0) cap += toupper(word[i]);
    else cap += tolower(word[i]);
    up += toupper(word[i]);
    low += tolower(word[i]);
  }
  expa[0] = cap;
  expa[1] = up;
  expa[2] = low;
  m[abb] = expa;
  return word;
}

void
processLine(const string &line) {
  string word = "";
  for (int i = 0; i < line.size(); ++i) {
    if (isalpha(line[i]) || isdigit(line[i])) {
      word += line[i];
    }
    else {
      cout << processWord(word) << line[i];
      word = "";
    }
  }
  if (!word.empty()) cout << processWord(word);
}

int
main() {
  string line;
  while (getline(cin, line)) {
    if (line.empty()) {
      cout << endl;
      m.clear();
      continue;  
    }
    processLine(line);   
    cout << endl;
  }
  return 0;
}
