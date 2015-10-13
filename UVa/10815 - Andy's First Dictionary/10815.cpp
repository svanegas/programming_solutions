// Santiago Vanegas Gil
#include <bits/stdc++.h>

using namespace std;

int
main() {
  set <string> words;
  char c;
  string word = "";
  while ((c = getchar()) != EOF) {
    if (isalpha(c)) word += tolower(c);
    else {
      if (word != "") words.insert(word);
      word = "";
    }
  }
  if (word != "") words.insert(word);
  set <string> :: iterator it;
  for (it = words.begin(); it != words.end(); ++it) printf("%s\n", (*it).c_str());
  return 0;
}
