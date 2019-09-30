#include <iostream>

int main() {
	int a[1001], dp[1001];
	int n, max;

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		dp[i] = 1;
	}

	max = dp[1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < i && a[j] < a[i]) {
				if (j == 1 || a[j] > a[j - 1])
					dp[i]++;
			}
			if (j > i && a[j] < a[i])
				if (j == 1 || a[j] < a[j - 1])
					dp[i]++;
		}
		if (dp[i] > max) max = dp[i];
	}

	printf("%d\n", max);
	return 0;
}