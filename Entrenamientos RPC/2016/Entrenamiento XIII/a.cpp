#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

string strs[10];
vector <string> nums;
int sz;
ll op[3];

void parse_line(const string &line) {
  int i = 0;
  for (int k = 0; k < sz; ++k) {
    nums[k] += line.substr(i, 5);
    i += 6;
  }
}

int
main() {
  strs[0] = "xxxxxx...xx...xx...xx...xx...xxxxxx";
  strs[1] = "....x....x....x....x....x....x....x";
  strs[2] = "xxxxx....x....xxxxxxx....x....xxxxx";
  strs[3] = "xxxxx....x....xxxxxx....x....xxxxxx";
  strs[4] = "x...xx...xx...xxxxxx....x....x....x";
  strs[5] = "xxxxxx....x....xxxxx....x....xxxxxx";
  strs[6] = "xxxxxx....x....xxxxxx...xx...xxxxxx";
  strs[7] = "xxxxx....x....x....x....x....x....x";
  strs[8] = "xxxxxx...xx...xxxxxxx...xx...xxxxxx";
  strs[9] = "xxxxxx...xx...xxxxxx....x....xxxxxx";
  string line;
  while (getline(cin, line)) {
    nums.clear();
    sz = (line.size() + 1) / 6;
    nums.resize(sz);
    parse_line(line);
    for (int i = 1; i < 7; ++i) {
      getline(cin, line);
      parse_line(line);
    }
    op[0] = op[1] = 0LL;
    bool ind = 0;
    for (int i = 0; i < sz; ++i) {
      bool found = false;
      for (int j = 0; !found && j <= 9; ++j) {
        if (nums[i] == strs[j]) {
          if (op[ind] != 0LL) op[ind] *= 10LL;
          op[ind] += j;
          found = true;
          break;
        }
      }
      if (!found) ind = 1;
    }
    string ans = toStr(op[0] + op[1]);
    for (int i = 0; i < 7; ++i) {
      for (int j = 0; j < ans.size(); ++j) {
        int nu = ans[j] - '0';
        printf("%s", strs[nu].substr((i * 5), 5).c_str());
        if (j != ans.size() - 1) printf(".");
      }
      puts("");
    }
  }
  return 0;
}
