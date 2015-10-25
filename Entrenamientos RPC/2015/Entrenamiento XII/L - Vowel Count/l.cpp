#include <bits/stdc++.h>

using namespace std;

int
main() {
  int n;
  cin >> n;
  while (n--) {
    string name; cin >> name;
    int vowels = 0;
    for (int i = 0; i < name.size(); ++i) {
      if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' ||
          name[i] == 'o' || name[i] == 'u') vowels++;
    }
    printf("%s\n", name.c_str());
    if (vowels > name.size() - vowels) puts ("1");
    else puts("0");
  }
  return 0;
}
