#include "algo_1260.h"

int arr1[16];
int arr2[16];
char result[4096];

void dec2bin(int num) {
	for (int i = 0; num > 0; i++) {
		result[i] = num % 2;
		num = num / 2;
	}
}

void drawMap(char *map, int mapSize) {
	for (int i = mapSize - 1; i >= 0; i--) {
		switch (map[i]) {
		case 1:
			cout << "#";
			break;
		case 0:
			cout << " ";
			break;
		default:
			break;
		}
	}
	cout << endl;
}

int kakao_secretMap() {
	int mapSize;
	cout << "Welcome to solving secret map!" << endl;
	cout << "Input size of map:" << endl;
	cout << ">> ";
	cin >> mapSize;

	cout << "Input first password" << endl;
	cout << ">> ";
	for (int i = 0; i < mapSize; i++) {
		cin >> arr1[i];
	}
	cout << "Input second password" << endl;
	cout << ">> ";
	for (int i = 0; i < mapSize; i++) {
		cin >> arr2[i];
	}

	for (int i = 0; i < mapSize; i++) {
		dec2bin(arr1[i] | arr2[i]);
		drawMap(result, mapSize);
	}

	return 0;
}

