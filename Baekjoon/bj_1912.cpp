#include <iostream>

int main() {
	int n;
	int a[100001], dp[100001] = { 0, };
	int max;

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	dp[1] = a[1];
	max = dp[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + a[i];
		if (dp[i] < a[i]) dp[i] = a[i];
		if (dp[i] > max) max = dp[i];
	}

	printf("%d\n", max);
	return 0;
}