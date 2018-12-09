#include <iostream>

using namespace std;
int mem[1000000];

int makeOne() {
	int start;
	cin >> start;
	mem[0] = 0;
	mem[1] = 0;
	mem[2] = 1;
	mem[3] = 1;
	while (1) {
		if (mem[start] == 1) {
			cout << mem[start] << endl;
			break;
		}
		if (start % 3 == 0) {
			mem[start] = mem[start/3] + 1;
			start = start / 3;
		}
		else if (start % 2 == 0) {
			mem[start] = mem[start/2] + 1;
			start = start / 2;
		}
		else {
			mem[start] = mem[start-1] + 1;
			start = start-1;
		}
	}

	return 0;
}