#include <iostream>

int d[41] = { 0 };

int fibonacci(int n) {
	if (n == 0) return d[0] = 0;
	if (n == 1) return d[1] = 1;
	if (d[n] != 0) return d[n];

	return d[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int T, N;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> N;
		if (N == 0)
			printf("1 0\n");
		else {
			printf("%d %d\n", fibonacci(N - 1), fibonacci(N));
		}
	}
}