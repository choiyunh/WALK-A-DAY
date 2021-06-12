#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int N;
	int dp[10001];
	int p[10001];
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> p[i];
	}
	
	dp[0] = 0;
	dp[1] = p[1];
	dp[2] = p[1] + p[2];

	for (int i = 3; i <= N; i++) {
		dp[i] = std::max(dp[i - 2] + p[i], dp[i - 3] + p[i - 1] + p[i]);
		dp[i] = std::max(dp[i], dp[i - 1]);
	}

	printf("%d\n", dp[N]);

	return 0;
}