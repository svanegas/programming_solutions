#include <bits/stdc++.h>

using namespace std;

int t;
vector <string> sounds;
map <string, string> m;

int
main() {
	cin >> t; cin.ignore();
	while (t--) {
		m.clear();
		sounds.clear();
		string line;
		getline(cin, line);
		stringstream ss(line);
		string word;
		while (ss >> word) sounds.push_back(word);
		while (getline(cin, line)) {
			if (line == "what does the fox say?") {
				vector <string> printThis;
				for (int i = 0; i < sounds.size(); ++i) {
					//printf("Busco por: %s\n", sounds[i].c_str());
					if (m.count(sounds[i]) == 0) printThis.push_back(sounds[i]);
				}
				cout << printThis[0];
				for (int i = 1; i < printThis.size(); ++i) {
					cout << " " << printThis[i];	
				}
				cout << endl;
				break;
			}
			else {
				string anim, does, sound;
				stringstream ss2(line);
				ss2 >> word >> does >> sound;
				//printf("pongo %s = %s\n", word.c_str(), sound.c_str());
				m[sound] = word;
			}
		}
	}
	return 0;
}
