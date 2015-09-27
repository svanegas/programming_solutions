#include <iostream>
using namespace std;

int dice[2][4];

double sum(int a, int b) {
	a--;
	int high = (b * (b + 1)) / 2;
	int low = (a * (a + 1)) / 2;
	return ((high - low) * 1.0) / (b - (a + 1) + 1.0);
}

int main() {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> dice[i][j];
		}
	}
	double gunnar = sum(dice[0][0], dice[0][1]);
	gunnar += sum(dice[0][2], dice[0][3]);
	double emma = sum(dice[1][0], dice[1][1]);
	emma += sum(dice[1][2], dice[1][3]);
	if (gunnar > emma) cout << "Gunnar" << endl;
	else if (gunnar < emma) cout << "Emma" << endl;
	else cout << "Tie" << endl;
	return 0;
}