#include <iostream>

long long d[100] = { 0 };

long long dp(int N) {
	if (N == 1) return 1;
	if (N == 2) return 1;
	if (N == 3) return 1;
	if (d[N - 1] != 0) return d[N - 1];
	
	return d[N - 1] = dp(N - 3) + dp(N - 2);
}
int main() {
	int T, N;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> N;
		printf("%lld\n", dp(N));
	}

	return 0;
}