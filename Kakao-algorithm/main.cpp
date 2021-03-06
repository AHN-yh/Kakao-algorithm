#include "algo_1260.h"
#include "algo_common.h"

int main() {
	int menu = 0;
	do {
		std::cout << "=======::Menu::=======" << std::endl;
		std::cout << " 1::  BJ_ALGO_1260" << std::endl;
		std::cout << " 2::  KAKAO_다트" << std::endl;
		std::cout << " 3::  KAKAO_비밀지도" << std::endl;
		std::cout << " 4::  BJ_ALGO_1991" << std::endl;
		std::cout << " 5::  ALGO_Quicksort" << std::endl;
		std::cout << "======================" << std::endl;
		std::cout << "For Exit: [0]" << std::endl;
		
		std::cout << ">> ";
		std::cin >> menu;

		switch (menu) {
		case 1:
			solve_algo();
			break;
		case 2:
			kakao_dart();
			break;
		case 3:
			kakao_secretMap();
			break;
		case 4:
			solve_1991();
			break;
		case 5:
			QuickSort_main();
			break;
		case 6:
			makeOne();
			break;
		default:
			std::cout << "No menu to run" << std::endl;
			break;
		}
		cout << endl;
	} while (menu != 0);
	
	return 0;
}
