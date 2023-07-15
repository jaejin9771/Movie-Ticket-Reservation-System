#include "Theater.h"
#include <iostream>
using namespace std;

Theater::Theater() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			seat[i][j] = -1;
		}
	}
}

void Theater::setSeat(int v, int row, int col) {
	seat[row][col] = v;
}

int Theater::getSeat(int row, int col) {
	return seat[row][col];
}

void Theater::printSeat() {
	cout << "================== 스크린 방향 ==================\n";
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (seat[i][j] == -1) cout << "□";
			else cout << "■";
			cout << "\t";
		}
		cout << "\n";
	}
	cout << "=================================================\n";
}
