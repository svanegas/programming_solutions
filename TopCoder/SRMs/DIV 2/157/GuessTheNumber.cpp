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

class GuessTheNumber {
    public:
        int noGuesses(int upper, int answer) {
            int cont = 0;
            int low = 1;
            int x = -1;
            while (x != answer) {
                x = (low + upper)/2;
                if (x < answer) low = x + 1;
                if (x > answer) upper = x - 1;
                cont++;
            }
            return cont;
        }  
};

int
main() {

    return 0;
}
