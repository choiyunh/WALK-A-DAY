#include <iostream>

int d[1000001] = { 0 };

int dp(int N) {
	if (N == 1) return 1;
	if (N == 2) return 2;
	if (d[N] != 0) return d[N];
	return d[N] = (dp(N - 1) + dp(N - 2)) % 15746;
	
}

int main() {
	int N;
	std::cin >> N;

	printf("%d\n", dp(N));
}
