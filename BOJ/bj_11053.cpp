#include <iostream>

int main() {
	int n;
	int a[1001] = { 0 };
	int dp[1001] = { 0 };
	int max;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		dp[i] = 1;
	}

	max = dp[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i]) max = dp[i];
	}

	printf("%d\n", max);

	return 0;
}