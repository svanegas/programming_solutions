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

class Time {
	public: string whatTime(int seconds) {
		int horas = seconds/3600;
		int minutos = (seconds - (horas*3600))/60;
		int segundos = ((seconds - horas*3600)-minutos*60);
		stringstream ss, ss1, ss2;
		ss << horas;
		ss1 << minutos;
		ss2 << segundos;
		string ret = ss.str() + ":" + ss1.str() + ":" + ss2.str();
		return ret;
	}
};
