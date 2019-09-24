#include <iostream>

int main() {
	int dp[101] = { 0 };
	int N;

	std::cin >> N;
	
	dp[1] = 9;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] * 2 - 1;
	}

	printf("%d\n", dp[N]);

	
	return 0;
}
