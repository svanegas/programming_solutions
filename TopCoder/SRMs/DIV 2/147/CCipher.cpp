#include <algorithm>
#include <iostream>
#include <iterator>
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

using namespace std;

class CCipher {
    public:
        string
        decode(string cipherText, int shift) {
            string result = "";
            for (int i = 0; i < cipherText.size(); i++) {
                int ascii = cipherText[i] - shift;
                if (ascii < 'A') {
                    int excede = 'A' - ascii;
                    result += ('['-excede);
                }   
                else {
                    result += cipherText[i]-shift;   
                }
            }
            return result;
        }
};

int
main() {

    return 0;
}
