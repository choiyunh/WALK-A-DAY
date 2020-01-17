#include <iostream>
#include <algorithm>

//quick sort

int arr[1000000];

void quick_sort(int i, int j) {
	if (i >= j) return;
	int pivot = arr[(i+j) / 2];
	int left = i;
	int right = j;

	while (left <= right) {
		while (arr[left] < pivot)left++;
		while (arr[right] > pivot) right--;
		if (left <= right) {
			std::swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
}

int main() {
	int n;

	std::cin >> n;

	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	quick_sort(0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	return 0;
}
