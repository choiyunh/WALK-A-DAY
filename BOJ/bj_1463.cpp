#include <iostream>
#include <algorithm>

int main() {
	int	N;
	int dp[1000001];
	
	std::cin >> N;

	dp[1] = 0;
	
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = std::min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = std::min(dp[i], dp[i / 3] + 1);
	}

	printf("%d\n", dp[N]);
	return 0;
}