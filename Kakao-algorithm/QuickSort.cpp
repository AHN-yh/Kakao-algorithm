#include <iostream>

int Partition(int *arr, int start, int end) {
	int left = start + 1;
	int right = end;
	int pivot = arr[start];
	int pivot_idx = start;

	while (left <= right) {
		while (arr[left] <= pivot && left < right) {
			left++;
		}
		while (arr[right] > pivot && left <= right) {
			right--;
		}
		if (left < right) {
			int temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;
		}
		else {
			break;
		}
	}
	int temp = arr[pivot_idx];
	arr[pivot_idx] = arr[right];
	arr[right] = temp;
	pivot_idx = right;

	return pivot_idx;
}

void QuickSort(int *arr, int start, int end) {
	if (start <= end) {
		int mid = Partition(arr, start, end);
		QuickSort(arr, mid + 1, end);
		QuickSort(arr, start, mid - 1);
	}
	else {
		return;
	}
}

int QuickSort_main() {
	int arr[] = { 80,89,93,45,76,55,34,45,65,76,56 };
	int arr_size = sizeof(arr) / 4;

	std::cout << "Before Sorting Algorithm" << std::endl;
	using namespace std;
	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	QuickSort(arr, 0, arr_size-1);
	std::cout << "After Sorting Algorithm" << std::endl;
	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}