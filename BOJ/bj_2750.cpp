#include <iostream>

int main(){
	int n;
	int a[1000];
	int min;

	std::cin >> n;

	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) min = j;
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}

	for (int i = 0; i < n; i++) printf("%d\n", a[i]);


	return 0;
}