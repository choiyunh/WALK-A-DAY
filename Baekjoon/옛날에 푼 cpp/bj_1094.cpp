#include <iostream>

int main() {
	int X, num = 1;
	int stick = 64, sum = 64;

	std:: cin >> X;

	while (sum != X) {
		stick /= 2;
		num++;

		if (sum - stick >= X) {
			sum -= stick;
			num--;
		}
	}
	std::cout << num << std::endl;
	
}
