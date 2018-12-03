#include "algo_common.h"
#include <string>

using namespace std;

int split[4];
int res[3] = { 0,0,0 };

void splitInput(string one) {
	int cnt = 0;
	for (int i = 0; i < one.size(); i++) {
		if (one[i] >= '0' && one[i] <= '9') {
			if (one[i - 1] == '1') {
				split[cnt] = i - 1;
				cnt++;
				continue;
			}
			split[cnt] = i;
			cnt++;
		}
	}
	split[3] = one.size();
}

void parseInput(string one) {
	int temp;
	for (int trying = 0; trying < 3; trying++) {
		for (int i = split[trying]; i < split[trying + 1]; i++) {
			switch (one[i]) {
			case '0':
				if (one[i - 1] == '1') {
					temp = 10;
					break;
				}
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				//cout << "number" << endl;
				temp = one[i] - '0';
				break;
			case 'S':
				break;
			case 'D':
				temp = temp * temp;
				break;
			case 'T':
				temp = temp * temp * temp;
				break;
			case '*':
				temp = temp * 2;
				if (trying > 0) {
					res[trying - 1] = res[trying - 1] * 2;
				}
				break;
			case '#':
				temp = temp * (-1);
				break;
			default:
				break;
			}
		}
		res[trying] = temp;
	}
}

int kakao_dart() {
	int T;
	cout << "Test case: ";
	cin >> T;
	for (int test = 0; test < T; test++) {
		string one;
		cin >> one;
		splitInput(one);
		for (int i = 0; i < 3; i++) {
			//cout << split[i] << " ";
		}
		//cout << endl;

		parseInput(one);
		int total = 0;
		for (int i = 0; i < 3; i++) {
			//cout << res[i] << " ";
			total += res[i];
		}
		cout << total << endl << endl;
	}
	return 0;
}